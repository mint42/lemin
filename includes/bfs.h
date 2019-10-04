/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:12:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 22:31:07 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

#include <stddef.h>
#include <stdint.h>

struct s_bfs
{
	struct s_bfs		*prev;
	struct s_bfs		*next;
	struct s_bfs		*path_prev;
	struct s_bfs		*path_next;
	struct s_path_info	*path_info;
	size_t				rid;
};

int		init_bfs(struct s_bfs **bfs);
void	delete_bfs(struct s_bfs **bfs);

#endif
