/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:05:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/10 21:37:57 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "farm.h"
#include "errors.h"
#include <stddef.h>

int		search(t_bfs *cur, t_bfs *tail, t_farm *farm, size_t *delimiter)
{
	size_t		nlinks;
	size_t		level;

	level = 0;
	while (level < *delimiter)
	{
		nlinks = 0;
		while (nlinks < (farm->graph[cur->room_id]).nlinks)
		{
			if ((farm->graph[cur->room_id]).links[nlinks] != cur->room_id)
				if (new_bfs_node(cur, tail, farm) == ERROR)
					return (ERROR);
			++nlinks;
		}
		if (cur->next->depth_level > cur->depth_level)
			++level;
		cur = cur->next;
	}
	return (0);
}
