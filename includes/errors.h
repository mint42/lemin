/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:15:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/27 13:07:11 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR 1
# define SUCCESS 0

enum	e_errors
{
	E_ALLOC= 0,
	E_ANTS,
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
	E_LINK_MISSING,
	E_NO_LINKS,
	E_SOLVE,
	E_NO_SOLUTION,
	TOTAL_ERROR_COUNT,
};

int		print_error();

#endif
