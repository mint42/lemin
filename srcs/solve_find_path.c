/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:05:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/16 01:27:04 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "farm.h"
#include "errors.h"
#include <stddef.h>

static int	

int			find_path(t_bfs *cur, t_bfs *tail, t_farm *farm, size_t *delimiter)
{
	size_t		nlinks;
	size_t		level;
	size_t		new_id;

	level = 0;
	while (level < *delimiter)
	{
		nlinks = 0;
		while (nlinks < (farm->graph[cur->room_id]).nlinks)
		{
			if ((farm->graph[cur->room_id]).links[nlinks] != cur->room_id)
			{
				new_node = new_bfs_node(cur, tail, farm);
				new_node->depth_level = cur->depth_level + 1;
				cur->path_info->paths_to_avoid[cur->path_info->npaths_to_avoid - 1] 
				
			++nlinks;
		}
		if (cur->next->depth_level > cur->depth_level)
			++level;
		cur = cur->next;
	}
	return (0);
}
