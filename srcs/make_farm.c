/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ant_farm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:33:12 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/16 00:15:14 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"
#include "ft_printf.h"

int		create_ant_farm(t_room **farm)
{
	t_binarytree	*rooms;
	size_t			nrooms;

	error = get_rooms(&rooms, &nrooms);
	if (error)
		return (1);
	return (0);
}
