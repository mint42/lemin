/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_manage_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:20:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/29 06:23:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		make_solution_printable(char  **s, t_pathset *solution, t_solve *solve)
{
	size_t	i;
	size_t	j;
	size_t	ant;

	*s = ((ft_numlen(solve->ants + 3) * solution->npaths) + 1) * solution->nmoves;
	if (!*s)
		return (print_error(E_ALLOC_ERROR));
	i = 0;
	j = 0;
	while (j < solve->nmoves)
	{
		*s[i] = 'L-';
		i = i + 2;
		
		++j;
	}
	
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
