/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:05:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/25 07:23:13 by rreedy           ###   ########.fr       */
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
**	DONE - check that the path you're on doesn't run into other base paths, or the same path twice. do i have to check the dni lis
**			for both when updating pathset and also when running the search  no, i dont think so
**	DONE - add the paths that you crossed from the room to the dni list
**	done - how order files
*/

static int		update_path_info(t_solve *solve, t_farm *farm, t_bfs *new_node, size_t make_new_path)
{
	if (!make_new_path)
		new_node->pathinfo = solve->bfs_cur->pathinfo;
	else
	{
		new_node->pathinfo = (t_path *)ft_memalloc(sizeof(t_path));
		if (!new_pathinfo)
			return (print_error(E_ALLOC_ERROR));
		if (solve->bfs_cur->pathinfo->pid_bit & 100000000000000000)
		{
			new_node->pathinfo->pid_index = solve->bfs_cur->pathinfo->pid_index + 1;
			new_node->pathinfo->pid_bit = 1;
		}
		else
			new_node->pathinfo->pid_bit = solve->bfs_cur->path_info->pid_bit << 1;
		new_node->pathinfo->base_pid = solve->bfs_cur->path_info->base_pid;
		new_node->pathinfo->depth_level = solve->bfs_cur->path_info->depth_lvl;
		new_node->pathinfo->npaths_dni = solve->bfs_cur->path_info->npaths_dni;
		new_node->pathinfo->mpaths_dni = solve->bfs_cur->path_info->mpaths_dni;
		while (farm->rooms[bfs_cur->rid]->npaths_encountered > solve->cur_bfs->path_info->mpaths_dni)
			if (realloc_array() == ERROR)
				return (ERROR);
		while (i < farm->rooms[bfs_cur->rid]->npaths_encountered)
			solve->cur_bfs->path_info->mpaths_dni[i] = solve->cur_bfs->path_info->mpaths_dni[i] & farm->rooms[bfs_cur->rid]->paths_encountered[i];
	}
	new_node->pathinfo->*paths_dni;
	return (0);
}

static int	update_basepath_info(t_solve *solve, t_bfs *new_node)
{
	t_path_info	path_info;
	t_basepath	basepath_info;
	
	path_info = new_node->path_info;
	basepath_info = solve->basepaths[path_info->base_pid];
	add_pid(array, size_array, index, bit);
/*
**	while (path_info.pid_index > basepath_info->mpaths)
**		if (realloc_array(&basepath_info.paths, &basepath_info.mpaths) == ERROR)
**			return (ERROR);
**	ADD_PID(basepath_info.paths, path_info.pid_index, path_info.pid_bit);
**	basepath.paths[path_info.pid_index] = basepath.paths[path_info.pid_index] | path_info.pid_bit;
*/
	return (0);
}

static int		combine_ends(t_solve *solve, t_bfs *new_node, t_farm *farm)
{
	t_bfs	*cur;
	
	cur = solve->cur_bfs;
	while (cur && )
	{
		
	}
}

/*
**	static int		create_new_bfs_node(t_solve *solve, t_farm *farm, t_bfs *new_node, bool make_new_path)
**	{
**		t_bfs			*new_node;
**		size_t			i;
**		
**		i = 0;
**		if (init_bfs_node(new_node) == ERROR)
**			return (ERROR);
**		if (!make_new_path)
**			new_node->pathinfo = solve->bfs_cur->pathinfo;
**		else
**		{
**			new_node->pathinfo = (t_path *)ft_memalloc(sizeof(t_path));
**			if (!new_node->pathinfo)
**				return (print_error(E_ALLOC_ERROR));
**			if (solve->bfs_cur->pathinfo->pid_bit & 100000000000000000)
**			{
**				new_node->pathinfo->pid_index = solve->bfs_cur->pathinfo->pid_index + 1;
**				new_node->pathinfo->pid_bit = 1;
**			}
**			else
**				new_pathinfo->pid_bit = solve->bfs_cur->path_info->pid_bit << 1;
**			new_node->pathinfo->base_pid = solve->bfs_cur->path_info->base_pid;
**			new_node->pathinfo->depth_level = solve->bfs_cur->path_info->depth_lvl;
**			new_node->pathinfo->npaths_dni = solve->bfs_cur->path_info->npaths_dni;
**			new_node->pathinfo->mpaths_dni = solve->bfs_cur->path_info->mpaths_dni;
**		}
**	}
**			while (i < farm->graph[bfs_cur->rid]->npaths_encountered)
**				solve->cur_bfs->path_info->mpaths_dni[i] = solve->cur_bfs->path_info->mpaths_dni[i] & farm->rooms[bfs_cur->rid]->paths_encountered[i];
**		}
**		new_pathinfo->*paths_dni;
**		return (0);
**	
**			add_pid(room->path_encounters, room->mpath_encounters, path_info->pid_index, path_info->pid_bit);
**			add_pid(solve->paths_in_base, solve->npaths_in_base, pathinfo.pid_index, pathinfo.pid_bit);
**			if (solve->basepaths[path_info->base_pid]->origin == START)
**				add_pid(solve->startpaths, solve->nstartpaths, new_node->path_info->pid_index, new_node->path_info->pid_bit)
**	
**				update_pathinfo(new_node);
**				update_basepath_info(solve);
**		new_node->prev = cur;
**		solve->tail->next = new_node;
**		solve->tail = tail->next;
**		return (0);
**	}
*/

static int		inspect_link(t_solve *solve, t_farm *farm, uint8_t *path_status)
{
	t_room		*link;
	t_basepath	*basepath;
	size_t		i;
	
	i = 0;
	basepath = (solve->basepaths)[solve->bfs_cur->pathinfo->base_pid];
	link = (farm->graph)[(farm->graph)[solve->bfs_cur->rid]->links[i]];
	while (path_status == IN_PROGRESS && i < link->npaths_encountered && i < basepath->paths_in_base && i < solve->nstart_paths)
	{
		if (link->paths_encountered[i] & basepath->paths_in_base[i])
			*path_status = DROPPED;
		if ((basepath->origin == START) && (link->paths_encountered[i] & solve->start_paths[i]))
			*path_status = COMPLETED;
		else if ((basepath->origin == END) && (link->paths_encountered[i] & ~solve->start_paths[i]))
			*path_status = COMPLETED;
		++i;
	}
}

static int		process_bfs_node(t_solve *solve, t_farm *farm, uint8_t *path_status)
{
	static size_t	i;
	t_room			*room;
	t_bfs			*new_node;

	while (path_status == IN_PROGRESS && i < room->nlinks)
	{
		room = (farm->graph)[solve->bfs_cur->rid];
		if (room->links[i] != cur->rid)
		{
			inspect_link(solve, farm, &path_status);
			if (*path_status == COMPLETE || *path_status == DROPPED)
				return (0);
			if (create_new_bfs_node(solve, farm, &new_node, i) == ERROR)
				return (ERROR);
			add_node_to_bfs(solve->bfs, new_node);
		}
		++i;
	}
	i = 0;
	return (0);
}

int				run_bfs(t_solve *solve, t_farm *farm)
{
	static uint8_t		path_status;

	if (path_status == COMPLETE)
		return (combine_ends(solve, farm));
	if (path_status == DROPPED)
		return (delete_path(solve, farm));
	path_status = IN_PROGRESS;
	while (solve->bfs_cur && solve->depth_delimiter)
	{
		++(solve->bfs_cur->path_info->depth_level);
		if (process_bfs_node(solve, farm) == ERROR)
			return (ERROR);
		if (*path_status == COMPLETE || *path_status == DROPPED)
			return (run_bfs(solve, farm));
		--(solve->depth_delimiter);
		solve->bfs_cur = solve->bfs_cur->next;
	}
	return (0);
}
