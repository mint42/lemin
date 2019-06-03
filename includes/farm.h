/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/03 06:54:58 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

#include <stddef.h>

typedef struct	s_room
{
	char		*room_name;
	size_t		room_number;
	size_t		*paths_encountered;
	size_t		*adjacency_list;
	int			x;
	int			y;
}				t_room;

int		create_ant_farm(t_room **farm);
int		delete_ant_farm(t_room **farm);

#endif
