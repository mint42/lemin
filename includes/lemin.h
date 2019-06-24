/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:55:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/21 20:58:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stddef.h>

typedef struct s_input	t_input;
typedef struct s_room	t_room;

int		get_ants(t_input *input, size_t *ants);
int		get_rooms(t_input *input, t_room **farm, size_t *nrooms);
int		get_links(t_input *input, t_room *farm, size_t	nrooms);


#endif
