/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 02:49:43 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/15 02:50:10 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

static int		init_solve(t_solve *solve)
{
	solve->bfs = 0;
	solve->pathsets = 0;
	solve->solution = 0;
	solve->npath_delimiter = 0;
	solve->depth_delimiter = 0;
	solve->max_array_id = 0;
	solve->max_bit_id = 0;
	solve->nbase_paths = 0;
}
