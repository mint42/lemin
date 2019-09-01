/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:15:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/01 01:45:08 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR 1

# define TOTAL_ERRORS 10

# define ALLOC_ERROR 0
# define ANTS_ERROR 1
# define MULTIPLE_START_ROOMS 2
# define MULTIPLE_END_ROOMS 3
# define NO_START_OR_END_ROOM 4
# define INVALID_ROOM_INPUT 5
# define ROOM_DUPLICATE 6
# define COORDINATE_DUPLICATE 7
# define LINK_ERROR 8
# define SOLVE_ERROR 9
# define INVALID_COORDINATES 10
# define INVALID_NAME 11
# define NO_SOLUTION 12

/*
**	enum	e_errors
**	{
**		E_ALLOC_ERROR = 1
**		E_ANTS_ERROR,
**		E_ROOM_ERROR,
**		E_LINK_ERROR,
**		E_SOLVE_ERROR,
**		E_MULTIPLE_START_ROOMS,
**		E_MULTIPLE_END_ROOMS,
**		E_NO_START_OR_END_ROOM,
**		E_INVALID_ROOM_INPUT,
**	}
*/

int		print_error();

#endif
