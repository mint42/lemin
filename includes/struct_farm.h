/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 08:56:08 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_FARM_H
# define STRUCT_FARM_H

# include <stddef.h>

struct s_room;

/*
**	s_farm is a struct storing information about that ant farm
**
**	graph				An array of all rooms inside the farm, arranged in alphabetical
**						order by name
**	nrooms				Number of rooms in the farm
**	longest_room_name	Length of the name of the longest room name
**	start_rid			Room ID of the start (source) room
**	end_rid				Room ID of the end (sink) room
*/

struct				s_farm
{
	struct s_room	**rooms;
	size_t			nrooms;
	size_t			longest_room_name;
	size_t			start_rid;
	size_t			end_rid;
	size_t			nants;
};

void				init_farm(struct s_farm *farm);

#endif
