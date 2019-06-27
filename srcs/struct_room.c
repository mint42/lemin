/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:42:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/26 17:08:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"
#include "room.h"
#include "ft_mem.h"
#include "ft_str.h"
#include "ft_binarytree.h"

t_room	*init_room(void)
{
	t_room	*room;

	room = ft_memalloc(sizeof(t_room));
	if (!room)
		return (0);
	room->name = 0;
	room->x = 0;
	room->y = 0;
	room->start_or_end = 0;
	room->nlinks = 0;
	room->mlinks = 0;
	room->links = 0;
	room->npaths = 0;
	room->mpaths = 0;
	room->paths = 0;
	return (room);
}

int		insert_room(t_binarytree **rooms, t_room *room)
{
	int		compare;

	if (!*rooms)
		*rooms = ft_treeinit(room, 0);
	else
	{
		compare = ft_strcmp(ROOM(*rooms)->name, room->name);
		if (compare == 0)
			return (1);
		else if (compare > 0)
			insert_room(&(*rooms)->right, room);
		else
			insert_room(&(*rooms)->left, room);
	}
	return (0);
}

void	delete_room(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
	{
		ft_strdel(&((t_room *)(content))->name);
	//	ft_memdel((void **)&((t_room *)(content))->paths);
		ft_memdel((void **)&((t_room *)(content))->links);
		ft_memdel((void **)&content);
	}
}
