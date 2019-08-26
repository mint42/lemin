/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pathset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:09:56 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/26 14:45:11 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_pathset	*init_pathset(t_bfs *path)
{
	t_pathset	*pathset;

	pathset = (t_pathset *)ft_memalloc(sizeof(t_pathset));
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
		ft_lstdel((*content)->paths);
		ft_memdel((void **)&content);
	}
}
