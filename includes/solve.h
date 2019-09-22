/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:53:48 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/22 03:47:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <stddef.h>

typedef struct s_bfs		t_bfs;
typedef struct s_pathset	t_pathset;
typedef struct s_path		t_path;
typedef struct s_list		t_list;
typedef struct s_basepath	t_basepath;

typedef struct		s_solve
{
	t_bfs			*bfs_head;
	t_bfs			*bfs_cur;
	t_bfs			*bfs_tail;
	t_list			*pathsets;
	t_pathset		*solution;
	t_basepath		*basepaths;
	size_t			nbasepaths;
	size_t			*start_pids;
	size_t			nstart_pids;
	size_t			nbpaths_delimiter;
	size_t			depth_delimiter;
	size_t			max_index_id;
	size_t			max_bit_id;
}					t_solve;

#endif
