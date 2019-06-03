/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:21:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/03 06:59:39 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "errors.h"
#include "ft_printf.h"

void	print_error(int error)
{
	if (error == GET_NEXT_LINE_ERROR)
		ft_printfd(STDERR_FD, "get_next_line error\n");
	else if (error == SOLVE_ERROR)
		ft_printfd(STDERR_FD, "solve error\n");
	else if (error == ANT_ERROR)
	{
		ft_printfd(STDERR_FD, "ant error\n");
		ft_printfd(STDERR_FD, "usage_error\n");
	}
	else if (error == ROOM_ERROR)
	{
		ft_printfd(STDERR_FD, "room error\n");
		ft_printfd(STDERR_FD, "usage_error\n");
	}
}
