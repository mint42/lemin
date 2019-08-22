/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/21 23:59:48 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	should delimiter be at the shortest or longest check? - longest


static int	compare_path_against_pathset(t_bfs *bfs, t_list *sets, )
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
				return (1);
			++i;
		}
		paths_cur = paths_cur->next;
	}
	return (0);
}

int			add_path_to_sets(t_bfs *bfs, t_list *pathsets, t_pathset *solution, size_t *delimeter)
{
	t_list	*cur;

	if (!pathsets)
	{
		pathsets = init_pathset();
		solution = PATHSET(pathsets);
		return (0);
	}
	cur = pathsets;
	while (pathsets)
	{
		if (compare_path_against_pathset() == NO_CONFLICT)
		{
			add_path_to_set;
			set_new_delimiter;
		}
		if (PATHSET(pathsets).complete)
		{
			if (PATHSET(pathsets).n_lines < solution.n_lines)
			{
				delete_pathset(&solution);
				solution = PATHSET(pathsets);
			}
			else
				delete_pathset(PATHSET(pathsets));
		}
		cur = sets;
		sets = sets->next;
	}
	cur->next = init_pathset();
}
