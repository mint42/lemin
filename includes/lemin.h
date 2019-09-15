/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:55:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/15 02:51:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stddef.h>

typedef struct s_binarytree		t_binarytree;
typedef struct s_input			t_input;
typedef struct s_farm			t_farm;
typedef struct s_room			t_room;
typedef struct s_solve			t_solve;

int		get_ants(t_input *input, size_t *ants);
int		get_rooms(t_input *input, t_binarytree **rooms, t_farm *farm);
int		get_links(t_input *input, t_farm *farm);
int		solve(t_farm *farm, char **solution);
int		run_bfs(t_bfs *cur, t_bfs *tail, t_farm *farm, size_t *delimiter);
int		update_pathsets(t_solve *solve);

#endif
