/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:43:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/29 23:52:10 by rreedy           ###   ########.fr       */
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

static void		make_solution_printable(t_pathset *best, char **solution)
{
	(void)best;
	(void)solution;
}

static int		find_solution(t_bfs *bfs, t_farm *farm, t_pathset *solution)
{
	t_bfs		*cur;
	t_bfs		*tail;
	t_list		*pathsets;
	size_t		delimiter;

	cur = bfs;
	tail = bfs;
	pathsets = 0;
	delimiter = 0;
	if (search(cur, tail, farm, &delimiter) == ERROR)
		return (print_error(NO_SOLUTION));
	if (update_pathsets(cur, pathsets, solution, &delimiter) == ERROR)
		return (1);
	while (pathsets)
	{
		if (search(cur, tail, farm, &delimiter) == ERROR)
			return (1);
		if (update_pathsets(cur, pathsets, solution, &delimiter) == ERROR)
			return (1);
	}
	return (0);
}

int				solve(t_farm *farm, t_bfs *bfs, char **solution)
{
	t_pathset	*best;
	int			error;

	error = 0;
	best = 0;
	if (find_solution(bfs, farm, best) == ERROR)
		error = 1;
	make_solution_printable(best, solution);
	return (error);
}
