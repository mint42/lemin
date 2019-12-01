/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_rooms.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:15:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 12:01:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_ROOMS_H
# define GRAPH_ROOMS_H

# include <stddef.h>

struct s_binarytree;
struct s_room;
struct s_farm;

int		setup_rooms(struct s_binarytree *bintree_rooms, struct s_farm *farm);
void	delete_rooms(struct s_room ***rooms, size_t nrooms);

#endif
