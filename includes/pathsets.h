/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathsets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 02:27:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/10 19:10:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSETS_H
# define PATHSETS_H

# include <stddef.h>
# include <stdbool.h>

# define PATHSET(sets) ((t_pathset *)((sets)->content))

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

t_pathset		*init_pathset();
void			delete_pathset(void *content, size_t content_size);

#endif
