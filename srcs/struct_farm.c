/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_farm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:44:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 01:32:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "farm.h"
#include "errors.h"
#include "ft_mem.h"
#include "ft_binarytree.h"
#include "ft_printf.h"
#include <stddef.h>

struct s_farm			init_farm(void)
{
	struct s_farm	farm;

	farm.ants = 0;
	farm.start_room_id = 0;
	farm.end_room_id = 0;
	farm.nrooms = 0;
	farm.graph = 0;
	return (farm);
}

struct s_room			*init_graph(size_t nrooms)
{
	struct s_room	*graph;

	graph = (struct s_room *)ft_memalloc(sizeof(struct s_room) * nrooms);
	if (!graph)
		return (0);
	return (graph);
}

static void		fill_graph(struct s_farm *farm, struct s_binarytree *rooms, size_t *room_id)
{
	if (rooms)
	{
		if (rooms->left)
			fill_graph(farm, rooms->left, room_id);
		(farm->graph)[*room_id] = *ROOM(rooms);
		if (ROOM(rooms)->start_end & START_ROOM)
			farm->start_room_id = *room_id;
		if (ROOM(rooms)->start_end & END_ROOM)
			farm->end_room_id = *room_id;
		++(*room_id);
		if (rooms->right)
			fill_graph(farm, rooms->right, room_id);
	}
}

int				make_graph(struct s_binarytree *rooms, struct s_farm *farm)
{
	size_t	room_id;
	
	room_id = 0;
	farm->graph = (struct s_room *)ft_memalloc(sizeof(struct s_room) * farm->nrooms);
	if (!(farm->graph))
		return (print_error(E_ALLOC_ERROR));
	fill_graph(farm, rooms, &room_id);
	return (0);
}

void			delete_graph(struct s_room **graph)
{
	(void)graph;
	ft_printf("delete graph\n");
}
