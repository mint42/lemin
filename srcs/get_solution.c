/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:43:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 20:14:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "lemin.h"
#include "manage_solution.h"
#include "queue_bfs.h"
#include "linked_list_pathsets.h"
#include "struct_bfs_node.h"
#include "struct_basenode.h"
#include "struct_farm.h"
#include "struct_pathinfo.h"
#include "struct_pathset.h"
#include "struct_pathids.h"
#include "struct_room.h"
#include "struct_solve.h"
#include <stddef.h>
#include <stdint.h>

static void		mirror_path(struct s_bfs_node *path)
{
	struct s_bfs_node		*start;
	struct s_bfs_node		*end;
	struct s_bfs_node		*tmp;
	struct s_bfs_node		*path_prev;
	struct s_bfs_node		*path_next;
	size_t					rid;
	struct s_pathinfo		*pathinfo;

	(void)start;
	(void)end;
	(void)tmp;
	(void)path_prev;
	(void)path_next;
	(void)rid;
	(void)pathinfo;
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

static void		reset_path_pointers_to_head(struct s_solve *solve)
{
	if ((solve->basenodes)[solve->solution->paths->pathinfo->basenode_id].origin == END_ROOM)
		;
		mirror_path(solve->solution->paths);
	while (solve->solution->paths)
		solve->solution->paths = solve->solution->paths->prev;
}

static void		overlap_pids_dni(struct s_bfs_node *end1,
						struct s_bfs_node *end2)
{
	size_t			*tmp;
	size_t			i;

	if (end1->pathinfo->pids_dni->size < end2->pathinfo->pids_dni->size)
	{
		tmp = end1->pathinfo->pids_dni->pids;
		end1->pathinfo->pids_dni->pids = end2->pathinfo->pids_dni->pids;
		end2->pathinfo->pids_dni->pids = tmp;
	}
	i = 0;
	while (i < end2->pathinfo->pids_dni->size)
	{
		end1->pathinfo->pids_dni->pids[i] = end1->pathinfo->pids_dni->pids[i] | end2->pathinfo->pids_dni->pids[i];
		++i;
	}
}

static void		combine_path_ends(struct s_solve *solve, uint8_t *path_status)
{
	static struct s_bfs_node	*end2;
	static size_t	 			depth_level;

	if (!end2)
	{
		end2 = solve->bfs_cur;
		depth_level = end2->pathinfo->depth_lvl;
	}
	while (end2->pathinfo->depth_lvl >= depth_level)
	{
		if (end2->pathinfo->depth_lvl == depth_level &&
			solve->start_pids->size >= solve->bfs_cur->pathinfo->pid_index &&
			solve->start_pids->pids[solve->bfs_cur->pathinfo->pid_index] & end2->pathinfo->pid_bit)
		{
			solve->bfs_cur->pathinfo->depth_lvl = solve->bfs_cur->pathinfo->depth_lvl * end2->pathinfo->depth_lvl;
			overlap_pids_dni(solve->bfs_cur, end2);
			end2->pathinfo = solve->bfs_cur->pathinfo;
			return ;
		}
		end2 = end2->prev;
	}
	*path_status = IN_PROGRESS;
}

int				get_solution(struct s_farm *farm, char **solution, size_t *solution_len)
{
	struct s_solve	solve;
	uint8_t			path_status;

	if (setup_solve(&solve, farm) == ERROR)
		return (ERROR);
	path_status = IN_PROGRESS;
	// gotta link new source and sink variables in setup
	while (solve.bfs_source && solve.bfs_sink && solve.bfs_cur && (solve.depth_delimiter > 0 || !solve.solution))
	{
		if (path_status == IN_PROGRESS)
		{
			if (update_bfs_queue(&solve, farm, &path_status) == ERROR)
				return (ERROR);
		}
		if (path_status == COMPLETE)
		{
			combine_path_ends(&solve, &path_status);
			if (update_pathsets(&solve, farm) == ERROR)
				return (ERROR);
		}
		else if (path_status == DROPPED)
		{
			delete_bfs_path(&solve);
			path_status = IN_PROGRESS;
		}
		else
		{
			++(solve.bfs_cur->pathinfo->depth_lvl);
			--(solve.depth_delimiter);
			solve.bfs_cur = solve.bfs_cur->next;
		}
	}
	if (!solve.bfs_source || !solve.bfs_sink)
		return (print_error(E_NO_SOLUTION));
	else if (solve.pathsets)
		verify_solution(&solve);
	reset_path_pointers_to_head(&solve);
	make_solution_printable(solution, solution_len, &solve, farm);
	return (0);
}
