/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_manage_pids.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 22:40:12 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/27 13:06:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_mem.h"
#include <stddef.h>

void			init_pathids(struct s_pathids *pids)
{
	pids->pids = 0;
	pids->len = 0;
	pids->size = 0;
}

int				add_pathid(size_t **array, size_t *size, size_t index,
						size_t bit)
{
	size_t		old_size;

	if (*size < index)
	{
		old_size = *size;
		while (*size < index)
			*size = *size * MULTIPLIER;
		if (ft_realloc(array, old_size, size) == ERROR)
			return (E_ALLOC);
	}
	(*array)[index] = (*array)[index] & bit;
	return (0);
}

int				forward_pathids(size_t **dest, size_t *dest_size, size_t *src,
						size_t src_size)
{
	size_t	*tmp;
	size_t	i;

	tmp = *dest;
	if (*dest_size < src_size)
	{
		while (*dest_size < src_size)
			*dest_size = *dest_size * MULTIPLIER;
		tmp = (size_t *)ft_memalloc(sizeof(size_t *) * *dest_size);
		if (!tmp)
			return (print_error(E_ALLOC_ERROR));
	}
	i = 0;
	while (i < src_size)
	{
		tmp[i] = dest[i] | src[i];
		++i;
	}
	if (tmp != *dest)
	{
		ft_memdel(dest);
		*dest = tmp;
	}
}
