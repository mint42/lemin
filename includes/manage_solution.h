/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_solution.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 01:24:04 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 20:16:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_SOLUTION_H
# define MANAGE_SOLUTION_H

# include <stddef.h>

typedef struct s_list	t_list;

struct s_pathset;
struct s_solve;
struct s_farm;

void	update_solution(struct s_solve *solve, struct s_list *pathset);
int		verify_solution(struct s_solve *solve);
int		make_solution_printable(char **solution, size_t *solution_len,
				struct s_solve *solve, struct s_farm *farm);

#endif
