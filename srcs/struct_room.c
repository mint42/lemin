/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:42:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/05 11:40:09 by rreedy           ###   ########.fr       */
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
	room->start_end = 0;
	room->nlinks = 0;
	room->mlinks = 0;
	room->links = 0;
	room->npaths_encountered = 0;
	room->mpaths_encountered = 0;
	room->paths_encountered = 0;
	return (room);
}

int			insert_room_by_name(t_binarytree **rooms, t_binarytree *room)
{
	int		compare;

	if (!rooms || !*rooms)
		*rooms = room;
	else
	{
		compare = ft_strcmp(ROOM(*rooms)->name, ROOM(room)->name);
		if (compare == 0)
			return (print_error(E_ROOM_DUPLICATE));
		else if (compare > 0)
			insert_room_by_name(&(*rooms)->right, room);
		else
			insert_room_by_name(&(*rooms)->left, room);
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
		if (ROOM(*rooms)->x > room->x ||
				(ROOM(*rooms)->x == room->x && ROOM(*rooms)->y > room->y))
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
