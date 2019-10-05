/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:43:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/05 04:48:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basepath.h"
#include "bfs.h"
#include "errors.h"
#include "farm.h"
#include "lemin.h"
#include "manage_solution.h"
#include "path_info.h"
#include "pathset.h"
#include "room.h"
#include "solve.h"
#include <stddef.h>
#include <stdint.h>

static void		mirror_path(struct s_bfs *path)
{
	struct s_bfs			*start;
	struct s_bfs			*end;
	struct s_bfs			*tmp;
	struct s_bfs			*path_prev;
	struct s_bfs			*path_next;
	size_t					rid;
	struct s_path_info		*path_info;

	start = path;
	end = path;
	while (start->path_prev)
		start = start->path_prev;
	while (end->path_next)
		end = end->path_next;
	while (start != end)
	{
		tmp = start;
		start->path_prev = end->prev;
		start->path_next = end->prev;
		end->path_prev = tmp->path_prev;
		end->path_prev = tmp->path_next;

		start = start->path_prev;
		end = end->path_next;
	}
}

static void		reset_path_pointers_to_head(struct s_pathset *solution, struct s_solve *solve)
{
	if ((solve->basepaths)[solution->paths->path_info->basepath_id].origin == END_ROOM)
		;
		mirror_path(solution->paths);
	while (solution->paths)
		solution->paths = solution->paths->prev;
}

static void		overlap_pids_dni(struct s_bfs *end1, struct s_bfs *end2)
{
	size_t			*tmp;
	size_t			i;

	if (end1->path_info->pids_dni_size < end2->path_info->pids_dni_size)
	{
		tmp = end1->path_info->pids_dni;
		end1->path_info->pids_dni = end2->path_info->pids_dni;
		end2->path_info->pids_dni = tmp;
	}
	i = 0;
	while (i < end2->path_info->pids_dni_size)
	{
		end1->path_info->pids_dni[i] = end1->path_info->pids_dni[i] | end2->path_info->pids_dni[i];
		++i;
	}
}

static void		combine_ends(struct s_bfs *end1, uint8_t *path_status)
{
	static struct s_bfs		*end2;
	static size_t	 		depth_level;

	if (!end2)
	{
		end2 = solve->bfs_cur;
		depth_level = end2->path_info->depth_level;
	}
	while (end2->path_info->depth_level >= depth_level)
	{
		if (end2->path_info->depth_level == depth_level &&
			solve->start_pids_size >= end1->path_info->pid_index &&
			solve->start_pids[end1->path_info->pid_index] & end2->path_info->pid_bit)
		{
			end1->path_info->depth_lvl = end1->path_info->depth_lvl * end2->path_info->depth_lvl;
			overlap_pids_dni(end1, end2);
			end2->path_info = end1->path_info;
			return ;
		}
		end2 = end2->prev;
	}
	*path_status = IN_PROGRESS;
	cur = 0;
}

int				solve(struct s_farm *farm, char **solution, size_t *solution_len)
{
	struct s_solve	solve;
	uint8_t			path_status;

	if (setup_solve(&solve, farm) == ERROR)
		return (ERROR);
	path_status = INPROGRESS;
	while (solve.bfs_source && solve.bfs_sink && solve.bfs_cur && (solve.depth_delimiter > 0 || !solve.solution))
	{
		if (path_status == IN_PROGRESS)
		{
			if (process_bfs_node(solve, farm, &path_status) == ERROR)
				return (ERROR);
		}
		if (path_status == COMPLETE)
		{
			combine_path_ends(solve->bfs_cur, &path_status);
			if (process_new_path(&solve, farm) == ERROR)
				return (ERROR);
		}
		else if (path_status == DROPPED)
		{
			delete_bfs_path(solve);
			path_status = IN_PROGRESS;
		}
		else
		{
			++(solve->bfs_cur->path_info->depth_lvl);
			--(solve->depth_delimiter);
			solve->bfs_cur = solve->bfs_cur->next;
		}
	}
	if (!solve.bfs_source || !solve.bfs_sink)
		return (print_error(E_NO_SOLUTION));
	else if (solve.pathsets)
		verify_solution(&solve);
	reset_path_pointers_to_head(solve.solution);
	make_solution_printable(solution, solution_len, &solve, farm->longest_room_name);
	return (0);
}
