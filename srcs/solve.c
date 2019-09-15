/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:43:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/15 02:50:49 by rreedy           ###   ########.fr       */
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

#include "ft_printf.h"
static void		make_solution_printable(t_pathset *best, char **solution)
{
	t_list	*paths;
	
	(void)solution;
	paths = best->paths;
	while (paths)
	{
		ft_printf("%5d %5b\n", PATH_ID_INDEX(paths), PATH_ID_BIT(paths));
		paths = paths->next;
	}
}

static int		setup_bfs(t_solve *solve, t_farm *farm)
{
	(solve->bfs) = init_bfs();
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
	if (GRAPH[farm->start_room_id]->nlinks < GRAPH[farm->end_room_id]->nlinks)
		solve->npaths_delimiter = GRAPH[farm->start_room_id]->nlinks;
	else
		solve->npaths_delimiter = GRAPH[farm->end_room_id]->nlinks;
	return (bfs);
}

int				solve(t_farm *farm, char **solution)
{
	t_solve		*solve;
	t_bfs		*cur;
	t_bfs		*tail;

	init_solve(&solve);
	setup_bfs(solve, farm);
	cur = solve->bfs;
	tail = (solve->bfs)->next;
	while (solve->sets && solve->depth_delimiter)
	{
		if (run_bfs(cur, tail, farm, &solve->depth_delimiter) == ERROR)
			return (ERROR);
		if (update_pathsets(farm, cur, solve) == ERROR)
			return (ERROR);
	}
	make_solution_printable(solve.solution, solution);
	delete_bfs(&solve.bfs);
	ft_lstdel(&solve.pathsets, delete_pathset);
	return (error);
}
