/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:16:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/22 20:49:04 by rreedy           ###   ########.fr       */
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
	return (input);
}

static int	copy_input(char **input, size_t size)
{
	char	*new_input;

	new_input = ft_strnew(size);
	if (!new_input)
		return (1);
	new_input = ft_strncpy(new_input, *input, size);
	ft_strdel(input);
	*input = new_input;
	return (0);
}

int			update_input(t_input *input)
{
	size_t	len;
	size_t	i;

	if (!input)
		return (1);
	i = 0;
	len = ft_strlen(input->line);
	input->input_size = input->input_size + len;
	if (input->input_size > input->max_size)
	{
		input->max_size = input->max_size * 2;
		copy_input(&(input->input), input->max_size);
	}
	while (i < len)
	{
		input->input[len + i] = input->line[i];
		++i;
	}
	return (0);
}

void		delete_input(t_input *input)
{
	ft_strdel(&(*input).input);
	ft_strdel(&(*input).line);
}
