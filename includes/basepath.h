/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basepath.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:56:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/16 21:05:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEPATH_H
# define BASEPATH_H

#include <stddef.h>

typedef struct	s_basepath
{
	uint8_t		start_or_end;
	size_t		*all_path_in_base;
	size_t		npaths;
	size_t		mpaths;
}				t_basepath;

#endif
