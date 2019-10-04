/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:57:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 05:43:57 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHSET_H
# define PATHSET_H

# include <stddef.h>

# define PATHSET(pathsets) ((struct s_pathset *)((pathsets)->content))

struct				s_bfs;
struct				s_list;

struct				s_pathset
{
	size_t			nlines;
	size_t			minpathlen;
	size_t			maxpathlen;
	size_t			*min_ant_for_path;
	size_t			min_ant_for_path_size;
	size_t			npaths;
	struct s_bfs	*paths;
};

void				init_pathset(struct s_pathset *pathset);
void				delete_pathset(struct s_list *pathsets_cur);

#endif
