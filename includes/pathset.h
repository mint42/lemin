/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:57:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/16 02:57:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

# include <stddef.h>
# include <stdbool.h>

# define PATHSET(sets) ((t_pathset *)((sets)->content))

typedef struct s_list	t_list;

typedef struct	s_pathset
{
	size_t		nmoves;
	size_t		maxpathlen;
	size_t		minpathlen;
	size_t		npaths;
	t_list		*paths;
}				t_pathset;

t_pathset		*init_pathset();
void			delete_pathset(void *content, size_t content_size);

#endif
