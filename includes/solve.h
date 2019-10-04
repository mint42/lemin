/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:53:48 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 22:31:09 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <stddef.h>

struct s_solve
{
	struct s_bfs		*bfs_head;
	struct s_bfs		*bfs_cur;
	struct s_bfs		*bfs_tail;
	struct s_list		*pathsets;
	struct s_pathset	*solution;
	struct s_basepath	*basepaths;
	size_t				s_basepaths;
	size_t				*start_pids;
	size_t				s_start_pids;
	size_t				npaths_delimiter;
	size_t				depth_delimiter;
	size_t				max_index_id;
	size_t				max_bit_id;
};

int		setup_solve(struct s_solve *solve, struct s_farm *farm);

#endif
