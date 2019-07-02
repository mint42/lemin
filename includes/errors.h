/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:15:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/07/01 20:50:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR 1

# define ALLOC_ERROR 0
# define ANTS_ERROR 1
# define ROOM_ERROR 2
# define LINK_ERROR 3
# define SOLVE_ERROR 4
# define MULTIPLE_START_ROOMS 5
# define MULTIPLE_END_ROOMS 6
# define NO_START_OR_END_ROOM 7
# define INVALID_ROOM_INPUT 8

//enum	e_errors
//{
//	E_ALLOC_ERROR = 1
//	E_ANTS_ERROR,
//	E_ROOM_ERROR,
//	E_LINK_ERROR,
//	E_SOLVE_ERROR,
//	E_MULTIPLE_START_ROOMS,
//	E_MULTIPLE_END_ROOMS,
//	E_NO_START_OR_END_ROOM,
//	E_INVALID_ROOM_INPUT,
//}

static int	ft_errno;

int		print_error();


#endif 
