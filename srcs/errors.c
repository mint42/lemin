/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:28:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 08:09:48 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_printf.h"
#include <unistd.h>

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
		"Invalid link format.",
		"Room given for link does not exist.",
		"No links given.",
		"Solve error, otherwise not specified.",
		"No solution.",
	};

	if (error_code < TOTAL_ERROR_COUNT)
	{
		ft_printfd(STDERR_FILENO, "LEM-IN ERROR: %s\n", errors[error_code]);
		ft_printfd(STDERR_FILENO, "PRINT USAGE\n");
	}
	return (ERROR);
}
