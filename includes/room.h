/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:38:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/07/28 05:42:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include <stddef.h>

# define START_ROOM 0x1
# define END_ROOM 0x2

# define ROOM(binarytree)	((t_room *)((binarytree)->content))

typedef struct s_binarytree		t_binarytree;

typedef struct	s_room
{
	char		*name;
	size_t		len;
	int			x;
	int			y;
	size_t		*links;
	size_t		nlinks;
	size_t		mlinks;
	size_t		*paths_crossed;
	size_t		npaths_crossed;
	size_t		mpaths_crossed;
}				t_room;

t_room			*init_room(void);
int				insert_room(t_binarytree **rooms, t_room *room);
void			delete_room(void *content, size_t content_size);

#endif
