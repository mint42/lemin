/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:42:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/19 23:28:04 by rreedy           ###   ########.fr       */
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
	char			**input;
	char			*line;
}					t_input;

int					get_ants(t_input *input, size_t *ants);
int					get_rooms(t_input *input, t_room **farm, size_t *nrooms);
int					get_links(t_input *input, t_room **farm, size_t	*nrooms);

#endif
