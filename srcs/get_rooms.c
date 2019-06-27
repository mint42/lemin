/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:45:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/26 20:09:32 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "farm.h"
#include "room.h"
#include "input.h"
#include "ft_fd.h"
#include "ft_str.h"
#include "ft_mem.h"
#include "ft_utils.h"
#include "ft_conv.h"
#include "ft_binarytree.h"
#include "get_next_line.h"

static int		parse_comment_line(char *line, int *start_or_end)
{
	if (ft_strequ("##start", line))
	{
		if ((*start_or_end) & START_ROOM)
		{
			ft_errno = MULTIPLE_START_ROOMS;
			return (1);
		}
		(*start_or_end) = (*start_or_end) | START_ROOM;
	}
	else if (ft_strequ("##end", line))
	{
		if ((*start_or_end) & END_ROOM)
		{
			ft_errno = MULTIPLE_END_ROOMS;
			return (1);
		}
		(*start_or_end) = (*start_or_end) | END_ROOM;
	}
	return (0);
}

static int		parse_room_line(char *line, t_room *room)
{
	size_t		len;

	len = ft_strlend(line, ' ');
	if (!len)
		return (1);
	room->name = ft_strndup(line, len);
	line = line + len + 1;
	len = ft_strlend(line, ' ');
	if (!len || !ft_isdigit(*line))
		return (1);
	room->x = ft_atoi(line);
	line = line + len + 1;
	if (!len || !ft_isdigit(*line))
		return (1);
	room->y = ft_atoi(line);
	return (0);
}

static int		parse_line(char *line, t_room **room, int *start_or_end)
{
	if (ft_strnequ("##", line, 2))
	{
		if (parse_comment_line(line, start_or_end) == ERROR)
			return (1);
		return (0);
	}
	*room = init_room();
	if (parse_room_line(line, *room) == ERROR)
	{
		ft_errno = INVALID_ROOM_INPUT;
		delete_room(room, 0);
		return (1);
	}
	(*room)->start_or_end = *start_or_end;
	return (0);
}

int				get_rooms(t_input *input, t_room **farm, size_t *nrooms)
{
	t_binarytree	*rooms;
	t_room			*room;
	int				start_or_end;

	room = 0;
	rooms = 0;
	start_or_end = 0;
	while (get_next_line(STDIN_FD, &(input->line)))
	{
		if (parse_line(input->line, &room, &start_or_end) == ERROR)
		{
			if (!start_or_end || !ft_strchr(input->line, '-'))
				break ;
			*farm = init_farm(*nrooms);
			if (!(*farm))
				break ;
			fill_farm(*farm, &rooms, *nrooms);
			return (0);
		}
		insert_room(&rooms, room);
		update_input(input);
		++(*nrooms);
	}
	ft_treedel(&rooms, 0);
	return (1);
}
