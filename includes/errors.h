/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:15:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/05 14:30:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR 1

enum	e_errors
{
	E_ALLOC_ERROR = 0,
	E_ANTS_ERROR,
	E_EMPTY_LINE,
	E_MULTIPLE_START_ROOMS,
	E_MULTIPLE_END_ROOMS,
	E_NO_START_ROOM,
	E_NO_END_ROOM,
	E_ROOM_DUPLICATE,
	E_COORDINATE_DUPLICATE,
	E_NO_COORDINATES,
	E_INVALID_COORDINATE,
	E_INVALID_LINK_FORMAT,
	E_LINK_GIVEN_DNE,
	E_SOLVE_ERROR,
	E_NO_SOLUTION,
	TOTAL_ERROR_COUNT,
};


int		print_error();

#endif
