/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:26:45 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 12:10:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "binarytree_rooms.h"
#include "struct_room.h"
#include "struct_farm.h"
#include "ft_mem.h"
#include "ft_str.h"
#include "ft_binarytree.h"
#include "ft_printf.h"
#include <stddef.h>

static void		fill_rooms(struct s_farm *farm,
						struct s_binarytree *bintree_rooms, size_t *room_id)
{
	if (bintree_rooms)
	{
		if (bintree_rooms->left)
			fill_rooms(farm, bintree_rooms->left, room_id);
		(farm->rooms)[*room_id] = BINROOM(bintree_rooms);
		if (BINROOM(bintree_rooms)->start_end & START_ROOM)
			farm->start_rid = *room_id;
		if (BINROOM(bintree_rooms)->start_end & END_ROOM)
			farm->end_rid = *room_id;
		++(*room_id);
		if (bintree_rooms->right)
			fill_rooms(farm, bintree_rooms->right, room_id);
	}
}

int				setup_rooms(struct s_binarytree *bintree_rooms,
						struct s_farm *farm)
{
	size_t	room_id;

	farm->rooms = (struct s_room **)ft_memalloc(sizeof(struct s_room *) *
			farm->nrooms);
	if (!(farm->rooms))
		return (print_error(E_ALLOC));
	room_id = 0;
	fill_rooms(farm, bintree_rooms, &room_id);
	return (SUCCESS);
}

void			delete_rooms(struct s_room ***rooms, size_t nrooms)
{
	size_t		i;

	i = 0;
	while(i < nrooms)
	{
		ft_strdel(&((*rooms)[i]->name));
		ft_memdel((void **)&((*rooms)[i]->pids_met));
		++i;
	}
	ft_memdel((void **)rooms);
}
