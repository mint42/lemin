/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_manage_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:20:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 06:59:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	static void		print_line()
**	{
**		size_t			j;
**	
**		while (j < solve->nmoves)
**		{
**			*s[i] = 'L-';
**			i = i + 2;
**			++j;
**		}
**	}
*/

static void		add_line(char *s, size_t *s_len, struct s_ant *ants_on_line, size_t n_ants_on_line)
{
	static size_t	s_len;
	size_t			i;

	*line_len = 0;
	i = 0;
	while (i < n_ants_on_line && ants_on_line[i]->location != 0)
	{
		line[i] = L;
		while ()
		line[i] = ;
	}
}

int				make_solution_printable(char  **s, t_pathset *solution, t_solve *solve, size_t longest_room_name)
{
	struct s_ant	*ants_on_line;
	size_t			n_ants_on_line;
	size_t			ant_number;
	size_t			s_len;
 
	n_ants_on_line = solve->npaths * solve->depth_level;
	solve->s_len = n_ants_on_line * (3 + ft_numlen(solve->n_ants) + longest_room_name) * solve->nlines;
	solve->s = ft_strnew(solve->s_len);
	if (!line || !s)
		return (print_error(E_ALLOC_ERROR));
	ant_number = 0;
	setup_ants(&ants_on_line, solve->npaths * solve->depth_level, solution);
	update_ants(&ant_number, &ants_on_line, n_ants_on_line, solution);
	while (ant_number <= solve->n_ants)
	{
		add_line(s, &s_len, ants_on_line, n_ants_on_line);
		update_ants(&ant_number, &ants_on_line);
	}
	return (0);
}

void			update_solution(t_solve *solve, t_pathset **cur)
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

int				verify_solution(t_solve *solve)
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
