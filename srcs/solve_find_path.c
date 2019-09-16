/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:05:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/16 16:17:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "farm.h"
#include "errors.h"
#include <stddef.h>

static int	

/*
**	bits
**	
**	paths in base paths
**	path id's that have been to rooms
**	paths to avoid - every node
**	paths to avoid - pathset version
**	
**	
**	
**	
**	should have 2 base path id's when combined, should the base bath's be bits then
**	I did not want them to be, what about making it an array the size of two
**	no, i am just going to go to next, it is wasted space
**	
**	- stop when paths combined
**	- combine paths
**	- add room bits to path when it crosses
**	- add bit to room when path crosses it
**	
**	- a path cant touch paths from the same base path, TRUE, because length
**	
**	- when a new path is split, it inherits the old criteria, but can add to it on its own, so realloc
*/

int			find_path(t_solve *solve, t_bfs *bfs_cur, t_bfs *bfs_tail, t_farm *farm)
{
	size_t		i;
	size_t		level;
	size_t		new_id;

	level = 0;
	while (level < *delimiter)
	{
		i = 0;
		while (i < (farm->graph[cur->room_id]).nlinks)
		{
			if ((solve->basepath)[bfs_cur->base_path_id]->start_or_end != (solve->basepath))
			if ((farm->rooms[cur->rid]).links[i] != cur->rid)
			{
				new_node = new_bfs_node(cur, tail, farm);
				new_node->depth_level = cur->depth_level + 1;
				cur->path_info->paths_to_avoid[cur->path_info->npaths_to_avoid - 1] 
			}
			++i;
		}
		if (cur->next->depth_level > cur->depth_level)
			++level;
		cur = cur->next;
	}
	return (0);
}
