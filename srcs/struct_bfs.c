/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:18:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/01 01:50:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "ft_mem.h"

t_bfs		*init_bfs(void)
{
	t_bfs	*bfs;

	bfs = (t_bfs *)ft_memalloc(sizeof(t_bfs));
	if (!bfs)
		return (0);
	bfs->prev = 0;
	bfs->next = 0;
	bfs->start_or_end_path = 0;
	bfs->base_path = 0;
	bfs->path_id_index = 0;
	bfs->path_id_bit = 0;
	bfs->paths_to_avoid = 0;
	bfs->npaths_to_avoid = 0;
	bfs->mpaths_to_avoid = 0;
	bfs->room_id = 0;
	bfs->depth_level = 0;
	return (bfs);
}

int			new_bfs_node(t_bfs *cur, t_bfs *tail, t_farm *farm)
{
	(void)cur;
	(void)tail;
	(void)farm;
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
