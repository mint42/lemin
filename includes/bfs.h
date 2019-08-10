/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:12:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/10 16:27:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS
# define BFS_H


typedef struct	s_bfs
{
	t_bfs		*prev;
	t_bfs		*next;
	uint8_t		start_or_end_path;
	size_t		base_path;
	size_t		path_id_array_index;
	size_t		path_id_bit_index;
	size_t		*paths_to_avoid;
	size_t		npaths_to_avoid;
	size_t		mpaths_to_avoid;
	size_t		room_id;
	size_t		depth_level;
}				t_bfs;

#endif
