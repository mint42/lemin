/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:53:48 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/15 02:30:56 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <stddef.h>

typedef struct s_bfs		t_bfs;

typedef struct	s_solve
{
	t_bfs		*bfs;
	t_list		*pathsets;
	t_pathset	*solution;
	size_t		npath_delimiter;
	size_t		depth_delimiter;
	size_t		max_array_index;
	size_t		max_bit_index;
	size_t		nbase_paths;
}				t_solve;

#endif
