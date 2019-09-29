/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 03:55:28 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/29 03:59:23 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_path_info		*init_path_info(t_bfs *bfs)
{
	t_path_info		*path_info;

	path_info = (t_path_info *)ft_memalloc(sizeof(t_path_info));
	if (!path_info)
		return (print_error(E_ALLOC_ERROR));
	path_info->pid_index = 0;
	path_info->pid_bit = 0;
	path_info->basepath_id = 0;
	path_info->depth_level = 0;
	path_info->pids_dni = 0;
	path_info->s_pids_dni = 0;
	return (path_info);
}

/*
**	void			delete_path_info(t_list *path_info_cur)
**	{
**		t_list	*cur;
**		t_list	*to_delete;
**	
**		if (path_info_cur)
**		{
**			to_delete = PATHSET(path_info_cur);
**			cur = PATHSET(path_info_cur)->prev;
**			cur->next = PATHSET(path_info_cur)->next;
**			ft_lstdelone(&(to_delete), delete_bfs_path());
**			ft_memdel((void **)&content);
**		}
**	}
*/

void			delete_path_info(t_path_info *path_info)
{
	if (path_info)
	{
		ft_memdel(&(path_info->pids_dni));
		ft_memdel((void **)&path_info);
	}
}
