/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathsets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 02:27:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/29 23:09:22 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSETS_H
# define PATHSETS_H

#include <stddef.h>
#include <stdbool.h>

typedef struct s_list	t_list;

typedef struct	s_pathset
{
	bool		completed;
	size_t		delimiter;
	size_t		nmoves;
	size_t		mpathlen;
	size_t		npaths;
	t_list		*paths;
}				t_pathset;

#endif
