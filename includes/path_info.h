/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 05:21:34 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 05:21:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_INFO_H
# define PATH_INFO_H

#include <stddef.h>

struct		s_path_info
{
	size_t	pid_index;
	size_t	pid_bit;
	size_t	base_pid;
	size_t	depth_lvl;
	size_t	*pids_dni;
	size_t	pids_dni_len;
	size_t	pids_dni_size;
};

#endif

