/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ant.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:21:20 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 01:36:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ANT_H
# define STRUCT_ANT_H

//# include <stdint.h>

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
