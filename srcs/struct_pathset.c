/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pathset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:09:56 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 22:53:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "pathsets.h"
#include "ft_mem.h"
#include "ft_list.h"
#include "ft_printf.h"

struct s_pathset	*init_pathset(struct s_bfs *bfs)
{
	struct s_pathset	*pathset;

	pathset = (struct s_pathset *)ft_memalloc(sizeof(struct s_pathset));
	if (!pathset)
		return (0);
	pathset->nmoves = 0;
	pathset->minpathlen = 0;
	pathset->maxpathlen = 0;
	pathset->npaths = 1;
	pathset->paths = 0;
	return (pathset);
}

void		delete_pathset(struct s_list *pathsets_cur)
{
	struct s_list	*cur;
	struct s_list	*to_delete;
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
