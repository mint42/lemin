/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:18:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 02:51:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bfs_node.h"
#include "ft_mem.h"

int				init_bfs_node(struct s_bfs_node **bfs)
{
	*bfs = (struct s_bfs_node *)fstruct s_memalloc(sizeof(struct s_bfs_node));
	if (!(*bfs))
		return (print_error(E_ALLOC_ERROR));
	(*bfs)->prev = 0;
	(*bfs)->next = 0;
	(*bfs)->path_prev = 0;
	(*bfs)->path_next = 0;
	(*bfs)->path_info = 0;
	(*bfs)->rid = 0;
	return (SUCCESS);
}

int				setup_bfs_node(struct s_bfs_node **new_node, struct s_solve *solve,
				struct s_farm *farm, size_t link_id)
{
	if (init_bfs_node(new_node) == ERROR)
		return (ERROR);
	(*new_node)->rid = ((farm->graph)[solve->bfs_cur->rid])->links[link_id];
	forward_pathids(&(new_node->path_info->pids_dni->pids),
			&(new_node->path_info->pids_dni->pids), room->pids_encountered->pids,
			room->pids_encountered->size)
	if (i > 0)
	{
		setup_pathinfo(&((*new_node)->pathinfo), solve, farm);
		add_pid(solve->basepaths[(*new_node)->path_info->basepid]->pids_in_base,
				solve->basepaths[(*new_node)->path_info->base_pid]->spids_in_base,
				(*new_node)->path_info->pid_index, (*new_node)->pathinfo->pid_bit);
		if (solve->basepaths[solve->bfs_cur->path_info->base_pid]->source == START_ROOM)
			add_pid(solve->startpaths, solve->start_pids_size,
					(*new_node)->path_info->pid_index, (*new_node)->pathinfo->pid_bit)
	}
	else
		(*new_node)->path_info = solve->bfs_cur->path_info;
	add_pid((farm->graph)[(*new_node)->rid]->pids_encountered,
			(farm->graph)[(*new_node)->rid]->s_pids_encountered,
			(*new_node)->path_info->pid_index, (*new_node)->path_info->pid_bit);
	return (0);
}

void			delete_bfs_node(struct s_bfs_node **bfs_node)
{
	if (bfs_node && *bfs_node)
	{
		ft_memdel((void **)&((*bfs_node)->prev));
		ft_memdel((void **)&((*bfs_node)->next));
		ft_memdel((void **)&((*bfs_node)->path_prev));
		ft_memdel((void **)&((*bfs_node)->path_next));
		delete_path_info(&((*bfs_node)->path_info));
		ft_memdel((void **)bfs_node);
	}
}
