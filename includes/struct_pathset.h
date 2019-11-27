/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pathset.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:17:06 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 08:51:04 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PATH_SET_H
# define STRUCT_PATH_SET_H

# include <stddef.h>

# define PATHSET(pathsets) ((struct s_pathset *)((pathsets)->content))

struct s_list;

/*
**	s_pathset stores information about a set of paths that don't collide,
**	making it a potential solution. On a larger scale, a linked list of
**	s_pathset structs exists in the s_solve struct of all potential solutions
**
**	nlines					Number of lines of output this solution will
**							currently yield
**	minpathlen				Length of the shortest path in the set
**	maxpathlen				Length of the longest path in the set
**	min_ant_for_path		Array of however many ants (at least) would be
**							needed to add a new path to the set. Array is
**							updated with every new path added
**	min_ant_for_path_size	Size of the min_ant_for_path array
**	npaths					Number of paths in the set
**	paths					Array of paths in the set
**
**	
**	questions:
**		- why is paths an array? how is the size of that array stored?
*/

struct					s_pathset
{
	size_t				nlines;
	size_t				minpathlen;
	size_t				maxpathlen;
	size_t				*min_ant_for_path;
	size_t				min_ant_for_path_size;
	size_t				npaths;
	struct s_bfs_node	*paths;
};

int						init_pathset(struct s_pathset *pathset);
void					delete_pathset(struct s_list *pathsets_cur);

#endif
