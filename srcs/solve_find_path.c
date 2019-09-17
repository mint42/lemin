/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:05:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/16 22:18:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "farm.h"
#include "errors.h"
#include <stddef.h>

/*
**	bits
**	
**	paths in base paths
**	path id's that have been to rooms
**	paths to avoid - every node
**	paths to avoid - pathset version
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
**	- add new pathid to its base path list of ids
**	
**	- a path cant touch paths from the same base path, TRUE, because length
**	
**	- when a new path is split, it inherits the old criteria, but can add to it on its own, so realloc
*/
/*
**	if base path id is 0 then that means that no base path was set yet
**	
**	if a base path is set, then you want to make a new node
**	
**	when do you give it a new path id. only the first one to enter gets a new id
**	
**	the base path info struct will be shared across all paths from the same base
*/
/*
**	DOne - return when new path is found
**	DONE - finish the loop though  ye
**	done - confirm new path when start meets end, or vice versa
**	done - will delimiter always work or will you run out of nodes first, added a check just in case
**	done - allocate for a new node
**	done - combine sides
**	done - give room new bit so that you have been there
**	done - check that the path you're on doesn't run into other base paths, or the same path twice. do i have to check the dni lis
**			for both when updating pathset and also when running the search  no, i dont think so
**	done - add the paths that you crossed from the room to the dni list
**	
**	done - inital allocate the mpaths_in_base variable based on how many paths are at the start or end node
*/


static int	copy_and_update_basepath_info(t_path *path_info, t_solve *solve)
{
	++solve->nbase_paths;
	cur->start_or_end = (cur->room_id == farm->start_room_id) ? 1 : 2;
	cur->base_path_info->base_path_id = solve->nbase_paths;
	if (cur->path_id_bit & 0x100000000000000)
	{
		update the numbas;
		new_node->path_id_bit = 1;
		++(new_node->path_id_index);
	}
	else
		new_node->path_id_index = cur->path_id_index << 1;
	if (dont need to add more numbah)
		cur->base_path_info->paths_in_base[new_node->path_id_index] = cur->base_path_info->paths_in_base | new_node->path_id_bit;
	else
	{
		update the numbas;
		++(cur->base_path_info->npaths_in_base);
		cur->base_path_info->mpaths_in_base *= 2;
	}
}

static int	copy_and_update_path_info(t_path *path_info, t_solve *solve)
{
	path_info = (t_path *)ft_memalloc(sizeof(t_path));
	if (!path_info)
		return (print_error(E_ALLOC_ERROR));
	if (solve->bfs_cur->path_info->path_id_bit & 100000000000000000)
	{
		path_info->path_id_index = solve->bfs_cur->path_info->path_id_index + 1;
		path_info->path_id_bit = 1;
	}
	else
		path_info->path_id_bit = solve->bfs_cur->path_info->path_id_bit << 1;

	path_info->basepath_id;

	path_info->depth_level = solve->bfs_cur->path_info->depth_level;
	path_info->npaths_dni = solve->bfs_cur->path_info->npaths_dni;
	path_info->mpaths_dni = solve->bfs_cur->path_info->mpaths_dni;

	path_info->*paths_dni;
}

int			update_bfs(t_solve *solve, t_farm *farm, size_t i, bool *path_found)
{
	t_bfs	*new_node;

	if (init_bfs(new_node) == ERROR)
		return (ERROR);
	new_node->rid = (farm->rooms)[bfs_cur->rid].links[i];

	update base paths's paths here;

	if (i == 0)
		new_node->path_info = solve->bfs_cur->path_info;
	else
	{
		if (copy_and_update_path_info(new_node->path_info, solve) == ERROR)
			return (ERROR);
	}

	update cur->path_info's dni list here
	cur->dni[cur->ndni - 1]

	look for path

	new_node->prev = cur;
	solve->tail->next = new_node;
	solve->tail = tail->next;
	return (0);
}

int			find_path(t_solve *solve, t_farm *farm)
{
	size_t		i;
	bool		path_found;

	path_found = false;
	while (cur && solve->depth_delimiter)
	{
		i = 0;
		while (i < (farm->rooms[bfs_cur->rid]).nlinks)
		{
			++(solve->bfs_cur->path_info->depth_level);
			if ((farm->rooms[solve->bfs_cur->rid]).links[i] != cur->rid)
				if (update_bfs(solve, farm, i, &path_found) == ERROR)
					return (ERROR);
			++i;
		}
		--(solve->depth_delimiter);
		if (path_found == true)
			break ;
		bfs_cur = bfs_cur->next;
	}
	return (0);
}
