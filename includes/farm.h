/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/18 23:34:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include "room.h"
# include <stddef.h>

typedef struct s_binarytree		t_binarytree;

typedef struct	s_farm
{
	t_room		*graph;
	size_t		nrooms;
	size_t		start_rid;
	size_t		end_rid;
	size_t		ants;
}				t_farm;

t_farm			init_farm();
t_room			*init_graph(size_t nrooms);
int				make_graph(t_binarytree *rooms, t_farm *farm);
void			delete_graph(t_room **graph);

#endif
