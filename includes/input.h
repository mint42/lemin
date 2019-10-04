/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:42:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 01:08:01 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stddef.h>

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
