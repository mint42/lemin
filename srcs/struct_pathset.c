/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pathset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:09:56 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/29 06:10:25 by rreedy           ###   ########.fr       */
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
	pathset->nmoves = 0;
	pathset->minpathlen = 0;
	pathset->maxpathlen = 0;
	pathset->npaths = 1;
	pathset->paths = 0;
	return (pathset);
}

void		delete_pathset(t_list *pathsets_cur)
{
	t_list	*cur;
	t_list	*to_delete;
	size_t	i;

	if (pathsets_cur)
	{
		cur = PATHSET(pathsets_cur)->prev;
		cur->next = PATHSET(pathsets_cur)->next;
		to_delete = PATHSET(pathsets_cur);
		ft_listdel(PATHSET(pathsets_cur)->paths, delete_bfs_path());
		ft_memdel((void **)&to_delete);
	}
}
