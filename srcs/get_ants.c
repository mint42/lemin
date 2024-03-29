/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:12:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/27 13:09:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_input.h"
#include "ft_utils.h"
#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>

int		get_ants(struct s_input *input, size_t *ants)
{
	char	*cur;
	size_t	prev_ants;

	if (!get_next_line(STDIN_FILENO, &(input->line)))
		return (print_error(E_ANTS));
	cur = input->line;
	while (cur && ft_isdigit(*cur))
	{
		prev_ants = *ants;
		*ants = (*ants * 10) + (*cur - 48);
		if (prev_ants > *ants)
			return (print_error(E_ANTS));
		++cur;
	}
	if (cur && *cur)
		return (print_error(E_ANTS));
	update_input(input);
	return (SUCCESS);
}
