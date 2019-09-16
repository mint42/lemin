/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basepath.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 02:56:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/16 02:56:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEPATH_H
# define BASEPATH_H

#include <stddef.h>

typedef struct	s_basepath
{
	size_t		start_or_end;
	size_t		base_path_id;
	size_t		*paths_in_base;
	size_t		npaths_in_base;
	size_t		mpaths_in_base;
}				t_basepath;

#endif
