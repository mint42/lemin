/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:26:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 12:17:02 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "lemin.h"
#include "graph_rooms.h"
#include "struct_farm.h"
#include "struct_input.h"
#include "struct_room.h"
#include "ft_binarytree.h"
#include "ft_str.h"
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

static int		solve(struct s_input *input, struct s_farm *farm)
{
	char	*solution;
	size_t	solution_len;

	solution = 0;
	solution_len = 0;
	if (get_solution(farm, &solution, &solution_len) == ERROR)
		return (ERROR);
	write(STDOUT_FILENO, "\n\n", input->input_len);
	write(STDOUT_FILENO, solution, solution_len);
	ft_strdel(&solution);
	return (SUCCESS);
}

static int		parse_input(struct s_input *input, struct s_farm *farm)
{
	if (get_ants(input, &farm->nants) == ERROR)
		return (ERROR);
	if (get_rooms(input, farm) == ERROR)
		return (ERROR);
	if (get_links(input, farm) == ERROR)
		return (ERROR);
	write(STDOUT_FILENO, input->input, input->input_len);
	return (SUCCESS);
}

int				main(void)
{
	struct s_input		input;
	struct s_farm		farm;
	uint8_t				error_code;

	error_code = 0;
	init_input(&input);
	init_farm(&farm);
	error_code = parse_input(&input, &farm);
	ft_strdel(&input.input);
	if (error_code == ERROR)
	{
		ft_strdel(&input.line);
		delete_rooms(&(farm.rooms), farm.nrooms);
		print_error();
		return (ERROR);
	}
	error_code = solve(&input, &farm);
	delete_rooms(&(farm.rooms), farm.nrooms);
	if (error_code == ERROR)
	{
		print_error();
		return (ERROR);
	}
	return (SUCCESS);
}
