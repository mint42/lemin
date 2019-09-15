/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:18:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/15 05:33:39 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "ft_mem.h"

static void		init_base_path_info(t_bfs *bfs)
{
	bfs->start_or_end = 0;
	bfs->base_path_id = 0;
	bfs->paths_in_base = 0;
	bfs->npaths_in_base = 0;
	bfs->mpaths_in_base = 0;
}

t_bfs			*init_bfs(void)
{
	t_bfs	*bfs;

	bfs = (t_bfs *)ft_memalloc(sizeof(t_bfs));
	if (!bfs)
		return (0);
	bfs->prev = 0;
	bfs->next = 0;
	bfs->base_path_info = 0;
	bfs->path_id_index = 0;
	bfs->path_id_bit = 0;
	bfs->depth_level = 0;
	bfs->room_id = 0;
	return (bfs);
}

int				new_bfs_node(t_farm *solve, t_bfs *cur, t_bfs **tail, t_farm *farm)
{
	t_bfs	*new_node;

	new_node = (t_bfs *)ft_memalloc(sizeof(t_bfs));
	if (!new_node)
		return (print_error(E_ALLOC_ERROR));
	if (cur->base_path_info->base_path_id == 0)
	{
		++solve->nbase_paths;
		cur->start_or_end = (cur->room_id == farm->start_room_id) ? 1 : 2;
		cur->base_path_info->base_path_id = solve->nbase_paths;
		if (new_node->path_id_bit & 0x100000000000000)
		{
			update the numbas;
			new_node->path_id_bit = 1;
			++(new_node->path_id_index);
		}
		else
			new_node->path_id_index = cur->path_id_index << 1;
		if (dont need to add more numbah pt2)
			cur->base_path_info->paths_in_base[new_node->path_id_index] = cur->base_path_info->paths_in_base | new_node->path_id_bit;
		else
		{
			update the numbas;
			++(cur->base_path_info->npaths_in_base);
			cur->base_path_info->mpaths_in_base *= 2;
		}
	}
	else
	{
		new_node->base_path_info = cur->base_path_info;
	}
	new_node->prev = cur;
	(*tail)->next = new_node;
	(*tail) = tail->next;


	inital allocate the mpaths_in_base variable based on how many paths are at the start or end node
	return (0);
}

void		delete_bfs(t_bfs **bfs)
{
	t_bfs	**cur;

	while (bfs)
	{
		cur = bfs;
		bfs = &(*bfs)->next;
		ft_memdel((void **)&((*cur)->prev));
		ft_memdel((void **)&((*cur)->next));
		ft_memdel((void **)&((*cur)->paths_to_avoid));
		ft_memdel((void **)&((*cur)->paths_to_avoid));
		ft_memdel((void **)cur);
	}
}
