/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_manage_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:20:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 06:21:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant.h"
#include "errors.h"
#include "pathset.h"
#include "solve.h"
#include "ft_list.h"
#include <stddef.h>

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

static void		add_line(char *s, size_t *slen, struct s_ant *ants_on_line, size_t n_ants_on_line)
{
	(void)s;
	(void)slen;
	(void)ants_on_line;
	(void)n_ants_on_line;
//	static size_t	s_len;
//	size_t			i;
//
//	*line_len = 0;
//	i = 0;
//	while (i < n_ants_on_line && ants_on_line[i]->location != 0)
//	{
//		line[i] = L;
//		while ()
//		line[i] = ;
//	}
}

int				make_solution_printable(char **s, size_t *slen, struct s_solve *solve, size_t longest_room_name)
{
	struct s_ant	*ants_on_line;
	size_t			n_ants_on_line;
	size_t			ant_number;
	size_t			s_len;
 
	n_ants_on_line = solve->solution->npaths * solve->solution->paths->path_info->depth_lvl;
	slen = n_ants_on_line *
		(3 + ft_numlen(solve->n_ants) + longest_room_name) * solve->nlines;
	s = ft_strnew(solve->s_len);
	if (!s)
		return (print_error(E_ALLOC_ERROR));
	ant_number = 0;
	setup_ants(&ants_on_line, solve->npaths * solve->depth_level, solution);
	update_ants(&ant_number, &ants_on_line, n_ants_on_line, solution);
	while (ant_number <= solve->n_ants)
	{
		add_line(s, &slen, ants_on_line, n_ants_on_line);
		update_ants(&ant_number, &ants_on_line);
	}
	return (0);
}

void			update_solution(struct s_solve *solve, struct s_pathset **cur)
{
	struct s_pathset	**to_delete;

	if (PATHSET(*cur)->nlines < solution->nlines)
	{
		to_delete = solve->solution;
		solution = PATHSET(*cur);
	}
	else
	{
		to_delete = *cur;
		*cur = (*cur)->prev;
	}
	delete_pathset(to_delete);
}

int				verify_solution(struct s_solve *solve)
{
	struct s_list	*cur;

	cur = solve->pathsets;
	while (cur)
	{
		if (update_solution(solve, &PATHSET(cur)) == ERROR)
			return (ERROR);
		cur = cur->next;
	}
}
