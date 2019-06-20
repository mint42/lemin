/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:09:59 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/19 22:25:56 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		new_links[i] = links[i];
		++i;
	}
	ft_memdel(links);
	*links = new_links;
	return (0);
}

static int		add_links(size_t roomi1, size_t roomi2, t_room *farm)
{
	if (farm[roomi1]->mlinks == 0)
		farm[roomi1]mlinks == 4;
	++(farm[roomi1]->nlinks);
	if (farm[roomi1]->nlinks == farm[roomi1]->mlinks)
	{
		farm[roomi1]->mlinks = farm[roomi1]->mlinks * 2;
		if (copy_links(&(farm[roomi1]->links), farm[roomi1]->mlinks) == ERROR)
			return (1);
	}
	farm[room1]->links[nlinks - 1] = roomi2;
	return (0);
}

static int		find_room(char *room, size_t *roomi, t_room *farm, size_t nrooms)
{
	if (!farm || !room)
		return (1);
	if (ft_strcmp(room, farm->room_name) > 0)
	{
		*roomi = (nrooms + *roomi) / 2;
		find_room(room, roomi, farm, nrooms);
	}
	if (ft_strcmp(room, farm->room_name) < 0)
	{
		*roomi = *roomi / 2;
		find_room(room, roomi, farm, nrooms / 2);
	}
	return (0);
}

static int		parse_line(char *line, t_room *farm, size_t nrooms)
{
	size_t		roomi1;
	size_t		roomi2;
	size_t		lend;

	roomi1 = nrooms / 2;
	roomi2 = nrooms / 2;
	lend = ft_strlend(line, ' ');
	if (lend > ft_strlen(line) - 3)
		return (1);
	line[lend] = '\0';
	if (find_room(line, &room1, farm, nrooms) == ERROR)
		return (1);
	line[lend] = ' ';
	if (line[lend + 1] != '-' || line[lend + 2] != ' ')
		return (1);
	if (find_room(line + (lend + 3), &room2, farm, nrooms) == ERROR)
		return (1);
	if (add_links(room1, room2, farm) == ERROR)
		return (1);
	if (add_links(room2, room1, farm) == ERROR)
		return (1);
}
		
int				get_links(t_input *input, t_room *farm, size_t nrooms)
{
	while (get_next_line(&(input->line)))
	{
		if (parse_line() == ERROR)
		{
			return (1);
		}
		update_input(input);
	}
	return (0);
}
