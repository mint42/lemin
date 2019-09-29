/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:42:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/29 06:10:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stddef.h>

typedef struct s_room	t_room;

typedef struct		s_input
{
	size_t			buff_size;
	size_t			input_size;
	size_t			line_size;
	char			*input;
	char			*line;
}					t_input;

int					init_input(t_input **input);
void				update_input(t_input *input);
void				delete_input(t_input **input);

#endif
