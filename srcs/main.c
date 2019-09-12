/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:26:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/10 21:39:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "input.h"
#include "errors.h"
#include "farm.h"
#include "bfs.h"
#include "solve.h"
#include "ft_str.h"
#include "ft_put.h"
#include "ft_binarytree.h"
#include <unistd.h>
#include <stddef.h>


/*
**	#include "ft_printf.h"
**	
**	static void		print_rooms(t_farm *farm)
**	{
**		size_t	i;
**	
**		i = 0;
**		ft_printf("ants: %zd\nstart_room_id: %zd\nend_room_id: %zd\nnrooms: %zd\nrooms:\n\n",
**			farm->ants, farm->start_room_id, farm->end_room_id, farm->nrooms);
**		while (i < farm->nrooms)
**		{
**			ft_printf("%s\n\n", (farm->graph)[i].name);
**			++i;
**		}
**	}
**	
*/

static int		lemin(t_input *input, t_farm *farm, t_binarytree **rooms)
{
	char			*solution;

	solution = 0;
	if (get_ants(input, &farm->ants) == ERROR)
		return (ERROR);
	if (get_rooms(input, rooms, farm) == ERROR)
		return (ERROR);
	if (make_graph(*rooms, farm) == ERROR)
		return (ERROR);
	if (get_links(input, farm) == ERROR)
		return (ERROR);
//	if (solve(farm, &solution) == ERROR)
//		return (ERROR);
	ft_putendl(input->input);
//	ft_putstr(solution);
//	ft_strdel(&solution);
	return (0);
}

int				main(void)
{
	t_binarytree	*rooms;
	t_farm			farm;
	t_input			input;
	unsigned int	error;

	rooms = 0;
	error = 0;
	input = init_input();
	farm = init_farm();
	if (lemin(&input, &farm, &rooms) == ERROR)
		error = 1;
//	ft_treedel(&rooms, delete_room);
//	delete_graph(&(farm.graph));
	ft_strdel(&(input.input));
	ft_strdel(&(input.line));
	return (error);
}
