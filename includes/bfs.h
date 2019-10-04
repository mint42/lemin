/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:12:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 05:20:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

#include <stddef.h>

struct					s_farm;
struct					s_pathinfo;
struct					s_solve;

struct					s_bfs
{
	struct s_bfs		*prev;
	struct s_bfs		*next;
	struct s_bfs		*path_prev;
	struct s_bfs		*path_next;
	struct s_path_info	*path_info;
	size_t				rid;
};

int						init_bfs(struct s_bfs **bfs);
int						setup_bfs(struct s_solve *solve, struct s_farm *farm);
int						setup_bfs_node(struct s_bfs **new_node,
							struct s_solve *solve, struct s_farm *farm,
							size_t link_id);
void					delete_bfs_node(struct s_bfs **bfs);
void					delete_bfs_path(struct s_solve *solve);

#endif
