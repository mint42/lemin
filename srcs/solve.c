/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:43:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/29 04:26:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"
#include "room.h"
#include "pathsets.h"
#include "bfs.h"
#include "solve.h"
#include "errors.h"
#include "ft_list.h"
#include <stddef.h>

/*
**	rules for solving:
**		- paths are stored in the queue, and to get to a path you go backwards using a previous pointer 
**		- when a path intersects with the same base path, do not continue the current path
**		- when a path intersects with a different base path, note that they cannot coexist by adding that specific path to the DNI list
**		- use a pointer to the double array so that the path info can be updated at any point
**	
**		- paths that split get a new number on path to avoid
**		- a new path set is made when starting paths intersect (paths with different identifiers)
**		- remember that a path has to avoid itself
**		- if a path crosses a path it can't interesect it the longer one can be destroyed, unless it has branched from start?
**		- the longer one will always be the one you're currently extending
**		- paths are stored as arrays, but there is a linked list of path sets?
**		- if a path has made it to the end first, all other paths that have branched from it can be destroyed. NO
**				because what if the shorter path is needed by another identifier
**		- actually every path gets an identifier?? and every path also gets a base path which it cant interract with
*/

/*
**	#include "ft_printf.h"
**	static void		make_solution_printable(t_pathset *best, char **solution)
**	{
**		t_list	*paths;
**		
**		(void)solution;
**		paths = best->paths;
**		while (paths)
**		{
**			ft_printf("%5d %5b\n", PATH_ID_INDEX(paths), PATH_ID_BIT(paths));
**			paths = paths->next;
**		}
**	}
*/

static void		overlap_pids_dni(t_bfs *end1, t_bfs *end2)
{
	size_t			*tmp;
	size_t			i;

	if (end1->s_pids_dni < cur->s_pids_dni)
	{
		tmp = end1->pids_dni;
		end1->pids_dni = end2->pids_dni;
		end2->pids_dni = tmp;
	}
	i = 0;
	while (i < cur->pids_dni)
	{
		end1->pids_dni[i] = end1->pids_dni[i] | end2->pids_dni[i];
		++i;
	}
}

static void		combine_ends(t_solve *solve, t_bfs *end1, uint8_t *path_status)
{
	static t_bfs	*cur;
	
	cur = solve->cur_bfs;
	if (!cur)
		cur = solve->bfs_cur;
	while (cur->depth_level >= end1->depth_level)
	{
		if (cur->depth_level != end1->depth_level &&
			solve->s_start_paths >= cur->pid_index &&
			solve->s_start_paths[cur->pid_index] & cur->pid_bit)
		{
			end1->depth_level = end1->depth_level + cur->depth_level;
			overlap_pids_dni(end1, cur);
			cur->path_info = end1->path_info;
			return ;
		}
		cur = cur->prev;
	}
	cur = 0;
}

int				solve(t_farm *farm, char **solution)
{
	t_solve		solve;
	uint8_t		path_status;

	path_status = IN_PROGRESS;
	if (setup_solve(&solve, farm) == ERROR)
		return (ERROR);
	while (solve.bfs_cur && solve.depth_delimiter >= 0)
	{
		if (path_status == IN_PROGRESS)
			if (run_bfs(solve, farm) == ERROR)
				return (ERROR);
		if (path_status == COMPLETE)
			return (combine_ends(solve, farm, &path_status));
		if (update_pathsets(solve, farm) == ERROR)
			return (ERROR);
	}
	if (solve.pathsets)
		verify_solution(solve);
	make_solution_printable(solve.solution, solution);
	delete_bfs(&solve.bfs);
	delete_pathset(&solve.solution);
	return (0);
}
