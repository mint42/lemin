/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:45:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/03 19:36:04 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "farm.h"
#include "room.h"
#include "input.h"
#include "ft_fd.h"
#include "ft_str.h"
#include "ft_utils.h"
#include "ft_conv.h"
#include "ft_binarytree.h"
#include "get_next_line.h"
#include <stdint.h>

static int		parse_comment_line(char *line, uint8_t *start_end)
{
	if (ft_strequ("##start", line))
	{
		if ((*start_end) & START_ROOM)
			return (print_error(E_MULTIPLE_START_ROOMS));
		(*start_end) = (*start_end) | START_ROOM;
	}
	else if (ft_strequ("##end", line))
	{
		if ((*start_end) & END_ROOM)
			return (print_error(E_MULTIPLE_END_ROOMS));
		(*start_end) = (*start_end) | END_ROOM;
	}
	return (0);
}

static int		get_coordinates(char *line, t_room *room)
{
	room->x = ft_atoi(*line);
	if (*line == '-' || *line == '+')
		++line;
	while (ft_isdigit(*line))
		++line;
	if (room->x == 0 && *line != ' ')
		return (ERROR);
	++line;
	len = 0;
	room->y = ft_atoi(*line);
	if (*line == '-' || *line == '+')
		++line;
	while (ft_isdigit(*line))
		++line;
	if (room->y == 0 && !ft_isdigit(*(line - 1)))
		return (ERROR);
	return (0);
}

static int		parse_room_line(char *line, t_room *room)
{
	size_t		len;

	len = ft_strlend(line, ' ');
	if (!len)
		return (print_error(E_EMPTY_LINE));
	if (len == ft_strlen(line))
		return (print_error(E_NO_COORDINATES));
	room->name = ft_strndup(line, len);
	if (validate_coordinates(line + len + 1) == ERROR)
		return (print_error(E_INVALID_COORDINATE));
	return (0);
}

static int		parse_line(char *line, t_room **room, uint8_t *start_end)
{
	if (*line == '#')
	{
		if (parse_comment_line(line, start_end) == ERROR)
			return (ERROR);
		return (0);
	}
	*room = init_room();
	if (!(*room))
		return (print_error(E_ALLOC_ERROR));
	if (parse_room_line(line, *room) == ERROR)
	{
		delete_room(*room, 0);
		return (ERROR);
	}
	(*room)->start_end = *start_end;
	*start_end = *start_end ^ (*start_end << 2);
	return (0);
}

int				get_rooms(t_input *input, t_binarytree **rooms, t_farm *farm)
{
	t_room			*room;
	uint8_t			start_end;

	start_end = 0;
	while (get_next_line(STDIN_FD, &(input->line)))
	{
		room = 0;
		if (ft_strchr(input->line, '-'))
		{
			if (!(start_end & START_ROOM))
				return (print_error(E_NO_START_ROOM));
			if (!(start_end & END_ROOM))
				return (print_error(E_NO_END_ROOM));
			return (sort_rooms_by_name(rooms) == ERROR);
		}
		if (parse_line(input->line, &room, &start_end) == ERROR)
			return (ERROR);
		if (insert_coordinates(rooms, room) == ERROR)
			return (ERROR);
		update_input(input);
		++(farm->nrooms);
	}
	return (ERROR);
}
