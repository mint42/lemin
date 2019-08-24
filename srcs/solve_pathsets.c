/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/23 20:35:31 by rreedy           ###   ########.fr       */
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

static void		get_new_delimiter()
{
	run equation on pathset;
}

static void		look_for_path_conflicts(t_bfs *bfs, t_list *sets)
{
	t_list		*paths_cur;
	t_list		*prev_path;
	size_t		i;

	if (PATHSET(sets)->base_path != bfs->base_path)
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
	prev_path->next = init_new_path();
	get_new_delimiter();
	return ;
}

int				update_pathsets(t_bfs *bfs, t_list *pathsets,
					t_pathset *solution, size_t *delimiter)
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
		update_pathset(bfs, PATHSET(pathsets));
		if (PATHSET(pathsets).delimiter > *delimiter)
			*delimeter = PATHSET(pathsets).delimiter;
		if (PATHSET(pathsets).complete)
			update_solution(bfs, pathsets, prev_pathset);
		prev_pathset = pathsets;
		pathsets = pathsets->next;
	}
	prev_pathset->next = init_pathset();
}
