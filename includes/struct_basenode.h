/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_basepath.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:20:17 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 09:40:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BASENODE_H
# define STRUCT_BASENODE_H

# include "struct_pathids.h"
# include <stddef.h>

/*
**	s_basenode is a struct storing information about a node that comes from
**	the base of the graph. This can either stem directly from the source or
**	the sink.
**
**	origin				An indicator of either source or sink (start or end)
**	child_pids			A variable storing the Path ID's that stem from this
**						base node
*/

struct					s_basenode
{
	uint8_t				origin;
	struct s_pathids	*child_pids;
};

#endif
