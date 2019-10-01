/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_manage_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:20:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/01 03:55:48 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		print_line()
{
	size_t			j;

	while (j < solve->nmoves)
	{
		*s[i] = 'L-';
		i = i + 2;
		++j;
	}

}

	print->ant_number = 0;
	print->location = 0;

int		print_solution(char  **s, t_pathset *solution, t_solve *solve)
{
	struct s_print	*print; 
	struct s_lemin_output	*print; 
	size_t			i;
	size_t			start;

	print = 0;
	set_pointers_to_head();
	if (init_print(&print, solve->npaths_delimiter * solution->depth_level) == ERROR)
		return (ERROR);
	i = 1;
	while (i <= ants)
	{
		print_line(print);
		update(&i);
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
