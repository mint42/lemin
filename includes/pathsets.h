/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathsets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 02:27:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/03 17:08:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSETS_H
# define PATHSETS_H

#include <stddef.h>

typedef struct	s_pathset
{
	bool		completed;
	size_t		delimiter;
	size_t		nmoves;
	size_t		max_path_len;
	size_t		npaths;
	t_list		*paths;
}				t_pathset;

#endif
