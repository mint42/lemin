/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:48:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/07/01 20:52:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"
#include "farm.h"
#include "errors.h"
#include "ft_mem.h"
#include "ft_binarytree.h"
#include "ft_printf.h"
#include <stddef.h>

t_room			*init_farm(size_t nrooms)
{
	t_room	*farm;

	farm = (t_room *)ft_memalloc(sizeof(t_room) * nrooms);
	if (!farm)
		return (0);
	return (farm);
}

static void		fill_farm(t_room *farm, t_binarytree *rooms, size_t room)
{
	if (rooms)
	{
		if (rooms->right)
			fill_farm(farm, rooms, room);
		farm[room] = *(t_room *)(rooms->content);
		--room;
		if (rooms->left)
			fill_farm(farm, rooms, room);
	}
}

int				make_farm(t_binarytree *rooms, t_room **farm, size_t nrooms)
{
	*farm = init_farm(nrooms);
	if (!(*farm))
		return (print_error(ALLOC_ERROR));
	fill_farm(*farm, rooms, nrooms);
	return (0);
}

int				delete_farm(t_room **farm)
{
	(void)farm;
	ft_printf("delete ant farm\n");
	return (0);
}
