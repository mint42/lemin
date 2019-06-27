/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:42:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/26 21:06:30 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stddef.h>

typedef struct 		s_room	t_room;

typedef struct		s_input
{
	size_t			input_size;
	size_t			max_size;
	char			*input;
	char			*line;
}					t_input;


t_input				init_input();
void				update_input(t_input *input);
void				delete_input(t_input *input);

#endif
