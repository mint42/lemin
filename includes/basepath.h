/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basepath.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:56:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 22:31:04 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEPATH_H
# define BASEPATH_H

#include <stddef.h>

struct s_basepath
{
	uint8_t		origin;
	size_t		*paths_in_base;
	size_t		s_paths;
};

#endif
