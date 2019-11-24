/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 00:20:03 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_FARM_H
# define STRUCT_FARM_H

# include <stdint.h>

struct				s_room;
struct				s_binarytree;

struct				s_farm
{
	struct s_room	*graph;
	size_t			nrooms;
	size_t			longest_room_name;
	size_t			start_rid;
	size_t			end_rid;
	size_t			ants;
};

int					init_farm(struct s_farm *farm);
struct s_room		*init_graph(size_t nrooms);
int					make_graph(struct s_binarytree *rooms, struct s_farm *farm);
void				delete_graph(struct s_room **graph);

#endif
