/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:12:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/03 16:21:33 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "errors.h"
#include "ft_fd.h"
#include "ft_utils.h"
#include "get_next_line.h"
#include <stddef.h>

int		get_ants(t_input *input, size_t *ants)
{
	char	*cur;
	size_t	prev_ants;

	if (!get_next_line(STDIN_FD, &(input->line)))
		return (print_error(E_ANTS_ERROR));
	cur = input->line;
	while (cur && ft_isdigit(*cur))
	{
		prev_ants = *ants;
		*ants = (*ants * 10) + (*cur - 48);
		if (prev_ants > *ants)
			return (print_error(E_ANTS_ERROR));
		++cur;
	}
	if (cur && *cur)
		return (print_error(E_ANTS_ERROR));
	update_input(input);
	return (0);
}
