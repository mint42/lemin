/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:16:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/01 01:35:37 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "ft_mem.h"
#include "ft_str.h"

t_input			init_input(void)
{
	t_input		input;

	input.buff_size = 0;
	input.input_size = 0;
	input.line_size = 0;
	input.input = 0;
	input.line = 0;
	return (input);
}

static void		update_input_buff(t_input *input)
{
	char	*new_input;

	while (input->input_size + input->line_size > input->buff_size)
		input->buff_size = input->buff_size * 2;
	new_input = ft_strnew(input->buff_size);
	if (!new_input)
		return ;
	new_input = ft_strncpy(new_input, input->input, input->input_size);
	ft_strdel(&(input->input));
	input->input = new_input;
}

void			update_input(t_input *input)
{
	if (!input->line)
		return ;
	input->line_size = ft_strlen(input->line) + 1;
	if (!input->input)
	{
		input->buff_size = input->line_size * 2;
		input->input = ft_strnew(input->buff_size);
	}
	else if (input->input_size + input->line_size > input->buff_size)
		update_input_buff(input);
	ft_strncpy(input->input + input->input_size, input->line, input->line_size);
	input->input_size = input->input_size + input->line_size;
	input->input[input->input_size - 1] = '\n';
	ft_strdel(&input->line);
}
