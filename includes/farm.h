/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/07/01 20:52:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include "room.h"
# include <stddef.h>

# define NAME(room) (farm[room].name)
# define X(room) (farm[room].x)
# define Y(room) (farm[room].y)
# define S_OR_E(room) (farm[room].start_or_end)
# define NLINKS(room) (farm[room].nlinks)
# define MLINKS(room) (farm[room].mlinks)
# define LINKS(room) (farm[room].links)
# define NPATHS(room) (farm[room].npaths)
# define MPATHS(room) (farm[room].mpaths)
# define PATHS(room) (farm[room].paths)

typedef struct s_binarytree		t_binarytree;

t_room		*init_farm(size_t nrooms);
int			make_farm(t_binarytree *rooms, t_room **farm, size_t room);
int			delete_farm(t_room **farm);

#endif
