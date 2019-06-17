/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:12:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/06 19:50:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "errors.h"
#include "ft_utils.h"
#include "get_next_line.h"
#include <stddef.h>

int		get_ants(size_t *ants)
{
	char	*line;
	size_t	prev_ants;

	line = NULL;
	if (!get_next_line(STDIN_FD, &line))
		return (ANT_ERROR);
	while (line && *line && ft_isdigit(*line))
	{
		prev_ants = *ants;
		*ants = (*ants * 10) + (*line - 48);
		if (prev_ants > *ants)
			return (ANT_ERROR);
		++line;
	}
	if (line && *line)
		return (ANT_ERROR);
	return (0);
}
