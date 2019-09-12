/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:09:59 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/11 22:27:28 by rreedy           ###   ########.fr       */
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
		new_links[i] = (*links)[i];
		++i;
	}
	ft_memdel((void **)links);
	*links = new_links;
	return (0);
}

static int		add_link(size_t room_id, size_t link_id, t_room *graph)
{
	if (graph[room_id].mlinks == 0)
	{
		graph[room_id].mlinks = 4;
		graph[room_id].links = (size_t *)ft_memalloc(sizeof(size_t) * graph[room_id].mlinks);
	}
	++(graph[room_id].nlinks);
	if (graph[room_id].nlinks == graph[room_id].mlinks)
	{
		graph[room_id].mlinks = graph[room_id].mlinks * 2;
		if (copy_links(&(graph[room_id].links), graph[room_id].mlinks) == ERROR)
			return (ERROR);
	}
	graph[room_id].links[graph[room_id].nlinks - 1] = link_id;
	return (0);
}

static int		find_room(char *name, t_farm *farm, size_t *room_id, size_t max)
{
	int		cmp;
	size_t	mid;

	if (max < 1)
		return (print_error(E_LINK_GIVEN_DNE));
	mid = *room_id + (max - *room_id) / 2;
	cmp = ft_strncmp(name, (farm->graph)[mid].name, (farm->graph)[mid].len + 1);
	if (cmp > 0)
	{
		*room_id = mid + 1;
		find_room(name, farm, room_id, max);
	}
	if (cmp < 0)
		find_room(name, farm, room_id, mid - 1);
	*room_id = mid;
	return (0);
}

static int		parse_line(char *line, t_farm *farm)
{
	size_t		room1_id;
	size_t		room2_id;
	size_t		len;

	if (*line == '#')
		return (0);
	if (ft_strchr(line, ' '))
		return (print_error(E_INVALID_LINK_FORMAT));
	len = ft_strlend(line, '-');
	if (len == ft_strlen(line))
		return (print_error(E_INVALID_LINK_FORMAT));
	line[len] = '\0';
	room1_id = 0;
	if (find_room(line, farm, &room1_id, farm->nrooms - 1) == ERROR)
		return (ERROR);
	line[len] = '-';
	room2_id = 0;
	if (find_room(line + len + 1, farm, &room2_id, farm->nrooms - 1) == ERROR)
		return (ERROR);
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
	if (parse_line(input->line, farm) == ERROR)
		return (ERROR);
	update_input(input);
	while (get_next_line(STDIN_FD, &(input->line)))
	{
		if (parse_line(input->line, farm) == ERROR)
			return (ERROR);
		update_input(input);
	}
	return (0);
}
