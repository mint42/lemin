/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 03:29:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "pathsets.h"
#include "manage_solution.h"
#include "ft_list.h"

static void		update_nlines(t_pathset *pathset)
{
	size_t	ants_on_min_path;
	size_t	ants_on_max_path;

	if (!pathset->nlines)
		pathset->nlines = pathset->minpathlen + farm->ants - 1;
	else
	{
		ants_on_min_path = pathset->nlines - 1;
		ants_on_max_path = 1;
		while (ants_on_min_path > ants_on_max_path && pathset->minpathlen + ants_on_min_path >= pathset->maxpathlen + ants_on_max_path)
		{
			--ants_on_min_path;
			++ants_on_max_path;
		}
		pathset->nlines = ants_on_min_path + 1;
	}
	pathset->min_ants_for_path[npaths] = pathset->nlines;
}

static void		update_pathset(struct s_bfs *bfs_cur, struct s_pathset *set, struct s_farm *farm)
{
	size_t		i;

	while (i < set->npaths)
	{
		if ((bfs_cur->path_info->basepath == set->paths[i]->basepath)
			||
		((bfs_cur->path_info->s_pids_dni > (set->paths)[i]->pid_index) &&
		(bfs_cur->path_info->pids_dni[(set->paths)[i]->pid_index] & (set->paths)[i]->pid_bit)))
			return ;
		++i;
	}
	(pathset->paths)[i] = *bfs_cur;
	pathset->maxpathlen = bfs_cur->depth_level;
	if (!set->minpathlen)
		set->minpathlen = set->maxpathlen;
	++(set->npaths);
	update_nlines(set, farm);
	return ;
}

int				update_pathsets(t_solve *solve, t_farm *farm)
{
	t_list	*cur;
	t_list	*prev_cur;

	if (!solve->sets)
	{
		solve->pathsets = ft_lstinit(init_pathset(), 0);
		solve->solution = PATHSET(solve->pathsets);
		return (0);
	}
	cur = solve->pathsets;
	prev_cur = cur;
	while (cur)
	{
		update_pathset(solve, PATHSET(cur));
		if (PATHSET(cur)->nlines < solve->solution->nlines || PATHSET(cur)->npaths == solve->npaths_delimiter)
			update_solution(solve, &PATHSET(cur));
		else if (PATHSET(cur)->nlines - PATHSET(cur)->maxpathlen > solve->depth_delimiter)
			solve->depth_delimiter = PATHSET(cur)->depth_delimiter;
		prev_cur = cur;
		cur = cur->next;
	}
	prev_cur->next = ft_lstinit(init_pathset(paths), 0);
	return (0);
}
