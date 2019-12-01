/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_pathets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:24:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 20:41:26 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "manage_solution.h"
#include "struct_bfs_node.h"
#include "struct_pathinfo.h"
#include "struct_farm.h"
#include "struct_pathset.h"
#include "struct_solve.h"
#include "ft_list.h"

static void		update_nlines(struct s_pathset *pathset, size_t	nants)
{
	size_t	ants_on_min_path;
	size_t	ants_on_max_path;

	if (!pathset->nlines)
		pathset->nlines = pathset->minpathlen + nants - 1;
	else
	{
		ants_on_min_path = pathset->nlines - 1;
		ants_on_max_path = 1;
		while (ants_on_min_path > ants_on_max_path &&
				pathset->minpathlen + ants_on_min_path >=
				pathset->maxpathlen + ants_on_max_path)
		{
			--ants_on_min_path;
			++ants_on_max_path;
		}
		pathset->nlines = ants_on_min_path + 1;
	}
	pathset->min_ant_for_path[pathset->npaths - 1] = pathset->nlines;
}

static void		update_pathset(struct s_pathset *set, struct s_bfs_node *bfs_cur,
						struct s_farm *farm)
{
	size_t		i;

	i = 0;
	while (i < set->npaths)
	{
		if ((bfs_cur->pathinfo->basenode_id == set->paths[i].pathinfo->basenode_id)
				||
				((bfs_cur->pathinfo->pids_dni->size > (set->paths)[i].pathinfo->pid_index) &&
				(bfs_cur->pathinfo->pids_dni->pids[(set->paths)[i].pathinfo->pid_index] &
				(set->paths)[i].pathinfo->pid_bit)))
			return ;
		++i;
	}
	ft_lstadd((void *)*bfs_cur);
	set->maxpathlen = bfs_cur->pathinfo->depth_lvl;
	if (!set->minpathlen)
		set->minpathlen = set->maxpathlen;
	++(set->npaths);
	update_nlines(set, farm->nants);
	return ;
}

/*
**	TODO: check how giving new pathset of its own at the end
**	TODO: xor list on bfs but maybe pathsets too
**	TODO: or turn pathsets into a dynamic array, but a list could work too, there is no need to index it
**	TODO: if things need reallocated then it should probably be a pointer to the content for quicker transfer
**	TODO: setup ctags
*/

int				update_pathsets(struct s_solve *solve, struct s_farm *farm)
{
	struct s_pathset	*new_pathset;
	struct s_list		*cur;
	struct s_list		*prev_cur;

	if (!solve->pathsets)
	{
		if (init_pathset(&new_pathset) == ERROR)
			return (ERROR);
		solve->pathsets = ft_lstinit(new_pathset, 0);
		solve->solution = PATHSET(solve->pathsets);
		return (SUCCESS);
	}
	cur = solve->pathsets;
	prev_cur = cur;
	while (cur)
	{
		update_pathset(PATHSET(cur), solve->bfs_cur, farm);
		if (PATHSET(cur)->nlines < solve->solution->nlines || PATHSET(cur)->npaths == solve->npaths_delimiter)
			update_solution(solve, prev_cur);
		else if (PATHSET(cur)->nlines - PATHSET(cur)->maxpathlen > solve->depth_delimiter)
			solve->depth_delimiter = PATHSET(cur)->nlines - PATHSET(cur)->maxpathlen;
		prev_cur = cur;
		cur = cur->next;
	}
	if (init_pathset(&new_pathset) == ERROR)
		return (ERROR);
	prev_cur->next = ft_lstinit(new_pathset, 0);
	return (0);
}
