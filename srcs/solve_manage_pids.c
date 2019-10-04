/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_manage_pids.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 22:40:12 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 05:24:58 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_mem.h"
#include <stddef.h>

int		realloc_pids_array(size_t **array, size_t *size, size_t new_min_size)
{
	size_t	*new_array;
	size_t	old_size;
	size_t	i;

	old_size = *size;
	while (*size < new_min_size)
		*size = *size * 2;
	new_array = (size_t *)ft_memalloc(sizeof(size_t *) * *size);
	if (!new_array)
		return (print_error(E_ALLOC_ERROR));
	i = 0;
	while (i < old_size)
	{
		new_array[i] = (*array)[i];
		++i;
	}
	ft_memdel((void **)array);
	*array = new_array;
	return (0);
}

int		add_pid(size_t **array, size_t *size, size_t index, size_t bit)
{
	if (*size < index)
		if (realloc_pids_array(array, size, index) == ERROR)
			return (ERROR);
	(*array)[index] = (*array)[index] & bit;
	return (0);
}

