/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/26 15:00:46 by rreedy           ###   ########.fr       */
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
	int		tovoid;

	(void)tovoid;
	//run equation on pathset;
}

static void		update_pathset(t_bfs *bfs, t_list *sets)
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
	prev_path->next = ft_lstinit(init_pathset(bfs), 0);
	get_new_delimiter();
	return ;
}

int				update_pathsets(t_bfs *bfs, t_list *pathsets, t_pathset *solution, size_t *delimiter)
{
	t_list	*prev_pathset;

	if (!pathsets)
	{
		pathsets = ft_lstinit(init_pathset(bfs), 0);
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
	prev_pathset->next = ft_lstinit(init_pathset(bfs), 0);
}
