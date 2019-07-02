/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:26:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/07/01 21:12:24 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "input.h"
#include "errors.h"
#include "farm.h"
#include "solve.h"
#include "ft_binarytree.h"
#include <unistd.h>
#include <stddef.h>

static int		lemin(t_input *input, t_binarytree **rooms, t_room **farm)
{
	size_t			ants;
	size_t			nrooms;

	ants = 0;
	nrooms = 0;
	if (get_ants(input, &ants) == ERROR)
		return (1);
	if (get_rooms(input, rooms, &nrooms) == ERROR)
		return (1);
	if (make_farm(*rooms, farm, nrooms) == ERROR)
		return (1);
	if (get_links(input, *farm, nrooms) == ERROR)
		return (1);
	if (solve(ants, *farm) == ERROR)
		return (1);
	return (0);
}

int				main(void)
{
	t_binarytree	*rooms;
	t_room			*farm;
	t_input			input;
	unsigned int	error;

	rooms = 0;
	farm = 0;
	error = 0;
	input = init_input();
	if (lemin(&input, &rooms, &farm) == ERROR)
		error = 1;
	delete_input(&input);
	ft_treedel(&rooms, delete_room);
	delete_farm(&farm);
	return (error);
}
