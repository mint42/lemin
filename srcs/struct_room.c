/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:42:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/24 02:51:25 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_farm.h"
#include "struct_room.h"
#include "ft_mem.h"
#include "ft_str.h"

void		init_room(struct s_room *room)
{
	room->name = 0;
	room->len = 0;
	room->start_end = 0;
	room->nlinks = 0;
	room->mlinks = 0;
	room->links = 0;
	room->npaths_encountered = 0; room->mpaths_encountered = 0;
	room->paths_encountered = 0;
}

void		delete_room(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
	{
		if (((struct s_room *)(content))->name)
			ft_strdel(&((struct s_room *)(content))->name);
		if (((struct s_room *)(content))->links)
			ft_memdel((void **)&((struct s_room *)(content))->links);
	}
}
