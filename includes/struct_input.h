/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_input.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:15:19 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 00:15:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INPUT_H
# define STRUCT_INPUT_H

//# include <stdint.h>

struct			s_input
{
	size_t		input_size;
	size_t		input_len;
	size_t		line_len;
	char		*input;
	char		*line;
};

int				init_input(struct s_input *input);
void			update_input(struct s_input *input);
void			delete_input(struct s_input *input);

#endif
