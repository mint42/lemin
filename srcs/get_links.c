/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:09:59 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/26 15:01:22 by rreedy           ###   ########.fr       */
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
		return (1);
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

static int		add_link(size_t room, size_t link, t_room *farm)
{
	if (MLINKS(room) == 0)
		MLINKS(room) = 4;
	++(NLINKS(room));
	if (NLINKS(room) == MLINKS(room))
	{
		MLINKS(room) = MLINKS(room) * 2;
		if (copy_links(&(LINKS(room)), MLINKS(room)) == ERROR)
			return (1);
	}
	LINKS(room)[NLINKS(room) - 1] = link;
	return (0);
}

static int		find_room(char *name, size_t *room, t_room *farm, size_t nrooms)
{
	int		cmp;

	cmp = ft_strcmp(name, NAME(*room));
	if (!name)
		return (1);
	if (cmp > 0)
	{
		*room = (nrooms + *room) / 2;
		find_room(name, room, farm, nrooms);
	}
	if (cmp < 0)
	{
		*room = *room / 2;
		find_room(name, room, farm, nrooms / 2);
	}
	return (0);
}

static int		parse_line(char *line, t_room *farm, size_t nrooms)
{
	size_t		room1;
	size_t		room2;
	size_t		len;

	room1 = nrooms / 2;
	room2 = room1;
	len = ft_strlend(line, ' ');
	if (len > ft_strlen(line) - 3)
		return (1);
	line[len] = '\0';
	if (find_room(line, &room1, farm, nrooms) == ERROR)
		return (1);
	line[len] = ' ';
	if (line[len + 1] != '-' || line[len + 2] != ' ')
		return (1);
	if (find_room(line + (len + 3), &room2, farm, nrooms) == ERROR)
		return (1);
	if (add_link(room1, room2, farm) == ERROR)
		return (1);
	if (add_link(room2, room1, farm) == ERROR)
		return (1);
	return (0);
}
		
int				get_links(t_input *input, t_room *farm, size_t nrooms)
{
	if (!input || !farm)
		return (1);
	while (get_next_line(STDIN_FD, &(input->line)))
	{
		if (parse_line(input->line, farm, nrooms) == ERROR)
			return (1);
		update_input(input);
	}
	return (0);
}
