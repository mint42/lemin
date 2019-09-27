/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:43:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/26 21:46:05 by rreedy           ###   ########.fr       */
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

static int		setup_bfs(t_solve *solve, t_farm *farm)
{
	if (init_bfs(solve->bfs) == ERROR)
		return (ERROR);
	(solve->bfs)->start_or_end_path = 1;
	(solve->bfs)->path_id_index = 0;
	(solve->bfs)->path_id_bit = 1;
	(solve->bfs)->room_id = farm->start_room_id;
	(solve->bfs)->next = init_bfs();
	(solve->bfs)->next->prev = bfs;
	(solve->bfs)->next->next = 0;
	(solve->bfs)->next->start_or_end_path = 1;
	(solve->bfs)->next->path_id_bit = 2;
	(solve->bfs)->next->room_id = farm->end_room_id;
	return (0);
}

static int		setup_basepaths(t_solve *solve, t_farm *farm)
{
	size_t	i;

	solve->basepaths = (size_t *)ft_memalloc(sizeof(size_t) * solve->nbasepaths);
	if (!solve->basepaths)
		return (print_error(E_ALLOC_ERROR));
	i = 0;
	while (i < (farm->graph)[farm->start_rid]->nlinks)
	{
		init_basepath(solve->basepaths[i]);
		(solve->basepaths)->mpaths_in_base = SQUARE(solve->npaths_delimiter) / NBITS_SIZE_T;
		(solve->basepaths)[i]->origin = START;
		(solve->basepaths)[i]->npaths = (farm->rooms)[farm->start_rid]->nlinks;
		++i;
		(solve_basepaths)[i]->basepath_id = i;
		(solve_startpaths)[i / 64] = (solve_startpaths)[i / 64] & (1 << i % 64);
	}
	while (i < solve->nbasepaths)
	{
		init_basepath(solve->basepaths[i]);
		(solve->basepaths)->mpaths_in_base = SQUARE(solve->npaths_delimiter) / NBITS_SIZE_T;
		(solve->basepaths)[i]->origin = END;
		(solve->basepaths)[i]->npaths = (farm->graph)[farm->end_rid]->nlinks;
		++i;
		(solve_basepaths)[i]->basepath_id = i;
	}
}

static int		setup_solve(t_solve *solve, t_farm *farm)
{
	solve->bfs_head = 0;
	solve->bfs_cur = 0;
	solve->bfs_tail = 0;
	solve->pathsets = 0;
	solve->solution = 0;
	solve->basepaths = 0;
	solve->depth_delimiter = 0;
	solve->max_index_id = 1;
	solve->max_bit_id = 1;
	solve->nbasepaths = (farm->graph)[farm->start_rid]->nlinks + (farm->graph)[farm->end_rid]->nlinks;
	solve->start_pids = (size_t *)ft_memalloc(sizeof(size_t));
	if (!solve->start_pids)
		return (print_error(E_ALLOC_ERROR));
	solve->nstart_pids = 1;
	solve->start_pids = START;
	if ((farm->graph)[farm->start_rid]->nlinks < (farm->rooms)[farm->end_rid]->nlinks)
		solve->npaths_delimiter = (farm->graph)[farm->start_rid]->nlinks;
	else
		solve->npaths_delimiter = (farm->graph)[farm->end_rid]->nlinks;
	setup_basepaths(*solve);
	setup_bfs(solve);
	solve->bfs_cur = solve->bfs;
	solve->bfs_tail = (solve-bfs)->next;
	return (bfs);
}


static int		combine_ends(t_bfs *end_1, t_bfs *end_2, uint8_t *path_status)
{
	t_bfs	*end_1;
	t_bfs	*end_2;
	
	cur = solve->cur_bfs;
	while (cur && )
	{
		check only while the depth level is the same;
		go backwards;
		do a check on all paths from start to see when a collision happens
			thats how you'll know which node to connect to
		do i need to copy over something dni lists, probs
		update depth_level to be double the fun

	
		cur = cur->prev;
	}
}


int				solve(t_farm *farm, char **solution)
{
	t_solve		solve;
	uint8_t		path_status;

	solve = 0;
	path_status = IN_PROGRESS;
	if (solve_setup(&solve, farm) == ERROR)
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
		verify_solution();
	make_solution_printable(solve.solution, solution);
	delete_bfs(&solve.bfs);
	delete_pathset(&solve.solution);
	return (error);
}
