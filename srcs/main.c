/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:26:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/07/28 05:51:03 by rreedy           ###   ########.fr       */
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

static void		print_solution(t_input *input, char *solution, size_t len)
{
	write();
	write();
	write();
}

static int		lemin(t_input *input, t_farm *farm, t_binarytree *rooms)
{
	char	*solution;
	size_t	len;

	solution = 0;
	len = 0;
	if (get_ants(input, &farm->ants) == ERROR)
		return (1);
	if (get_rooms(input, rooms, farm) == ERROR)
		return (1);
	if (make_farm(rooms, farm) == ERROR)
		return (1);
	if (get_links(input, farm) == ERROR)
		return (1);
	if (solve(farm, &solution, len) == ERROR)
		return (1);
	print_solution(input solution);
	ft_strdel(&solution);
	return (0);
}

int				main(void)
{
	t_binarytree	*rooms;
	t_farm			farm;
	t_input			input;
	char			*solution;
	unsigned int	error;

	rooms = 0;
	error = 0;
	input = init_input();
	farm = init_farm();
	if (lemin(&input, &farm, &rooms) == ERROR)
		error = 1;
	ft_treedel(&rooms, delete_room);
	delete_farm(&farm);
	delete_input(&input);
	return (error);
}
