/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:05:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/12 13:13:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			bfs(t_bfs *cur, t_bfs *tail, t_farm *farm, size_t *delimiter)
{
	size_t		nlinks;
	size_t		level;
	
	level = 0;
	while (level < delimiter)
	{
		nlinks = 0;
		while (nlinks < (farm->graph[cur->room_id])->nlinks)
		{
			if (*((farm->graph[cur->room_id])->paths_crossed) != cur->room_id)
				new_bfs_node();
			++nlinks;
		}
		if (cur->next->depth_level > cur->depth_level)
			++level;
		cur = cur->next;
	}
}
