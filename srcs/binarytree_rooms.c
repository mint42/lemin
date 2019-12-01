/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rearrange_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:19:38 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 14:41:47 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "binarytree_rooms.h"
#include "struct_room.h"
#include "ft_binarytree.h"
#include "ft_str.h"

static int 	rearrange(struct s_binarytree **rooms_by_coordinate, struct s_binarytree **rooms_by_name)
{
	if (!rooms_by_coordinate)
		return (0);
	if ((*rooms_by_coordinate)->left)
		rearrange(&(*rooms_by_coordinate)->left, rooms_by_name);
	if ((*rooms_by_coordinate)->right)
		rearrange(&(*rooms_by_coordinate)->right, rooms_by_name);
	if (!rooms_by_name || !*rooms_by_name)
		*rooms_by_name = *rooms_by_coordinate;
	else if (insert_room_by_name(rooms_by_name, *rooms_by_coordinate) == ERROR)
		return (ERROR);
	return (0);
}

int 		rearrange_rooms_by_name(struct s_binarytree **rooms_by_coordinate)
{
	struct s_binarytree	*rooms_by_name;

	rooms_by_name = 0;
	if (rearrange(rooms_by_coordinate, &rooms_by_name) == ERROR)
		return (ERROR);
	*rooms_by_coordinate = rooms_by_name;
	return (0);
}

int			insert_room_by_name(struct s_binarytree **rooms,
					struct s_binarytree *room)
{
	int		cmp;

	if (!rooms || !*rooms)
	{
		room->left = 0;
		room->right = 0;
		*rooms = room;
	}
	else
	{
		cmp = ft_strncmp(BINROOM(*rooms)->name, BINROOM(room)->name, BINROOM(room)->len + 1);
		if (cmp == 0)
			return (print_error(E_ROOM_DUPLICATE));
		else if (cmp > 0)
			insert_room_by_name(&(*rooms)->left, room);
		else
			insert_room_by_name(&(*rooms)->right, room);
	}
	return (0);
}

int			insert_room_by_coordinates(struct s_binarytree **rooms,
					struct s_room *room)
{
	if (!room)
		return (0);
	if (!rooms || !*rooms)
		*rooms = ft_treeinit(room, 0);
	else
	{
		if (BINROOM(*rooms)->x == room->x && BINROOM(*rooms)->y == room->y)
			return (print_error(E_COORDINATE_DUPLICATE));
		if (BINROOM(*rooms)->x < room->x ||
				(BINROOM(*rooms)->x == room->x && BINROOM(*rooms)->y < room->y))
			insert_room_by_coordinates(&(*rooms)->right, room);
		else
			insert_room_by_coordinates(&(*rooms)->left, room);
	}
	return (0);
}
