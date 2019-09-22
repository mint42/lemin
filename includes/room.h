/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:38:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/22 04:41:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include <stddef.h>
# include <stdint.h>

# define ROOM(binarytree) ((t_room *)((binarytree)->content))

# define NAME(room) (farm[room].name)
# define X(room) (farm[room].x)
# define Y(room) (farm[room].y)
# define S_OR_E(room) (farm[room].start_or_end)
# define NLINKS(room) (farm[room].nlinks)
# define MLINKS(room) (farm[room].mlinks)
# define LINKS(room) (farm[room].links)
# define NPATHS(room) (farm[room].npaths)
# define MPATHS(room) (farm[room].mpaths)
# define PATHS(room) (farm[room].paths)

# define START_ROOM 1
# define END_ROOM 2

typedef struct s_binarytree		t_binarytree;

typedef struct	s_room
{
	uint8_t		start_end;
	int			x;
	int			y;
	char		*name;
	size_t		len;
	size_t		*links;
	size_t		nlinks;
	size_t		mlinks;
	size_t		*paths_encountered;
	size_t		npaths_encountered;
	size_t		mpaths_encountered;
}				t_room;

t_room			*init_room(void);
int				rearrange_rooms_by_name(t_binarytree **rooms_by_coordinte);
int				insert_room_by_coordinates(t_binarytree **rooms, t_room *room);
int				insert_room_by_name(t_binarytree **rooms, t_binarytree *room);
void			delete_room(void *content, size_t content_size);

#endif
