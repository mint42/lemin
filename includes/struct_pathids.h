/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path_ids.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 08:38:49 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 08:48:01 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PATHIDS_H
# define STRUCT_PATHIDS_H

# include <stddef.h>

/*
**	s_path_ids is a struct for storing a set of Path ID's (pids). The pids array
**	is dynamically allocated, and will need resized if the 'size' variable ever
**	becomes larger than 'total_size'
**
**	pids		An array of Path ID's
**	len			Amount of the array currently being used
**	size		Total allocated size of the array
*/

struct			s_pathids
{
	size_t		*pids;
	size_t		len;
	size_t		size;
};

int		realloc_pids_array(struct s_pathids *pids, size_t new_min_size);
int		add_pid(struct s_pathids *pids, size_t index, size_t bit);

#endif
