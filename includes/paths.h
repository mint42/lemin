/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/03 06:34:03 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H
# define PATHS_H

#include <stddef.h>

typedef struct	s_paths
{
	size_t		index;
	size_t		bit;
	size_t		npaths_start;
	size_t		npaths_end;
}				t_paths;

typedef struct	s_path
{
	size_t		index;
	size_t		bit;
	size_t		*paths_to_avoid;
	size_t		max_index;
}				t_path;

#endif
