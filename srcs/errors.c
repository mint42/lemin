/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:28:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/03 17:23:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_fd.h"
#include "ft_printf.h"

int		print_error(enum e_errors error_code)
{
	char	*errors[TOTAL_ERROR_COUNT] = {
		"Malloc fail. Check memory usage.",
		"Invalid number of ants given.",
		"Empty line found.",
		"Multiple ##start rooms have been declared.",
		"Multiple ##end rooms have been declared.",
		"##start room not declared.",
		"##end room not declared.",
		"Multiple rooms have been declared with the same name.",
		"Multiple rooms have been defined with the same coordinates.",
		"No coordinates given for one or more rooms.",
		"Invalid coordinate given for one or more rooms.",
		"Link error, otherwise not specified.",
		"Solve error, otherwise not specified.",
		"No solution.",
	};

	if (error_code < TOTAL_ERROR_COUNT)
	{
		ft_printfd(STDERR_FD, "LEM-IN ERROR: %s\n", errors[error_code]);
		ft_printfd(STDERR_FD, "PRINT USAGE\n");
	}
	return (ERROR);
}
