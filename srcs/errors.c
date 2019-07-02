/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:21:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/07/01 20:50:32 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "ft_fd.h"
#include "ft_printf.h"

int		print_error(int error)
{
	if (error == SOLVE_ERROR)
		ft_printfd(STDERR_FD, "solve error\n");
	else if (error == ANTS_ERROR)
	{
		ft_printfd(STDERR_FD, "ant error\n");
		ft_printfd(STDERR_FD, "usage_error\n");
	}
	else if (error == ROOM_ERROR)
	{
		ft_printfd(STDERR_FD, "room error\n");
		ft_printfd(STDERR_FD, "usage_error\n");
	}
	return (ERROR);
}
