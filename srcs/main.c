/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:26:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/24 16:20:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "input.h"
#include "errors.h"
#include "farm.h"
#include "solve.h"
#include <unistd.h>
#include <stddef.h>

static int		lemin(t_input *input, t_room **farm)
{
	size_t			ants;
	size_t			nrooms;

	ants = 0;
	nrooms = 0;
	if (get_ants(input, &ants) == ERROR)
		return (1);
	if (get_rooms(input, farm, &nrooms) == ERROR)
		return (1);
	if (get_links(input, *farm, nrooms) == ERROR)
		return (1);
	if (solve(ants, *farm) == ERROR)
		return (1);
	return (0);
}

int				main(void)
{
	t_input			input;
	t_room			*farm;
	unsigned int	error;

	farm = 0;
	error = 0;
	input = init_input();
	if (lemin(&input, &farm) == ERROR)
	{
		error = 1;
		print_error();
	}
	delete_input(&input);
	delete_farm(&farm);
	return (error);
}
