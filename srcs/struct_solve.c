/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 02:49:43 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 02:51:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_solve.h"

static int		init_solve(struct s_ *solve)
{
	solve->bfs_head = 0;
	solve->bfs_cur = 0;
	solve->bfs_tail = 0;
	solve->pathsets = 0;
	solve->solution = 0;
	solve->basepaths = 0;
	solve->s_basepaths = 0;
	solve->*start_pids = 0;
	solve->s_start_pids = 0;
	solve->depth_delimiter = 0;
	solve->npaths_delimiter = 0;
	solve->max_index_id = 0;
	solve->max_bit_id = 0;
}

int				setup_solve(struct s_solve *solve, struct s_farm *farm)
{
	init_solve(&solve);
	solve->max_index_id = 1;
	solve->max_bit_id = 1;
	solve->nbasepaths = (farm->graph)[farm->start_rid]->nlinks + (farm->graph)[farm->end_rid]->nlinks;
	solve->start_pids = (size_t *)ft_memalloc(sizeof(size_t));
	if (!solve->start_pids)
		return (print_error(E_ALLOC_ERROR));
	solve->s_start_pids = 1;
	solve->start_pids = START;
	if ((farm->graph)[farm->start_rid]->nlinks < (farm->rooms)[farm->end_rid]->nlinks)
		solve->npaths_delimiter = (farm->graph)[farm->start_rid]->nlinks;
	else
		solve->npaths_delimiter = (farm->graph)[farm->end_rid]->nlinks;
	setup_basepaths(*solve);
	setup_bfs(solve);
	solve->bfs_cur = solve->bfs;
	solve->bfs_tail = (solve-bfs)->next;
	return (0);
}
