/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:26:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 02:51:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "lemin.h"
#include "struct_farm.h"
#include "struct_input.h"
#include "struct_room.h"
#include "ft_binarytree.h"
#include "ft_str.h"
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

static int		lemin(struct s_input *input, struct s_farm *farm, struct s_binarytree **rooms)
{
	char	*solution;
	size_t	solution_len;

	solution = 0;
	solution_len = 0;
	if (get_ants(input, &farm->ants) == ERROR)
		return (ERROR);
	if (get_rooms(input,rooms, farm) == ERROR)
		return (ERROR);
	if (make_graph(*rooms, farm) == ERROR)
		return (ERROR);
	if (get_links(input, farm) == ERROR)
		return (ERROR);
	write(STDOUT_FILENO, input->input, input->input_len);
	ft_strdel(&input->input);
	write(STDOUT_FILENO, "\n\n", input->input_len);
	if (solve(farm, &solution, &solution_len) == ERROR)
		return (ERROR);
	write(STDOUT_FILENO, solution, solution_len);
	ft_strdel(&solution);
	return (0);
}

int				main(void)
{
	struct s_binarytree		*rooms;
	struct s_input			input;
	struct s_farm			farm;
	uint8_t					error;

	rooms = 0;
	error = 0;
	init_input(&input);
	init_farm(&farm);
	if (lemin(&input, &farm, &rooms) == ERROR)
		error = 1;
	ft_treedel(&rooms, delete_room);
	delete_graph(&(farm.graph));
	return (error);
}
