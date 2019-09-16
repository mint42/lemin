/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/16 16:20:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "pathsets.h"
#include "ft_list.h"

/*
** 	should delimiter be at the shortest or longest check? - longest
*/

static void		update_solution(t_bfs *bfs, t_list *sets, t_pathset *solution)
{
	t_pathset	*cur;

	if (PATHSET(sets)->nmoves < solution->nmoves)
	{
		solution = PATHSET(sets);
		cur->next = sets->next;
		delete_pathset(&solution);
	}
	else
	{
		cur->next = sets->next;
		delete_pathset(&PATHSET(sets));
	}
}

static void		update_nmoves(t_pathset *pathset, t_farm *farm)
{
	size_t	ants_on_min_path;
	size_t	ants_on_max_path;

	if (!pathset->nmoves)
		pathset->nmoves = pathset->minpathlen + farm->ants - 1;
	else
	{
		ants_on_min_path = pathset->nmoves - 1;
		ants_on_max_path = 1;
		while (ants_on_min_path > ants_on_max_path &&
				pathset->minpathlen + ants_on_min_path >= pathset->maxpathlen + ants_on_max_path)
		{
			--ants_on_min_path;
			++ants_on_max_path;
		}
		pathset->nmoves = ants_on_min_path + 1;
	}
}

static void		update_pathset(t_bfs *new_path, t_pathset *pathset, t_farm *farm)
{
	t_list		*paths_cur;
	t_list		*prev_path;

	paths_cur = pathset->paths;
	while (paths_cur)
	{
		if (new_path->base_path != PATH(paths_cur)->base_path)
			return ;
		if ((new_path->npaths_to_avoid - 1 >= PATH_ID_INDEX(paths_cur)) &&
				(new_path->paths_to_avoid[PATH_ID_INDEX(paths_cur)]
			 	& PATH_ID_BIT(paths_cur)))
			return ;
		prev_path = paths_cur;
		paths_cur = paths_cur->next;
	}
	prev_path->next = ft_lstinit(init_pathset(new_path), 0);
	if (!pathset->minpathlen)
		pathset->minpathlen = new_path->depth_level;
	++(pathset->npaths);
	pathset->maxpathlen = new_path->depth_level;
	update_nmoves(pathset, farm);
	return ;
}

pathsets will now have a variable that is a pointer to all of the paths that it cannot interract with
shoudl i add back in base paths? i guess that would be nice for if comparing

int				update_pathsets(t_farm *farm, t_bfs *paths, t_solve *solve)
{
	t_list	*cur_pathset;
	t_list	*prev_pathset;

	cur_pathsets = solve->sets;
	if (!solve->sets)
	{
		solve->sets = ft_lstinit(init_pathset(paths), 0);
		solve->solution = PATHSET(solve->sets);
		return (0);
	}
	prev_pathset = sets;
	while (cur_pathsets)
	{
		update_pathset(paths, PATHSET(cur_pathsets), farm);
		if (PATHSET(cur_pathsets)->nmoves - PATHSET(cur_pathsets)->maxpathlen <= 0 ||
			PATHSET(cur_pathsets)->npaths == npaths_delimiter)
			update_solution(solution, solve->sets);
		if (PATHSET(cur_pathsets)->moves - PATHSET(cur_pathsets)->maxpathlen > solve->depth_delimiter)
			solve->depth_delimiter = PATHSET(cur_pathsets)->delimiter;
		if (PATHSET(cur_pathsets)->completed)
			update_solution(solve->solution, cur_pathsets);
		prev_pathset = sets;
		sets = sets->next;
	}
	prev_pathset->next = ft_lstinit(init_pathset(paths), 0);
	return (0);
}
