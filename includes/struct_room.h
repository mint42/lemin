/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_room.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 00:18:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 00:18:30 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ROOM_H
# define STRUCT_ROOM_H

//# include <stdint.h>

# define ROOM(binarytree) ((struct s_room *)((binarytree)->content))

# define START_ROOM 1
# define END_ROOM 2

struct			s_binarytree;

struct			s_room
{
	uint8_t		start_end;
	int			x;
	int			y;
	char		*name;
	size_t		len;
	size_t		*links;
	size_t		nlinks;
	size_t		links_size;
	size_t		*pids_met;
	size_t		pids_met_len;
	size_t		pids_met_size;
};

struct s_room	*init_room(void);
int				rearrange_rooms_by_name(struct s_binarytree **rooms_by_coord);
int				insert_room_by_coordinates(struct s_binarytree **rooms,
						struct s_room *room);
int				insert_room_by_name(struct s_binarytree **rooms,
						struct s_binarytree *room);
void			delete_room(void *content, size_t content_size);

#endif
