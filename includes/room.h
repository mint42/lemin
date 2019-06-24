/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:38:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/24 11:38:40 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include <stddef.h>

# define START_ROOM 0x1
# define END_ROOM 0x2

# define ROOM(binarytree)	((t_room *)((binarytree)->content))
/*
the farm is stored as an array of this s_room struct. if the "adjacency list" was
a list of indexes that represent rooms, then finding a room, and the rooms that
connected to it would be instant.
*/

typedef struct s_binarytree		t_binarytree;

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int			start_or_end;
	size_t		nlinks;
	size_t		mlinks;
	size_t		*links;
	size_t		npaths;
	size_t		mpaths;
	size_t		*paths;
}				t_room;

t_room			*init_room(void);
int				insert_room(t_binarytree **rooms, t_room *room);
void			delete_room(void *content, size_t content_size);

#endif
