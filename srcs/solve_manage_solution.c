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


int		make_solution_printable(char  **s, t_pathset *solution)
{

}

void	update_solution(t_solve *solve, t_pathset **cur)
{
	t_pathset	**to_delete;

	if (PATHSET(*cur)->nmoves < solution->nmoves)
	{
		to_delete = solve->solution;
		solution = PATHSET(*cur);
	}
	else
	{
		to_delete = *cur;
		*cur = (*cur)->prev;
	}
	delete_pathset(&to_delete);
}

int		verify_solution(t_solve *solve)
{
	t_list	*cur;

	cur = solve->pathsets;
	while (cur)
	{
		if (update_solution(solve, &PATHSET(cur)) == ERROR)
			return (ERROR);
		cur = cur->next;
	}
}
