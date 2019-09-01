/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_farm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:44:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/01 01:59:47 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "farm.h"
#include "errors.h"
#include "ft_mem.h"
#include "ft_binarytree.h"
#include "ft_printf.h"
#include <stddef.h>

t_farm			init_farm(void)
{
	t_farm	farm;

	farm.ants = 0;
	farm.start_room_id = 0;
	farm.end_room_id = 0;
	farm.nrooms = 0;
	farm.graph = 0;
	return (farm);
}

t_room			*init_graph(size_t nrooms)
{
	t_room	*graph;

	graph = (t_room *)ft_memalloc(sizeof(t_room) * nrooms);
	if (!graph)
		return (0);
	return (graph);
}

static void		fill_graph(t_room *graph, t_binarytree *rooms, size_t room)
{
	if (rooms)
	{
		if (rooms->right)
			fill_graph(graph, rooms, room);
		graph[room] = *(t_room *)(rooms->content);
		--room;
		if (rooms->left)
			fill_graph(graph, rooms, room);
	}
}

int				make_graph(t_binarytree *rooms, t_farm *farm)
{
	farm->graph = (t_room *)ft_memalloc(sizeof(t_room) * farm->nrooms);
	if (!(farm->graph))
		return (print_error(ALLOC_ERROR));
	fill_graph(farm->graph, rooms, farm->nrooms);
	return (0);
}

void			delete_graph(t_room **graph)
{
	(void)graph;
	ft_printf("delete graph\n");
}
