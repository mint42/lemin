/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:55:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/29 23:01:02 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stddef.h>

typedef struct s_binarytree		t_binarytree;
typedef struct s_input			t_input;
typedef struct s_farm			t_farm;
typedef struct s_room			t_room;

int		get_ants(t_input *input, size_t *ants);
int		get_rooms(t_input *input, t_binarytree **rooms, t_farm *farm);
int		get_links(t_input *input, t_farm *farm);


#endif
