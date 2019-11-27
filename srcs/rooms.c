/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:44:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 02:51:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_room.h"
#include "struct_farm.h"
#include "ft_mem.h"
#include "ft_binarytree.h"
#include "ft_printf.h"
#include <stddef.h>

static void		fill_rooms(struct s_farm *farm,
						struct s_binarytree *bintree_rooms, size_t *room_id)
{
	if (rooms)
	{
		if (rooms->left)
			fill_graph(farm, bintree_rooms->left, room_id);
		(farm->graph)[*room_id] = BINROOM(bintree_rooms);
		if (BINROOM(bintree_rooms)->start_end & START_ROOM)
			farm->start_room_id = *room_id;
		if (BINROOM(bintree_rooms)->start_end & END_ROOM)
			farm->end_room_id = *room_id;
		++(*room_id);
		if (bintree_rooms->right)
			fill_graph(farm, bintree_rooms->right, room_id);
	}
}

int				setup_rooms(struct s_binarytree *bintree_rooms,
						struct s_farm *farm)
{
	size_t	room_id;

	farm->graph = (struct s_room *)ft_memalloc(sizeof(struct s_room) *
			farm->nrooms);
	if (!(farm->graph))
		return (print_error(E_ALLOC));
	room_id = 0;
	fill_graph(farm, bintree_rooms, &room_id);
	return (SUCCESS);
}

void			delete_rooms(struct s_room ***rooms, size_t nrooms)
{
	size_t		i;

	i = 0;
	while(i < nrooms)
	{
		ft_strdel((*rooms)[i]->name);
		ft_memdel((*rooms)[i]->pids_met);
		++i;
	}
	ft_memdel(rooms);
}
