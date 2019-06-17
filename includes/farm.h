/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/15 20:27:58 by rreedy           ###   ########.fr       */
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
	int			start;
	int			end;
	size_t		room_index;
	size_t		num_links;
	size_t		max_links;
	size_t		*links;
	size_t		num_paths;
	size_t		max_paths;
	size_t		*paths;
}				t_room;

#endif
