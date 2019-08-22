/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/22 15:07:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	should delimiter be at the shortest or longest check? - longest

static void		update_solution(t_bfs *bfs, t_pathset *pathset)
{
	if (PATHSET(pathsets).n_lines < solution.n_lines)
	{
		cur->next = pathsets->next;
		delete_pathset(&solution);
		solution = PATHSET(pathsets);
	}
	else
	{
		cur->next = pathsets->next;
		delete_pathset(&PATHSET(pathsets));
	}
}

static int		look_for_path_conflicts(t_bfs *bfs, t_list *sets)
{
	t_list		*paths_cur;
	size_t		i;

	if (PATHSET(sets)->base_path != bfs->base_path)
		return (1);
	paths_cur = PATHSET(sets)->paths;
	while (paths_cur)
	{
		i = 0;
		while (i < bfs->n_paths_to_avoid)
		{
			if (bfs->paths_to_avoid[i] & paths_cur)
				return (CONFLICT);
			++i;
		}
		paths_cur = paths_cur->next;
	}
	return (NO_CONFLICT);
}

int				update_pathsets(t_bfs *bfs, t_list *pathsets, t_pathset *solution, size_t *delimiter)
{
	t_list	*prev_pathset;

	if (!pathsets)
	{
		pathsets = init_pathset();
		solution = PATHSET(pathsets);
		return (0);
	}
	prev_pathset = pathsets;
	while (pathsets)
	{
		if (look_for_path_conflicts(bfs, PATHSET(pathsets)) == NO_CONFLICT)
		{
			add_path_to_set;
			set_new_delimiter;
			if (PATHSET(pathsets).delimiter > *delimiter)
				*delimeter = PATHSET(pathsets).delimiter;
		}
		if (PATHSET(pathsets).complete)
			update_solution();
		prev_pathset = pathsets;
		pathsets = pathsets->next;
	}
	prev_pathset->next = init_pathset();
}
