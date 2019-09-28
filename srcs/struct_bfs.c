/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:18:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/28 02:09:06 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "ft_mem.h"

t_bfs	*init_bfs(void)
{
	t_bfs	*bfs;

	bfs = (t_bfs *)ft_memalloc(sizeof(t_bfs));
	if (!bfs)
		return (print_error(E_ALLOC_ERROR));
	bfs->prev = 0;
	bfs->next = 0;
	bfs->base_path_info = 0;
	bfs->path_id_index = 0;
	bfs->path_id_bit = 0;
	bfs->room_id = 0;
	bfs->depth_level = 0;
	return (bfs);
}

int		setup_bfs(t_solve *solve, t_farm *farm)
{
	if (init_bfs(solve->bfs) == ERROR)
		return (ERROR);
	(solve->bfs)->start_or_end_path = 1;
	(solve->bfs)->path_id_index = 0;
	(solve->bfs)->path_id_bit = 1;
	(solve->bfs)->room_id = farm->start_room_id;
	(solve->bfs)->next = init_bfs();
	(solve->bfs)->next->prev = bfs;
	(solve->bfs)->next->next = 0;
	(solve->bfs)->next->start_or_end_path = 1;
	(solve->bfs)->next->path_id_bit = 2;
	(solve->bfs)->next->room_id = farm->end_room_id;
	return (0);
}

static int		inherit_encounters(t_bfs *new_node, t_room *room)
{
	size_t	i;

	if (new_node->path_info->s_pids_dni < room->max_pid_encountered)
		if (realloc_pids_array(&(new_node->path_info->pids_dni), &(new_node->path_info->s_pids_dni), room->max_pid_encountered) == ERROR)
			return (ERROR);
	i = 0;
	while (i < room->max_pid_encountered)
	{
		new_node->path_info->pids_dni[i] = new_node->path_info->pids_dni[i] | room->pids_encountered[i];
		++i;
	}
}

int		setup_bfs_node(t_bfs **new_node, t_solve *solve, t_farm *farm, size_t i)
{
	if (init_bfs(new_node) == ERROR)
		return (ERROR);
	(*new_node)->rid = ((farm->graph)[solve->bfs_cur->rid])->links[i];
	inherit_encounters((*new_node), (farm->graph)[(*new_node)->rid]);
	if (i > 0)
	{
		create_new_path(&((*new_node)->pathinfo), solve, farm);
		add_pid(solve->basepaths[(*new_node)->path_info->basepid]->pids_in_base, solve->basepaths[(*new_node)->path_info->base_pid]->spids_in_base, (*new_node)->path_info->pid_index, (*new_node)->pathinfo->pid_bit);
		if (solve->basepaths[solve->bfs_cur->path_info->base_pid]->origin == START)
			add_pid(solve->startpaths, solve->sstartpaths, (*new_node)->path_info->pid_index, (*new_node)->pathinfo->pid_bit)
	}
	else
		(*new_node)->path_info = solve->bfs_cur->path_info;
	add_pid((farm->graph)[(*new_node)->rid]->pids_encountered, (farm->graph)[(*new_node)->rid]->s_pids_encountered, (*new_node)->path_info->pid_index, (*new_node)->path_info->pid_bit);
	return (0);
}

void	delete_bfs_node(t_bfs **bfs_node)
{
	if (bfs_node && *bfs_node)
	{
		ft_memdel((void **)&((*bfs_node)->prev));
		ft_memdel((void **)&((*bfs_node)->next));
		ft_memdel((void **)&((*bfs_node)->path_prev));
		ft_memdel((void **)&((*bfs_node)->path_next));
		delete_path_info(bfs_node->path_info);
		ft_memdel((void **)bfs_node);
	}
}

void	delete_bfs_path(t_bfs **bfs)
{
	t_bfs	**cur;
	t_bfs	**to_delete;

	cur = bfs;
	while ((*cur)->path_prev)
	{
		to_delete = cur;
		cur = (*cur)->path_prev;
		delete_bfs_node(to_delete);
	}
	cur = bfs;
	while ((*cur)->path_next)
	{
		to_delete = cur;
		cur = (*cur)->path_next;
		delete_bfs_node(to_delete);
	}
	delete_bfs_node(bfs);
}
