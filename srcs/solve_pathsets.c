/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/17 00:45:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	should delimiter be at the shortest or longest check? - longest


static int	compare_against_pathset(t_bfs *bfs, t_list *sets, )
{
	t_list		*sets_cur;
	t_list		*paths_cur;
	size_t		i;

	if (sets->base_path != bfs->base_path)
		return (0);
	sets_cur = sets;
	paths_cur = sets->content->paths;
	while (sets_cur)
	{
		while (paths_cur)
		{
			i = 0;
			while (i < bfs->n_paths_to_avoid)
			{
				if (bfs->paths_to_avoid[i] & paths_cur set thing)
					break ;
				++i;
			}
			add_to_set;
			paths_cur = paths_cur->next;
		}
		sets_cur = sets_cur->next;
	}
	add_to_own_set;
}

int			add_path_to_sets(t_bfs *bfs, t_list *sets, t_pathset *solution, size_t *delimeter)
{
	t_bfs	*bfs_cur;

	if (!sets)
	{
		sets = init_pathset();
		solution = sets;
		return (0);
	}
	bfs_cur = 0;
	while (sets)
	{
		if (compare_against_pathset)
		{
			add path to set
			set new delimiter
		}
		if (pathset is now complete (when the == complete variable))
		{
			- compare against solution
			- ++sets
			- continue
		}
		cur = sets;
		++sets;
	}
	cur->next = init_pathset();
}
