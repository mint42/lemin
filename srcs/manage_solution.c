/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_manage_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 02:20:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 20:24:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_ant.h"
#include "struct_bfs_node.h"
#include "struct_pathinfo.h"
#include "struct_pathset.h"
#include "struct_farm.h"
#include "struct_solve.h"
#include "ft_str.h"
#include "ft_utils.h"
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

/*
**	TODO: learn to make shortcut for comments
**	TODO: make variables to shorten these long struct accesses
**	TODO: maybe make a libft dynamic array struct, and maybe a void array manager
*/

int				make_solution_printable(char **s, size_t *slen,
						struct s_solve *solve, struct s_farm *farm)
{
	//is this an array ? dont think so
	struct s_ant	ants_on_line;
	size_t			n_ants_on_line;
	size_t			ant_number;
	size_t			s_len;
 
	n_ants_on_line = solve->solution->npaths * solve->solution->paths->pathinfo->depth_lvl;
	slen = n_ants_on_line *
		(3 + ft_numlen(farm->nants) + farm->longest_room_name) * solve->solution->paths->nlines;
	*s = ft_strnew(*slen);
	if (!s)
		return (print_error(E_ALLOC));
	ant_number = 0;
	setup_ants(&ants_on_line, solve->solution->npaths * solve->solution->paths->pathinfo->depth_lvl, solve->solution);
	update_ants(&ant_number, &ants_on_line, n_ants_on_line, solve->solution);
	while (ant_number <= farm->nants)
	{
		add_line(*s, slen, &ants_on_line, n_ants_on_line);
		update_ants(&ant_number, &ants_on_line, n_ants_on_line, solve->solution);
	}
	return (0);
}

/*
**	TODO: fix delete pathset function and implement xor list so i dont have to pass around prev pointers
**	TODO: paths are not a linked list and probably should be
*/

void			update_solution(struct s_solve *solve, t_list *pathset)
{
	struct s_pathset	**to_delete;

	if (PATHSET(pathset->next)->nlines < solve->solution->nlines)
	{
		to_delete = &(solve->solution);
		solve->solution = PATHSET(pathset->next);
	}
	else
	{
		to_delete = &PATHSET(pathset->next);
		pathset->next = pathset->next->next;
	}
	delete_pathset(to_delete);
}

int				verify_solution(struct s_solve *solve)
{
	struct s_list	*cur;

	cur = solve->pathsets;
	while (cur)
	{
		if (update_solution(solve, cur) == ERROR)
			return (ERROR);
		cur = cur->next;
	}
}
