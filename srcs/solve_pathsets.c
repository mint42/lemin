/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/01 02:59:40 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "pathsets.h"
#include "manage_solution.h"
#include "ft_list.h"

static void		update_nmoves(t_pathset *pathset)
{
	size_t	ants_on_min_path;
	size_t	ants_on_max_path;

	if (!pathset->nmoves)
		pathset->nmoves = pathset->minpathlen + farm->ants - 1;
	else
	{
		ants_on_min_path = pathset->nmoves - 1;
		ants_on_max_path = 1;
		while (ants_on_min_path > ants_on_max_path && pathset->minpathlen + ants_on_min_path >= pathset->maxpathlen + ants_on_max_path)
		{
			--ants_on_min_path;
			++ants_on_max_path;
		}
		pathset->nmoves = ants_on_min_path + 1;
	}
	pathset->min_ants_for_path[npaths] = pathset->nmoves;
}

static void		update_pathset(t_solve *solve, t_pathset *pathset)
{
	t_list		*cur;
	t_list		*prev_cur;

	cur = pathset->paths;
	prev_cur = cur;
	while (cur)
	{
			if ((solve->bfs_cur->path_info->basepath == PATH(cur)->basepath)
				||
			((solve->bfs_cur->s_pids_dni > PID_INDEX(cur)) &&
			(solve->bfs_cur->pids_dni[PID_INDEX(cur)] & PID_BIT(cur))))
			return ;
		prev_cur = cur;
		cur = cur->next;
	}
	prev_cur->next = ft_lstinit(solve->bfs_cur->path_info, 0);
	pathset->maxpathlen = solve->bfs_cur->depth_level;
	if (!pathset->minpathlen)
		pathset->minpathlen = pathset->maxpathlen;
	++(pathset->npaths);
	update_nmoves(pathset, farm);
	return ;
}

int				update_pathsets(t_solve *solve, t_farm *farm)
{
	t_list	*cur;
	t_list	*prev_cur;

	if (!solve->sets)
	{
		solve->sets = ft_lstinit(init_pathset(), 0);
		solve->solution = PATHSET(solve->sets);
		return (0);
	}
	cur = solve->sets;
	prev_cur = cur;
	while (cur)
	{
		update_pathset(paths, PATHSET(cur), farm);
		if (PATHSET(cur)->nmoves < solve->solution->nmoves || PATHSET(cur)->npaths == solve->npaths_delimiter)
			update_solution(solve, &PATHSET(cur));
		else if (PATHSET(cur)->nmoves - PATHSET(cur)->maxpathlen > solve->depth_delimiter)
			solve->depth_delimiter = PATHSET(cur)->depth_delimiter;
		prev_cur = cur;
		cur = cur->next;
	}
	prev_cur->next = ft_lstinit(init_pathset(paths), 0);
	return (0);
}
