/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/30 10:44:43 by rreedy           ###   ########.fr       */
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

t_farm		init_farm();
t_room		*init_graph(size_t nrooms);
int			make_graph(t_binarytree *rooms, t_farm *farm);
void		delete_graph(t_room **graph);

#endif
