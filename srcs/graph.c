/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 02:50:49 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/28 22:40:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "farm.h"
#include "errors.h"
#include "ft_mem.h"
#include "ft_binarytree.h"
#include "ft_printf.h"
#include <stddef.h>

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
	fill_graph(farm->graph, rooms, farm->nrooms - 1);
	return (0);
}


int				delete_graph(t_room **graph)
{
	(void)graph;
	ft_printf("delete ant graph\n");
	return (0);
}
