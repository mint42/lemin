/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/30 14:25:20 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "pathsets.h"
#include "ft_list.h"

//	should delimiter be at the shortest or longest check? - longest

/*
**	static void		update_solution(t_bfs *bfs, t_list *sets, t_pathset *solution)
**	{
**		t_pathset	*cur;
**	
**		if (PATHSET(sets)->nmoves < solution->nmoves)
**		{
**			solution = PATHSET(sets);
**			cur->next = sets->next;
**			delete_pathset(&solution);
**		}
**		else
**		{
**			cur->next = sets->next;
**			delete_pathset(&PATHSET(sets));
**		}
**	}
*/

static void		get_new_delimiter()
{
	int		tovoid;

	(void)tovoid;
	//run equation on pathset;
}

static void		update_pathset(t_bfs *bfs, t_list *sets)
{
	t_list		*paths_cur;
	t_list		*prev_path;
	size_t		i;

	if (PATH(sets, sets->paths)->base_path != bfs->base_path)
		return ;
	paths_cur = PATHSET(sets)->paths;
	while (paths_cur)
	{
		i = 0;
		while (i < bfs->n_paths_to_avoid)
		{
			if (bfs->paths_to_avoid[i] & paths_cur)
				return ;
			++i;
		}
		prev_path = paths_cur;
		paths_cur = paths_cur->next;
	}
	prev_path->next = ft_lstinit(init_pathset(bfs), 0);
	get_new_delimiter();
	return ;
}

int				update_pathsets(t_bfs *bfs, t_list *sets, t_pathset *solution, size_t *delimiter)
{
	t_list	*prev_pathset;

	if (!sets)
	{
		sets = ft_lstinit(init_pathset(bfs), 0);
		solution = PATHSET(sets);
		return (0);
	}
	prev_pathset = sets;
	while (sets)
	{
		update_pathset(bfs, PATHSET(sets));
		if (PATHSET(sets)->delimiter > *delimiter)
			*delimiter = PATHSET(sets)->delimiter;
		if (PATHSET(sets)->completed)
			solution = PATHSET(sets);
		prev_pathset = sets;
		sets = sets->next;
	}
	prev_pathset->next = ft_lstinit(init_pathset(bfs), 0);
}
