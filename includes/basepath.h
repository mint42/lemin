/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basepath.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:56:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 05:11:00 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEPATH_H
# define BASEPATH_H

#include <stddef.h>
#include <stdint.h>

struct			s_basepath
{
	uint8_t		origin;
	size_t		*child_pids;
	size_t		child_pids_len;
	size_t		child_pids_size;
};

#endif
