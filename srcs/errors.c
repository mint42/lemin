/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:21:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/07/03 17:37:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_fd.h"
#include "ft_printf.h"

int		print_error(int error)
{
	char	*errors[TOTAL_ERRORS] = {
		"Malloc fail. Check memory usage.",
		"Invalid input for number of ants",
		"Multiple ##start rooms have been declared",
		"Multiple ##end rooms have been declared",
		"##start and/or ##end room not declared",
		"One or more rooms not correctly formatted",
		"Multiple rooms have been declared with the same name",
		"Multiple rooms have been defined with the same coordinates",
		"Link error, otherwise not specified",
		"Solve error, otherwise not specified",
	};

	if (error > 0 && error < TOTAL_ERRORS - 1)
	{
		ft_printfd(STDERR_FD, "LEM-IN ERROR: %s\n", errors[error]);
		ft_printfd(STDERR_FD, "PRINT USAGE\n");
	}
	return (ERROR);
}
