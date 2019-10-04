/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 05:33:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 05:39:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANT_H
# define ANT_H

# include <stddef.h>

struct 				s_bfs;
struct 				s_pathset;

struct				s_ant
{
	size_t			ant_num;
	size_t			ant_numlen;
	struct s_bfs	*location;
};

int					setup_ants(struct s_ant **ants_on_line,
						size_t n_ants_on_line, struct s_pathset *solution);
void				update_ants(size_t *ant_number, struct s_ant *ants_on_line,
						size_t n_ants_on_line, struct s_pathset *solution);

#endif
