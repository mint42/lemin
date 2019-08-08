/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pathsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:53:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/07 17:05:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	should delimiter be at the shortest or longest check? - longest

		if (sets->base_path != bfs->base_path)
			- no collision from the paths DNI list and the existing paths)
		paths_cur = sets->content->paths;
		while (bfs->paths_to_avoid & paths_cur)
		{
			add to set
		}

static int		add_path_to_sets(t_bfs *bfs, t_list *sets, t_pathset *solution, size_t *delimeter)
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
		compare against pathset, add path if passes 
		set new delimiter
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
