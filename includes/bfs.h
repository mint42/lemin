/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:12:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/29 06:10:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

#include <stddef.h>
#include <stdint.h>

typedef struct s_bfs		t_bfs;
typedef struct s_path_info	t_path_info;

typedef struct		s_bfs
{
	t_bfs			*prev;
	t_bfs			*next;
	t_bfs			*path_prev;
	t_bfs			*path_next;
	size_t			rid;
	t_path_info		*path_info;
}					t_bfs;

int					init_bfs(t_bfs **bfs);
void				delete_bfs(t_bfs **bfs);

#endif
