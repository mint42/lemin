/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:15:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/21 16:03:34 by rreedy           ###   ########.fr       */
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
# define INVALID_ROOM_INPUT 7

static int	ft_errno;

void		print_error();


#endif 
