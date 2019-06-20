/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/19 22:24:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

#include <stddef.h>

/*
the farm is stored as an array of this s_room struct. if the "adjacency list" was
a list of indexes that represent rooms, then finding a room, and the rooms that
connected to it would be instant.
*/

typedef struct	s_room
{
	char		*room_name;
	int			x_coordinate;
	int			y_coordinate;
	int			start_or_end;
	size_t		nlinks;
	size_t		mlinks;
	size_t		*links;
	size_t		npaths;
	size_t		mpaths;
	size_t		*paths;
}				t_room;

#endif
