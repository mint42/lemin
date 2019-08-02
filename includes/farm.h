/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/02 02:52:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include "room.h"
# include <stddef.h>

typedef struct	s_farm
{
	size_t		ants;
	size_t		start_room_id;
	size_t		end_room_id;
	size_t		nrooms;
	t_room		*graph;
}				t_farm;

typedef struct s_binarytree		t_binarytree;

t_room		*init_farm(size_t nrooms);
int			make_farm(t_binarytree *rooms, t_room **farm, size_t room);
int			delete_farm(t_room **farm);

#endif
