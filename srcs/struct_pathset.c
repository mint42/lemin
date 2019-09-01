/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pathset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:09:56 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/01 02:06:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "pathsets.h"
#include "ft_mem.h"
#include "ft_list.h"
#include "ft_printf.h"

t_pathset	*init_pathset(t_bfs *bfs)
{
	t_pathset	*pathset;

	pathset = (t_pathset *)ft_memalloc(sizeof(t_pathset));
	if (!pathset)
		return (0);
	pathset->completed = 0;
	pathset->delimiter = 0;
	pathset->nmoves = 0;
	pathset->mpathlen = 0;
	pathset->npaths = 1;
	pathset->paths = ft_lstinit(bfs, 0);
	return (pathset);
}

void		delete_pathset(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
	{
		ft_printf("delete_pathset\n");
		/*
		**	ft_lstdel(&(content->paths), 0);
		**	ft_memdel((void **)&content);
		*/
	}
}
