/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path_info.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:16:34 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 06:27:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PATH_INFO_H
# define STRUCT_PATH_INFO_H

#include <stddef.h>

struct s_path_ids;

/*
**	s_path_info is a struct storing information about a path
**
**	pid_index		Array index used to access the correct Path ID bit
**	pid_bit			Bit representing the Path ID
**	basenode		ID for the which origin point this path came from. This ID
**					can be used to index the s_basepaths struct in s_solve to
**					get more information about the origin point of this path
**	depth_lvl		Current depth lvl the path has been to
**	pids_dni		A variable storing the Path ID's that cannot interract with
**					this path (dni -> Do Not Interract)
*/

struct					s_path_info
{
	size_t				pid_index;
	size_t				pid_bit;
	size_t				basepath_id;
	size_t				depth_lvl;
	struct s_path_ids	*pids_dni
};

#endif
