/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rearrange_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:19:38 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 22:53:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "room.h"
#include "ft_binarytree.h"

static int 		rearrange(struct s_binarytree **rooms_by_coordinate, struct s_binarytree **rooms_by_name)
{
	if (!rooms_by_coordinate)
		return (0);
	if ((*rooms_by_coordinate)->left)
		rearrange(&(*rooms_by_coordinate)->left, rooms_by_name);
	if ((*rooms_by_coordinate)->right)
		rearrange(&(*rooms_by_coordinate)->right, rooms_by_name);
	if (!rooms_by_name || !*rooms_by_name)
		*rooms_by_name = *rooms_by_coordinate;
	else if (insert_room_by_name(rooms_by_name, *rooms_by_coordinate) == ERROR)
		return (ERROR);
	return (0);
}

int 			rearrange_rooms_by_name(struct s_binarytree **rooms_by_coordinate)
{
	struct s_binarytree	*rooms_by_name;

	rooms_by_name = 0;
	if (rearrange(rooms_by_coordinate, &rooms_by_name) == ERROR)
		return (ERROR);
	*rooms_by_coordinate = rooms_by_name;
	return (0);
}
