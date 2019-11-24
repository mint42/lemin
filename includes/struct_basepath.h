/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_basepath.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:20:17 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 01:36:10 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BASEPATH_H
# define STRUCT_BASEPATH_H

//#include <stdint.h>

/*
**	s_basepath is a struct storing information about a node that comes from
**	the "base" of the graph. This can either be from the "source" or the "sink".
**
**	origin				An indicator of either source or sink (start or end)
**	child_pids			A variable storing the Path ID's the stem from this
**						base node
**	child_pids_len		Current length of the array
**	child_pids_size		Total size of the array available before needing to
**						resize it
*/

struct			s_basepath
{
	uint8_t		origin;
	size_t		*child_pids;
	size_t		child_pids_len;
	size_t		child_pids_size;
};

#endif
