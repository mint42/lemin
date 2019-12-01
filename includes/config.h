/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:48:06 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/27 11:51:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*
**	MULTIPLIER is the rate at which all of the dynamically allocated arrays
**	will grow.
**
**	ie. When an array is filled, it will be reallocated to 
**	current_size * MULTIPLIER larger
*/

# define MULTIPLIER 2

#endif
