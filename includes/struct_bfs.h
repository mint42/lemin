/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bfs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:20:37 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 06:27:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BFS_H
# define STRUCT_BFS_H

#include <stddef.h>

struct					s_farm;
struct					s_pathinfo;
struct					s_solve;

/*
**	s_bfs is a Breadth First Search implemented as a queue. Pointers to the
**	head, tail, and current positions of the bfs are in the s_solve struct
**
**	prev, next				Seqential previous and next pointers for the queue
**	path_prev, path_next	Hold the previous and next pointers on the path the
**							node is attached to
**	path_info				Stores information about the current node's path
**	rid						Room ID. The room in the ant farm that the node is
**							exploring
**
**	questions:
**		- how does path_next get set up?
*/

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
