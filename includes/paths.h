/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/07/28 02:37:35 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H
# define PATHS_H

#include <stddef.h>

typedef struct	s_bfs
{
	size_t		array_index;
	size_t		bit_index;
	size_t		*paths_to_avoid;
	size_t		npaths_to_avoid;
	size_t		mpaths_to_avoid;
}				t_bfs;

#endif
