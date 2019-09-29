/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:13:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/29 06:10:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

#include <stddef.h>
#include <stdint.h>

# define PATH(paths) ((struct s_bfs *)((paths)->content))
# define PATH_ID_INDEX(paths) (((struct s_bfs *)((paths)->content))->path_id_index)
# define PATH_ID_BIT(paths) (1 << (((struct s_bfs *)((paths)->content))->path_id_bit))

struct s_path
{
	size_t	pid_index;
	size_t	pid_bit;
	size_t	basepath_id;
	size_t	depth_level;
	size_t	*pids_dni;
	size_t	s_pids_dni;
};

#endif

