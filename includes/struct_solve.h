/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_solve.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:19:25 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 06:27:37 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SOLVE_H
# define STRUCT_SOLVE_H

#include <stddef.h>

struct					s_bfs;
struct					s_farm;
struct					s_list;
struct					s_base_node;
struct					s_path_set;
struct					s_path_ids;
struct					s_solve;

/*
**	s_solve is a struct storing information about the lemin algorithm
**
**	bfs_head			pointer to the head node of the breadth first search
**	bfs_tail			pointer to the tail node of the breadth first search
**	bfs_cur				pointer to the node of the breadth first search
**						currently
**						being explored
**	pathsets			path sets of possible solutions
**	solution			current best solution
**	basenodes			Array of nodes stemming directly from either source or
**						sink
**	nbasenodes			Number of base nodes
**	npaths_delimiter	The number of paths found that would cause the algorithm
**						to not need to search any further
**	depth_delimiter		The depth level searched that would cause the algorithm
**						to not need to search any further
**	max_pid_index		Index of the current largest Path ID
**	max_pid_bit			Bit representing the current largest Path ID
*/

struct					s_solve
{
	struct s_bfs		*bfs_head;
	struct s_bfs		*bfs_cur;
	struct s_bfs		*bfs_tail;
	struct s_list		*pathsets;
	struct s_base_node	*basenodes;
	struct s_path_ids	start_pids;
	struct s_path_set	*solution;
	size_t				nbasenodes;
	size_t				npaths_delimiter;
	size_t				depth_delimiter;
	size_t				max_pid_index;
	size_t				max_pid_bit;
};

int						setup_solve(struct s_solve *solve, struct s_farm *farm);

#endif
