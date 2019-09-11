/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:42:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/10 17:39:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "farm.h"
#include "room.h"
#include "ft_mem.h"
#include "ft_str.h"
#include "ft_binarytree.h"

t_room		*init_room(void)
{
	t_room	*room;

	room = ft_memalloc(sizeof(t_room));
	if (!room)
		return (0);
	room->name = 0;
	room->len = 0;
	room->start_end = 0;
	room->nlinks = 0;
	room->mlinks = 0;
	room->links = 0;
	room->npaths_encountered = 0;
	room->mpaths_encountered = 0;
	room->paths_encountered = 0;
	return (room);
}

#include "ft_printf.h"
int			insert_room_by_name(t_binarytree **rooms, t_binarytree *room)
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
		cmp = ft_strncmp(ROOM(*rooms)->name, ROOM(room)->name, ROOM(room)->len + 1);
		if (cmp == 0)
		{
			ft_printf("room1: %s\nroom2: %s\n", ROOM(room)->name, ROOM(*rooms)->name);
			return (print_error(E_ROOM_DUPLICATE));
		}
		else if (cmp > 0)
			insert_room_by_name(&(*rooms)->left, room);
		else
			insert_room_by_name(&(*rooms)->right, room);
	}
	return (0);
}

int			insert_room_by_coordinates(t_binarytree **rooms, t_room *room)
{
	if (!room)
		return (0);
	if (!rooms || !*rooms)
		*rooms = ft_treeinit(room, 0);
	else
	{
		if (ROOM(*rooms)->x == room->x && ROOM(*rooms)->y == room->y)
			return (print_error(E_COORDINATE_DUPLICATE));
		if (ROOM(*rooms)->x < room->x ||
				(ROOM(*rooms)->x == room->x && ROOM(*rooms)->y < room->y))
			insert_room_by_coordinates(&(*rooms)->right, room);
		else
			insert_room_by_coordinates(&(*rooms)->left, room);
	}
	return (0);
}

void		delete_room(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
	{
		if (((t_room *)(content))->name)
			ft_strdel(&((t_room *)(content))->name);
		if (((t_room *)(content))->links)
			ft_memdel((void **)&((t_room *)(content))->links);
		ft_memdel((void **)&content);
	}
}
