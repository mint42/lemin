/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:09:59 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/05 14:42:39 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "farm.h"
#include "input.h"
#include "ft_fd.h"
#include "ft_str.h"
#include "ft_mem.h"
#include "get_next_line.h"
#include <sys/types.h>

static int		copy_links(size_t **links, size_t max_links)
{
	size_t	*new_links;
	size_t	i;

	new_links = (size_t *)ft_memalloc(sizeof(size_t) * max_links);
	if (!new_links)
		return (print_error(E_ALLOC_ERROR));
	max_links = max_links / 2;
	i = 0;
	while (i < max_links)
	{
		new_links[i] = *links[i];
		++i;
	}
	ft_memdel((void **)links);
	*links = new_links;
	return (0);
}

static int		add_link(size_t room, size_t link, t_room *graph)
{
	if (graph[room].mlinks == 0)
		graph[room].mlinks = 4;
	++(graph[room].nlinks);
	if (graph[room].nlinks == graph[room].mlinks)
	{
		graph[room].mlinks = graph[room].mlinks * 2;
		if (copy_links(&(graph[room].links), graph[room].mlinks) == ERROR)
			return (ERROR);
	}
	graph[room].links[graph[room].nlinks - 1] = link;
	return (0);
}

static int		find_room(char *name, size_t *room_id, t_farm *farm, ssize_t jump)
{
	int		cmp;

	if (!name)
		return (ERROR);
	cmp = ft_strcmp(name, (farm->graph)[*room_id].name);
	if (jump == -1 || (jump == 0 && farm->nrooms % 2 == 0))
		return ((cmp) ? ERROR : 0);
	if (jump == 0)
	{
		*room_id = *room_id + ((cmp) ? 1 : -1);
		find_room(name, room_id, farm, -1);
	}
	if (cmp > 0)
	{
		*room_id = *room_id + jump;
		find_room(name, room_id, farm, jump / 2);
	}
	if (cmp < 0)
	{
		*room_id = *room_id - jump;
		find_room(name, room_id, farm, jump / 2);
	}
	return (0);
}

static int		parse_line(char *line, t_farm *farm)
{
	size_t		room1_id;
	size_t		room2_id;
	size_t		len;

	room1_id = farm->nrooms / 2;
	room2_id = room1_id;
	len = ft_strlend(line, ' ');
	if (len > ft_strlen(line) - 4)
		return (print_error(E_INVALID_LINK_FORMAT));
	line[len] = '\0';
	if (find_room(line, &room1_id, farm, farm->nrooms / 2) == ERROR)
		return (E_LINK_GIVEN_DNE);
	line[len] = ' ';
	if (line[len + 1] != '-' || line[len + 2] != ' ')
		return (print_error(E_INVALID_LINK_FORMAT));
	if (find_room(line + len + 3, &room2_id, farm, farm->nrooms / 2) == ERROR)
		return (E_LINK_GIVEN_DNE);
	if (add_link(room1_id, room2_id, farm->graph) == ERROR)
		return (ERROR);
	if (add_link(room2_id, room1_id, farm->graph) == ERROR)
		return (ERROR);
	return (0);
}

int				get_links(t_input *input, t_farm *farm)
{
	if (!input || !farm || !farm->graph)
		return (ERROR);
	while (get_next_line(STDIN_FD, &(input->line)))
	{
		if (parse_line(input->line, farm) == ERROR)
			return (ERROR);
		update_input(input);
	}
	return (0);
}
