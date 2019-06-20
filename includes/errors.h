/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:15:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/19 22:27:52 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#define ALLOC_ERROR 0
#define ANTS_ERROR 1
#define ROOM_ERROR 2
#define LINK_ERROR 3
#define SOLVE_ERROR 4

static int	ft_error;

void		print_error();

#endif 
