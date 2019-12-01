/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:45:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 12:06:34 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "binarytree_rooms.h"
#include "graph_rooms.h"
#include "struct_farm.h"
#include "struct_room.h"
#include "struct_input.h"
#include "ft_str.h"
#include "ft_utils.h"
#include "ft_conv.h"
#include "ft_parse.h"
#include "ft_binarytree.h"
#include "get_next_line.h"
#include <stdint.h>
#include <unistd.h>

static int		parse_comment_line(char *line, uint8_t *boundries)
{
	if (ft_strequ("##start", line))
		*boundries = *boundries | START_ROOM;
	else if (ft_strequ("##end", line))
		*boundries = *boundries | END_ROOM;
	if ((*boundries) & (START_ROOM << 2))
		return (print_error(E_MULTIPLE_END_ROOMS));
	if ((*boundries) & (END_ROOM << 2))
		return (print_error(E_MULTIPLE_END_ROOMS));
	return (SUCCESS);
}

static int		parse_room_line(char *line, struct s_room *room)
{
	size_t		len;
	char		*word;

	len = 0;
	word = ft_parse_word(&line, &len);
	if (len == 0)
		return(E_EMPTY_LINE);
	room->len = len;
	room->name = ft_strndup(word, len);
	if (!room->name)
		return (print_error(E_ALLOC));
	ft_parse_space(&line, &len);
	if (len != 1)
		return (print_error(E_INVALID_COORDINATE));
	room->x = ft_parse_number(&line, &len);
	if (len == 0)
		return (print_error(E_INVALID_COORDINATE));
	ft_parse_space(&line, &len);
	if (len != 1)
		return (print_error(E_INVALID_COORDINATE));
	room->y = ft_parse_number(&line, &len);
	if (!(*line))
		return (print_error(E_INVALID_COORDINATE));
	return (SUCCESS);
}

int			parse_line(struct s_binarytree **bintree_rooms, uint8_t *boundries,
					struct s_farm *farm, struct s_input *input)
{
	struct s_room		*room;

	room = 0;
	if (*(input->line) == '#')
		parse_comment_line(input->line, boundries);
	else
	{
		if (init_room(&room) == ERROR)
			return (ERROR);
		parse_room_line(input->line, room);
		++(farm->nrooms);
		room->start_end = *boundries & (START_ROOM & END_ROOM);
		*boundries = *boundries ^ (*boundries << 2);
		if (insert_room_by_coordinates(bintree_rooms, room) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

/*
**	get_rooms comes directly from get_ants and continues looping through the
**	data line by line. As it loops, each line gets parsed, and the rooms get
**	organized into a binarytree.
**
**	When the rooms are first sorted into the tree they are organized by their
**	coordinate to verify there are no overlapping rooms. Once there are no more
**	rooms to parse the binarytree is resorted alphabetically by name to verify
**	there are no rooms with the same name. This tree then gets sent to
**	setup_rooms() which will turn the tree into an array of struct s_room
**	pointers. The array will make accessing and storing the rooms easier in the
**	solving process.
**
**	uint8_t boundries is a variable that stores both if the current room is the
**	starting or ending room, and if the starting or ending rooms have been found
**	yet. start room and end room are synonymous with the graph theory terms
**	"source" and "sink"
**
**	bit encoding:
**
**	0 0 0 0	1			1			1				1
**			source		sink		current room	current room
**			defined		defined		is source		is sink
*/

int				get_rooms(struct s_input *input, struct s_farm *farm)
{
	struct s_binarytree		*bintree_rooms;
	uint8_t					boundries;

	boundries = 0;
	while (get_next_line(STDIN_FILENO, &(input->line)))
	{
		if (ft_strchr(input->line, '-'))
		{
			if (!(boundries & START_ROOM))
				return (print_error(E_NO_START_ROOM));
			if (!(boundries & END_ROOM))
				return (print_error(E_NO_END_ROOM));
			if (rearrange_rooms_by_name(&bintree_rooms) == ERROR)
				return (ERROR);
			if (setup_rooms(bintree_rooms, farm) == ERROR)
				return (ERROR);
			return (SUCCESS);
		}
		else
			parse_line(&bintree_rooms, &boundries, farm, input);
		if (update_input(input) == ERROR)
			return (ERROR);
	}
	return (print_error(E_NO_LINKS));
}
