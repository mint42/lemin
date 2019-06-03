/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:26:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/03 06:57:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "errors.h"
#include "ants.h"
#include "farm.h"
#include "solve.h"
#include <unistd.h>
#include <stddef.h>

int		main(void)
{
	size_t		ants;
	t_room		*farm;
	int			error;

	ants = 0;
	farm = 0;
	error = get_ants(&ants);
	if (!error)
		error = create_ant_farm(&farm);
	if (!error)
		error = solve(ants, farm);
	delete_ant_farm(&farm);
	if (error)
	{
		print_error(error);
		return (1);
	}
	return (0);
}
