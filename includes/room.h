/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:38:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:22:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

# include <stddef.h>
# include <stdint.h>

# define ROOM(binarytree) ((struct s_room *)((binarytree)->content))

# define START_ROOM 1
# define END_ROOM 2

struct			s_room
{
	uint8_t		start_end;
	int			x;
	int			y;
	char		*name;
	size_t		len;
	size_t		*links;
	size_t		nlinks;
	size_t		mlinks;
	size_t		*paths_encountered;
	size_t		npaths_encountered;
	size_t		mpaths_encountered;
};

struct s_room	*init_room(void);
int				rearrange_rooms_by_name(struct s_binarytree **rooms_by_coordinte);
int				insert_room_by_coordinates(struct s_binarytree **rooms, struct s_room *room);
int				insert_room_by_name(struct s_binarytree **rooms, struct s_binarytree *room);
void			delete_room(void *content, size_t content_size);

#endif
