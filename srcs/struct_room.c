/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:42:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 02:51:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_farm.h"
#include "struct_room.h"
#include "ft_mem.h"
#include "ft_str.h"
#include "ft_binarytree.h"

void	init_room(struct s_room *room)
{
	room->name = 0;
	room->len = 0;
	room->start_end = 0;
	room->nlinks = 0;
	room->mlinks = 0;
	room->links = 0;
	room->npaths_encountered = 0;
	room->mpaths_encountered = 0;
	room->paths_encountered = 0;
}

int			insert_room_by_name(struct s_binarytree **rooms, struct s_binarytree *room)
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
			return (print_error(E_ROOM_DUPLICATE));
		else if (cmp > 0)
			insert_by_name(&(*rooms)->left, room);
		else
			insert_room_by_name(&(*rooms)->right, room);
	}
	return (0);
}

int			insert_room_by_coordinates(struct s_binarytree **rooms, struct s_room *room)
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
		if (((struct s_room *)(content))->name)
			ft_strdel(&((struct s_room *)(content))->name);
		if (((struct s_room *)(content))->links)
			ft_memdel((void **)&((struct s_room *)(content))->links);
	}
}
