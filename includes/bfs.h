/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:12:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/14 15:58:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

#include <stddef.h>
#include <stdint.h>

# define PATH(paths) ((t_bfs *)((paths)->content))
# define PATH_ID_INDEX(paths) (((t_bfs *)((paths)->content))->path_id_index)
# define PATH_ID_BIT(paths) (1 << (((t_bfs *)((paths)->content))->path_id_bit))

typedef struct s_bfs	t_bfs;
typedef struct s_farm	t_farm;

typedef struct	s_bfs
{
	t_bfs		*prev;
	t_bfs		*next;
	uint8_t		start_or_end_path;
	size_t		base_path;
	size_t		path_id_index;
	size_t		path_id_bit;
	size_t		*paths_to_avoid;
	size_t		npaths_to_avoid;
	size_t		mpaths_to_avoid;
	size_t		room_id;
	size_t		depth_level;
}				t_bfs;

t_bfs			*init_bfs(void);
int				new_bfs_node(t_bfs *cur, t_bfs *tail, t_farm *farm);
void			delete_bfs(t_bfs **bfs);

#endif
