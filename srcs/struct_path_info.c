/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 03:55:28 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 05:19:58 by rreedy           ###   ########.fr       */
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

static int		setup_path_info(struct s_path_info **path_info, struct s_solve *solve)
{
	*path_info = (struct s_path_info *)ft_memalloc(sizeof(struct s_path_info));
	if (!*path_info)
		return (print_error(E_ALLOC_ERROR));
	if (solve->max_pid_bit & 100000000000000000)
	{
		++(solve->max_pid_index);
		solve->max_pid_bit = 1;
	}
	else
		solve->max_pid_bit = solve->max_pid_bit << 1;
	(*path_info)->pid_index = solve->max_pid_index;
	(*path_info)->pid_bit = solve->max_pid_bit;
	(*path_info)->base_pid = solve->bfs_cur->path_info->base_pid;
	(*path_info)->depth_lvl = solve->bfs_cur->path_info->depth_lvl + 1;
	(*path_info)->pids_dni_size = solve->bfs_cur->path_info->pids_dni_size;
	(*path_info)->pids_dni_len = solve->bfs_cur->path_info->pids_dni_len;
	(*path_info)->pids_dni = ft_memalloc(sizeof(size_t) * (*path_info)->pids_dni_size);
	if (!(*path_info)->pids_dni)
		return (print_error(E_ALLOC_ERROR));
	ft_memcpy((*path_info)->pids_dni, solve->bfs_cur->path_info->pids_dni, (*path_info)->pids_dni_len);
	return (0);
}

void			delete_path_info(struct s_path_info *path_info)
{
	if (path_info)
	{
		ft_memdel(&(path_info->pids_dni));
		ft_memdel((void **)&path_info);
	}
}
