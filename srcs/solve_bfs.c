/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:05:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 02:51:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "lemin.h"
#include "struct_basepath.h"
#include "struct_bfs.h"
#include "struct_farm.h"
#include "struct_path_info.h"
#include "struct_room.h"
#include "struct_solve.h"
#include "ft_mem.h"
#include <stddef.h>
#include <stdint.h>

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
	add_pid(basepath_info.paths, path_info.pid_index, path_info.pid_bit);
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

static void		inspect_link(struct s_room *link, struct s_solve *solve, uint8_t *path_status)
{
	struct s_basepath	basepath;
	size_t				i;

	i = 0;
	basepath = (solve->basepaths)[solve->bfs_cur->path_info->base_pid];
	while (*path_status == IN_PROGRESS && i < link->pids_met_len && i < basepath.child_pids_len && i < solve->start_pids_len)
	{
		if (link->pids_met[i] & basepath.child_pids[i])
			*path_status = DROPPED;
		if ((basepath.origin == START_ROOM) && (link->pids_met[i] & ~solve->start_pids[i]))
			*path_status = COMPLETED;
		else if ((basepath.origin == END_ROOM) && (link->pids_met[i] & solve->start_pids[i]))
			*path_status = COMPLETED;
		++i;
	}
}

int		update_bfs_queue(struct s_solve *solve, struct s_farm *farm, uint8_t *path_status)
{
	static size_t	i;
	struct s_room	room;
	struct s_bfs	*new_node;

	room = (farm->graph)[solve->bfs_cur->rid];
	while (i < room.nlinks)
	{
		if (room.links[i] != solve->bfs_cur->rid)
		{
			inspect_link(&((farm->graph)[room.links[i]]), solve, path_status);
			if (*path_status != IN_PROGRESS)
				return (0);
			if (setup_bfs_node(&new_node, solve, farm, i) == ERROR)
				return (ERROR);
			solve->bfs_tail->next = new_node;
			new_node->prev = solve->bfs_tail;
			new_node->path_prev = solve->bfs_cur;
			solve->bfs_tail = new_node;
		}
		++i;
	}
	i = 0;
	return (0);
}
