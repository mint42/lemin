/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:18:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/30 00:16:26 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

t_bfs		*init_bfs()
{
	t_bfs	*bfs;

	bfs = (t_bfs *)ft_memalloc(sizeof(t_bfs));
	bfs->prev = 0;
	bfs->next = 0;
	bfs->start_or_end_path = 0;
	bfs->base_path = 0;
	bfs->path_id_array_index = 0;
	bfs->path_id_bit_index = 0;
	bfs->paths_to_avoid = 0;
	bfs->npaths_to_avoid = 0;
	bfs->mpaths_to_avoid = 0;
	bfs->room_id = 0;
	bfs->depth_level = 0;

	return (bfs);
}

int			new_bfs_node(t_bfs *cur, t_bfs *tail)
{
	(void)cur;
	(void)tail;
	return (0);
}

void		delete_bfs(t_bfs **bfs)
{
	t_bfs	*cur;

	cur = *bfs;
	while (bfs)
	{
		cur = bfs;
		bfs = bfs->next;
		ft_memdel(&(cur->prev));
		ft_memdel(&(cur->next));
		ft_memdel(&(cur->paths_to_avoid));
		ft_memdel(&(cur->paths_to_avoid));
		ft_memdel(&(cur));
	}
}
