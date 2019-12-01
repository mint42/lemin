/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:16:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/27 13:15:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_input.h"
#include "ft_mem.h"
#include "ft_str.h"

void		init_input(struct s_input *input)
{
	input->buff_size = 0;
	input->input_size = 0;
	input->line_size = 0;
	input->input = 0;
	input->line = 0;
}

static int	update_input_buff(struct s_input *input)
{
	char	*new_input;

	while (input->input_size + input->line_size > input->buff_size)
		input->buff_size = input->buff_size * 2;
	new_input = ft_strnew(input->buff_size);
	if (!new_input)
		return (print_error(E_ALLOC));
	new_input = ft_strncpy(new_input, input->input, input->input_size);
	ft_strdel(&(input->input));
	input->input = new_input;
}

void		update_input(struct s_input *input)
{
	if (!input->line)
		return ;
	input->line_size = ft_strlen(input->line) + 1;
	if (!input->input)
	{
		input->buff_size = input->line_size * 2;
		input->input = ft_strnew(input->buff_size);
		if (!input->input)
			return (print_error(E_ALLOC));
	}
	else if (input->input_size + input->line_size > input->buff_size)
	{
		if (update_input_buff(input) == ERROR)
			return (ERROR);
	}
	ft_strncpy(input->input + input->input_size, input->line, input->line_size);
	input->input_size = input->input_size + input->line_size;
	input->input[input->input_size - 1] = '\n';
	ft_strdel(&input->line);
}
