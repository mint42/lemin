/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 03:55:28 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 22:53:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_path_info		*init_path_info(struct s_bfs *bfs)
{
	struct s_path_info		*path_info;

	path_info = (struct s_path_info *)ft_memalloc(sizeof(struct s_path_info));
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

void			delete_path_info(struct s_path_info *path_info)
{
	if (path_info)
	{
		ft_memdel(&(path_info->pids_dni));
		ft_memdel((void **)&path_info);
	}
}
