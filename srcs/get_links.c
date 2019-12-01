/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:09:59 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/27 13:06:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "config.h"
#include "struct_farm.h"
#include "struct_input.h"
#include "struct_room.h"
#include "ft_str.h"
#include "ft_mem.h"
#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>

static int		add_link(struct s_room *room, size_t link)
{
	if (room->links_arr_size == 0)
	{
		room->links_arr_size = 4;
		room->links = (size_t *)ft_memalloc(sizeof(size_t) * room->links_arr_size);
	}
	++(room->nlinks);
	if (room->nlinks > room->links_arr_size)
	{
		if (ft_realloc((void **)&(room->links), room->links_arr_size,
				room->links_arr_size * MULTIPLIER) == ERROR)
		{
			return (E_ALLOC);
		}
		room->links_arr_size = room->links_arr_size * MULTIPLIER;
	}
	room->links[room->nlinks - 1] = link;
	return (SUCCESS);
}

static int		find_room(char *name, struct s_farm *farm, size_t *room_id, size_t max)
{
	int		cmp;
	size_t	mid;

	if (max < 1)
		return (print_error(E_LINK_GIVEN_DNE));
	mid = *room_id + (max - *room_id) / 2;
	cmp = ft_strncmp(name, (farm->rooms)[mid]->name, (farm->rooms)[mid]->len + 1);
	if (cmp > 0)
	{
		*room_id = mid + 1;
		find_room(name, farm, room_id, max);
	}
	if (cmp < 0)
		find_room(name, farm, room_id, mid - 1);
	*room_id = mid;
	return (SUCCESS);
}

static int		parse_line(char *line, struct s_farm *farm)
{
	size_t		room1_id;
	size_t		room2_id;
	size_t		len;

	if (*line == '#')
		return (SUCCESS);
	if (ft_strchr(line, ' '))
		return (print_error(E_INVALID_LINK_FORMAT));
	len = ft_strlend(line, '-');
	if (len == ft_strlen(line))
		return (print_error(E_LINK_MISSING));
	line[len] = '\0';
	room1_id = 0;
	if (find_room(line, farm, &room1_id, farm->nrooms - 1) == ERROR)
		return (ERROR);
	line[len] = '-';
	room2_id = 0;
	if (find_room(line + len + 1, farm, &room2_id, farm->nrooms - 1) == ERROR)
		return (ERROR);
	if (add_link((farm->rooms)[room1_id], room2_id) == ERROR)
		return (ERROR);
	if (add_link((farm->rooms)[room2_id], room1_id) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int				get_links(struct s_input *input, struct s_farm *farm)
{
	if (!input || !farm || !farm->rooms)
		return (ERROR);
	if (parse_line(input->line, farm) == ERROR)
		return (ERROR);
	update_input(input);
	while (get_next_line(STDIN_FILENO, &(input->line)))
	{
		if (parse_line(input->line, farm) == ERROR)
			return (ERROR);
		update_input(input);
	}
	return (SUCCESS);
}
