/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:16:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/20 00:04:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "ft_mem.h"
#include "ft_str.h"

t_input		init_input()
{
	t_input		input;

	input.input_size = 0;
	input.max_size = 0;
	input.input = 0;
	input.line = 0;
}

int			update_input(t_input *input)
{
	size_t	len;

	len = ft_strlen(input->line);
	input->input_size = input->input_size + len;
	if (input->input_size > input->max_size)
	{
		input->max_size = input->max_size * 2;
		copy_input();
	}
	while ()
}

void		delete_input(t_input **input)
{
	if (*input)
	{
		ft_strdel(&(*room)->room_name);
		ft_memdel(&((*room)->paths_encountered));
		ft_memdel(&((*room)->adjacency_list));
		ft_memdel(room);
	}
}
