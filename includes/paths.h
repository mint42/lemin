/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:31:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/02 01:29:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H
# define PATHS_H

#include <stddef.h>

typedef struct	s_paths
{
	size_t		max_path_len;
	size_t		npaths;
	t_list		*paths;
}				t_paths;

#endif
