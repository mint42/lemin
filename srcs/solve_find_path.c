/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:05:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/17 23:19:31 by rreedy           ###   ########.fr       */
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
**	DONE - return when new path is found
**	DONE - finish the loop though  ye
**	DONE - confirm new path when start meets end, or vice versa
**	DONE - will delimiter always work or will you run out of nodes first, added a check just in case
**	DONE - allocate for a new node
**	done - combine sides
**	DONE - give room new bit so that you have been there
**	done - check that the path you're on doesn't run into other base paths, or the same path twice. do i have to check the dni lis
**			for both when updating pathset and also when running the search  no, i dont think so
**	done - add the paths that you crossed from the room to the dni list
*/


static int	update_path_info(t_solve *solve, t_farm *farm, t_pathinfo **new_pathinfo, size_t new_path)
{
	if (!new_path)
		new_pathinfo = solve->bfs_cur->pathinfo;
	else
	{
		new_pathinfo = (t_path *)ft_memalloc(sizeof(t_path));
		if (!new_pathinfo)
			return (print_error(E_ALLOC_ERROR));
		if (solve->bfs_cur->pathinfo->pid_bit & 100000000000000000)
		{
			new_pathinfo->pid_index = solve->bfs_cur->pathinfo->pid_index + 1;
			new_pathinfo->pid_bit = 1;
		}
		else
			new_pathinfo->pid_bit = solve->bfs_cur->path_info->pid_bit << 1;

		new_pathinfo->base_pid = solve->bfs_cur->path_info->base_pid;
		new_pathinfo->depth_level = solve->bfs_cur->path_info->depth_lvl;
		new_pathinfo->npaths_dni = solve->bfs_cur->path_info->npaths_dni;
		new_pathinfo->mpaths_dni = solve->bfs_cur->path_info->mpaths_dni;
	}
	new_pathinfo->*paths_dni;

}

static int	update_basepath_info(t_solve *solve)
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

int			update_bfs(t_solve *solve, t_farm *farm, size_t i, bool *path_found)
{
	t_bfs	*new_node;

	if (init_bfs(new_node) == ERROR)
		return (ERROR);
	new_node->rid = (farm->rooms)[bfs_cur->rid].links[i];
	update_basepath_info(solve);
	update_path_info(solve);
	new_node->prev = cur;
	solve->tail->next = new_node;
	solve->tail = tail->next;
	if ((solve->basepaths)[solve->bfs_cur->path_info->basepath_id]->origin != (solve->basepaths)[new_node->path_info->basepath_id]->origin)
	{
		path_found = true;
		combine_ends(solve, new_node);
	}
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
			if ((farm->rooms[solve->bfs_cur->rid]->links[i] != cur->rid)
				if (update_bfs(solve, farm, i, &path_found) == ERROR)
					return (ERROR);
			if (farm->rooms[bfs_cur->rid]->mpaths_encountered >= solve->cur_bfs->path_info->path_index)
				farm->rooms[bfs_cur->rid]->paths_encountered[solve->cur_bfs->path_info->path_id_index] = farm->rooms[bfs_cur->rid]->paths_encountered[solve->cur_bfs->path_info->path_id_index] & solve->cur_bfs->path_info->path_id_bit;
			++i;
		}
		--(solve->depth_delimiter);
		if (path_found == true)
			break ;
		bfs_cur = bfs_cur->next;
	}
	return (0);
}
