/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:09:59 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/03 17:03:38 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "farm.h"
#include "input.h"
#include "ft_fd.h"
#include "ft_str.h"
#include "ft_mem.h"
#include "get_next_line.h"
#include <stddef.h>

static int		copy_links(size_t **links, size_t max_links)
{
	size_t	*new_links;
	size_t	i;

	new_links = (size_t *)ft_memalloc(sizeof(size_t) * max_links);
	if (!new_links)
		return (ERROR);
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

static int		find_room(char *name, size_t *room, t_room *graph, size_t nrooms)
{
	int		cmp;

	cmp = ft_strcmp(name, graph[*room].name);
	if (!name)
		return (ERROR);
	if (cmp > 0)
	{
		*room = (nrooms + *room) / 2;
		find_room(name, room, graph, nrooms);
	}
	if (cmp < 0)
	{
		*room = *room / 2;
		find_room(name, room, graph, nrooms / 2);
	}
	return (0);
}

static int		parse_line(char *line, t_room *graph, size_t nrooms)
{
	size_t		room1;
	size_t		room2;
	size_t		len;

	room1 = nrooms / 2;
	room2 = room1;
	len = ft_strlend(line, ' ');
	if (len > ft_strlen(line) - 3)
		return (ERROR);
	line[len] = '\0';
	if (find_room(line, &room1, graph, nrooms) == ERROR)
		return (ERROR);
	line[len] = ' ';
	if (line[len + 1] != '-' || line[len + 2] != ' ')
		return (ERROR);
	if (find_room(line + (len + 3), &room2, graph, nrooms) == ERROR)
		return (ERROR);
	if (add_link(room1, room2, graph) == ERROR)
		return (ERROR);
	if (add_link(room2, room1, graph) == ERROR)
		return (ERROR);
	return (0);
}

int				get_links(t_input *input, t_farm *farm)
{
	if (!input || !farm || !farm->graph)
		return (ERROR);
	while (get_next_line(STDIN_FD, &(input->line)))
	{
		if (parse_line(input->line, farm->graph, farm->nrooms) == ERROR)
			return (ERROR);
		update_input(input);
	}
	return (0);
}
