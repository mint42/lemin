/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:53:48 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 05:40:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <stddef.h>

struct					s_basepath;
struct					s_bfs;
struct					s_farm;
struct					s_list;
struct					s_pathset;
struct					s_solve;

struct					s_solve
{
	struct s_bfs		*bfs_head;
	struct s_bfs		*bfs_cur;
	struct s_bfs		*bfs_tail;
	struct s_list		*pathsets;
	struct s_pathset	*solution;
	struct s_basepath	*basepaths;
	size_t				s_basepaths;
	size_t				*start_pids;
	size_t				start_pids_size;
	size_t				start_pids_len;
	size_t				npaths_delimiter;
	size_t				depth_delimiter;
	size_t				max_pid_index;
	size_t				max_pid_bit;
};

int						setup_solve(struct s_solve *solve, struct s_farm *farm);

#endif
