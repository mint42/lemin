/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_input.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:15:19 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 06:27:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INPUT_H
# define STRUCT_INPUT_H

# include <stddef.h>

/*
**	s_input is a struct storing information about the data being sent into the
**	program.
**
**	input			String of the entire input, dynamically allocated as it is
**					being read into the input buffer
**	line			Buffer used to grab the next line from stdin
**	input_len		Current length of the input string
**	input_size		Total allocated size of the input string
**	line_size		Length of the buffer string
*/

struct			s_input
{
	char		*input;
	char		*line;
	size_t		input_len;
	size_t		input_size;
	size_t		line_len;
};

int				init_input(struct s_input *input);
void			update_input(struct s_input *input);

#endif
