/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:12:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/05 16:00:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS
# define BFS_H


typedef struct	s_bfs
{
	t_bfs		*prev;
	t_bfs		*next;
	uint8_t		start_or_end;
	size_t		base_path;
	size_t		id_array_index;
	size_t		id_bit_index;
	size_t		*paths_to_avoid;
	size_t		npaths_to_avoid;
	size_t		mpaths_to_avoid;
	size_t		node_viewing;
}				t_bfs;

#endif
