/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_room.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:18:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 12:08:08 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ROOM_H
# define STRUCT_ROOM_H

# include <stddef.h>
# include <stdint.h>

# define START_ROOM 1
# define END_ROOM 2

# include "struct_pathids.h"

/*
**	s_room is a struct storing information about a room in the ant farm.
**
**	start_end	Indicator of whether or not this room is the source and/or sink
**	x			X coordinate of the room
**	y			Y coordinate of the room
**	name		Name of the room
**	len			Length of the room's name
**	links		Array of Room ID's that connect to this one. This array is
**				dynamically allocated as links are processed from input data
**	nlinks		Number of links
**	links_size	Total allocated size of the array
**	pids_met	A variable storing Path ID's of paths that have interracted with
**				this room
*/

struct					s_room
{
	uint8_t				start_end;
	int					x;
	int					y;
	char				*name;
	size_t				len;
	size_t				*links;
	size_t				nlinks;
	size_t				links_arr_size;
	struct s_pathids	*pids_met;
};

int		init_room(struct s_room **room);
void	delete_room(void *content, size_t content_size);

#endif
