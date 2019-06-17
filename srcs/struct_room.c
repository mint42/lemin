/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:42:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/08 14:48:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "ft_mem.h"
#include "ft_str.h"

t_room	*init_room(void)
{
	t_room	*room;

	room = ft_memalloc(sizeof(t_room));
	if (!room)
		return (0);
	room->start = 0;
	room->end = 0;
	room->room_name = 0;
	room->room_number = 0;
	room->paths_encountered = 0;
	room->adjacency_list = 0;
	room->x = 0;
	room->y = 0;
	return (room);
}

int		insert_room(t_binarytree **rooms, t_room *room)
{
	int		compare;

	if (!*rooms)
		*rooms = ft_treeinit(room, 0);
	else
	{
		compare = ft_strcmp(ROOM(rooms)->room_name, room->room_name);
		if (compare == 0)
			return (1);
		else if (compare > 0)
			insert_room(&(*rooms)->right, room);
		else
			insert_room(&(*rooms)->left, room);
	}
	return (0);
}

void	delete_room(t_room **room)
{
	if (*room)
	{
		ft_strdel(&(*room)->room_name);
		ft_memdel(&((*room)->paths_encountered));
		ft_memdel(&((*room)->adjacency_list));
		ft_memdel(room);
	}
}
