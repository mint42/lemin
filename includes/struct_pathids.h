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

void	init_pathids(struct s_pathids *pids);
int		add_pathid(size_t **array, size_t *size, size_t index, size_t bit);
int		forward_pathids(size_t **dest, size_t *dest_size, size_t *src,
				size_t src_size);

#endif
