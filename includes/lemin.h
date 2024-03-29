/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:55:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 12:29:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stddef.h>
# include <stdint.h>

/*
**	path status
*/

# define IN_PROGRESS 0
# define COMPLETE 1
# define DROPPED 2

struct s_farm;
struct s_input;

int		get_ants(struct s_input *input, size_t *ants);
int		get_rooms(struct s_input *input, struct s_farm *farm);
int		get_links(struct s_input *input, struct s_farm *farm);
int		get_solution(struct s_farm *farm, char **solution,
				size_t *solution_len);
#endif
