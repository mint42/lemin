/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 22:31:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include "room.h"
# include <stddef.h>

struct s_farm
{
	struct s_room	*graph;
	size_t			nrooms;
	size_t			start_rid;
	size_t			end_rid;
	size_t			ants;
};

int				init_farm(struct s_farm **farm);
struct s_room	*init_graph(size_t nrooms);
int				make_graph(struct s_binarytree *rooms, struct s_farm *farm);
void			delete_graph(struct s_room **graph);

#endif
