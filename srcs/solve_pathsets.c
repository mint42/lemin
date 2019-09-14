/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/14 16:21:27 by rreedy           ###   ########.fr       */
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
	pathset->delimiter = pathset->nmoves - pathset->maxpathlen;
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

int				update_pathsets(t_farm *farm, t_bfs *paths, t_list *sets, t_pathset *solution, size_t *depth_delimiter, size_t *npaths_delimiter)
{
	t_list	*prev_pathset;

	if (!sets)
	{
		sets = ft_lstinit(init_pathset(paths), 0);
		solution = PATHSET(sets);
		return (0);
	}
	prev_pathset = sets;
	while (sets)
	{
		update_pathset(paths, PATHSET(sets), farm);
		if (PATHSET(sets)->nmoves - PATHSET(sets)->maxpathlen <= 0 ||
			PATHSET(sets)->npaths == npaths_delimiter)
			update_solution(solution, sets);
		if (PATHSET(sets)->moves - PATHSET(sets)->maxpathlen > *depth_delimiter)
			*delimiter = PATHSET(sets)->delimiter;
		if (PATHSET(sets)->completed)
			update_solution(solution, sets);
		prev_pathset = sets;
		sets = sets->next;
	}
	prev_pathset->next = ft_lstinit(init_pathset(paths), 0);
	return (0);
}
