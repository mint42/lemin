/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:45:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 08:40:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_farm.h"
#include "struct_room.h"
#include "struct_input.h"
#include "ft_str.h"
#include "ft_utils.h"
#include "ft_conv.h"
#include "ft_binarytree.h"
#include "get_next_line.h"
#include <stdint.h>
#include <unistd.h>

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

static int		parse_room_line(char *line, struct s_room *room)
{
	size_t		len;

	len = 0;
	if (init_room(&room) == ERROR)
		return (ERROR);
	room->name = ft_parse_word(&line, &len);
	if (len == 0)
		return(E_EMPTY_LINE);
	room->len = len;
	room->name = ft_strndup(room->name, len);
	if (!room->name)
		return (print_error(E_ALLOC));
	ft_parse_space(&line, &len);
	if (len != 1)
		return (print_error(E_INVALID_COORDINATE));
	room->x = ft_parse_number(&line, &len);
	if (len == 0)
		return (print_error(E_INVALID_COORDINATE));
	ft_parse_white_space(&line, &len);
	if (len != 1)
		return (print_error(E_INVALID_COORDINATE));
	room->y = ft_parse_number(&line);
	if (!(*line))
		return (print_error(E_INVALID_COORDINATE));
	return (SUCCESS);
}

/*
**	get_rooms comes directly from get_ants and continues looping through the
**	data line by line. As it loops, each line gets parsed, and then 
*/

int				get_rooms(struct s_input *input, struct s_farm *farm)
{
	struct s_binarytree		*bintree_rooms;
	struct s_room			*room;
	uint8_t					start_end;

	start_end = 0;
	while (get_next_line(STDIN_FILENO, &(input->line)))
	{
		room = 0;
		if (ft_strchr(input->line, '-'))
		{
			if (!(start_end & START_ROOM))
				return (print_error(E_NO_START_ROOM));
			if (!(start_end & END_ROOM))
				return (print_error(E_NO_END_ROOM));
			if (rearrange_rooms_by_name(rooms) == ERROR)
				return (ERROR);
			return (0);
		}
		else if (*(input->line) == '#')
			parse_comment_line(input->line, &start_end);
		else
		{
			parse_room_line(input->line, &room, start_end);
			++(*nrooms);
			(*room)->start_end = start_end;
			start_end = start_end ^ (start_end << 2);
			if (insert_broom_by_coordinates(bintree_rooms, room) == ERROR)
				return (ERROR);
		}
		if (update_input(input) == ERROR)
			return (ERROR);
	}
	return (print_error(E_NO_LINKS));
}
