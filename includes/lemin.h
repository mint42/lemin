/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:55:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/29 06:10:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stddef.h>

/*
**	struct s_binarytree;
**	struct s_input;
**	struct s_farm;
**	struct s_room;
**	struct s_bfs;
**	struct s_solve;
*/

int		get_ants(struct s_input *input, size_t *ants);
int		get_rooms(struct s_input *input, struct s_binarytree **rooms, struct s_farm *farm);
int		get_links(struct s_input *input, struct s_farm *farm);
int		solve(struct s_farm *farm, char **solution);
int		run_bfs(struct s_solve *solve, struct s_farm *farm);
int		update_pathsets(struct s_solve *solve, struct s_farm *farm);

#endif
