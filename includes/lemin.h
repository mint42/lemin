/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:55:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 09:56:52 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define IN_PROGRESS 0
# define COMPLETE 1
# define DROPPED 2

# include <stddef.h>
# include <stdint.h>

struct s_bfs_node;
struct s_farm;
struct s_input;
struct s_room;
struct s_solve;
struct s_binarytree;

int		get_ants(struct s_input *input, size_t *ants);
int		get_rooms(struct s_input *input, struct s_binarytree **rooms,
				struct s_farm *farm);
int		get_links(struct s_input *input, struct s_farm *farm);

int		solve(struct s_farm *farm, char **solution, size_t *solution_len);
int		update_bfs(struct s_solve *solve, struct s_farm *farm,
				uint8_t *path_status);
int		update_pathsets(struct s_solve *solve, struct s_farm *farm);

#endif
