/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:57:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 03:02:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

# include <stddef.h>
# include <stdbool.h>

# define PATHSET(sets) ((struct s_pathset *)((sets)->content))

struct s_pathset
{
	size_t			nmoves;
	size_t			minpathlen;
	size_t			maxpathlen;
	size_t			*min_ant_for_path;
	size_t			s_min_ant_for_path;
	size_t			npaths;
	struct s_list	*paths;
};

struct s_pathset	*init_pathset();
void				delete_pathset(t_list *pathsets_cur);

#endif
