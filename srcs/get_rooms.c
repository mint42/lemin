/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:45:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/29 10:55:49 by rreedy           ###   ########.fr       */
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
			return (print_error(MULTIPLE_START_ROOMS));
		(*start_end) = (*start_end) | START_ROOM;
	}
	else if (ft_strequ("##end", line))
	{
		if ((*start_end) & END_ROOM)
			return (print_error(MULTIPLE_END_ROOMS));
		(*start_end) = (*start_end) | END_ROOM;
	}
	return (0);
}

static int		validate_coordinates(char *line)
{
	size_t	len;

	len = 0;
	if (*line == '-' || *line == '+')
		++line;
	while (ft_isdigit(*line))
	{
		++line;
		++len;
	}
	if (!len || *line != ' ')
		return (1);
	len = 0;
	if (*line == '-' || *line == '+')
		++line;
	while (ft_isdigit(*line))
	{
		++line;
		++len;
	}
	if (!len || *line != ' ')
		return (1);
	return (0);
}

static int		parse_room_line(char *line, t_room *room)
{
	size_t		len;

	len = ft_strlend(line, ' ');
	if (!len || len == ft_strlen(line))
		return (print_error(INVALID_NAME));
	room->name = ft_strndup(line, len);
	line = line + len + 1;
	if (validate_coordinates(line) == ERROR)
		return (print_error(INVALID_COORDINATES));
	return (0);
}

static int		parse_line(char *line, t_room **room, uint8_t *start_end)
{
	if (*line == '#')
	{
		if (parse_comment_line(line, start_end) == ERROR)
			return (1);
		return (0);
	}
	*room = init_room();
	if (!(*room))
		return (print_error(ALLOC_ERROR));
	if (parse_room_line(line, *room) == ERROR)
	{
		delete_room(*room, 0);
		return (print_error(INVALID_ROOM_INPUT));
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
			if (!(start_end & START_ROOM) || !(start_end & END_ROOM))
				return (print_error(NO_START_OR_END_ROOM));
			return (0);
		}
		if (parse_line(input->line, &room, &start_end) == ERROR)
			return (1);
		if (insert_room(rooms, room) == ERROR)
			return (1);
		update_input(input);
		++(farm->nrooms);
	}
	return (1);
}
