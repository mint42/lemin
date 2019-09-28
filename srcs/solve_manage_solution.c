/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_manage_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:20:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/28 02:21:05 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		update_solution(t_bfs *bfs, t_list *sets, t_pathset *solution)
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

int		verify_solution(t_solve *solve, t_farm *farm)
{
	t_list	*cur;
	
	cur = pathsets;
	while (cur)
	{
		if (PATHSET(cur)->nmoves > solve->solution->nmoves)
			if (update_solution() == ERROR)
				return (ERROR);
		cur = cur->next;
	}
}
