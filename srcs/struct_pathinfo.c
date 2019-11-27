/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_pathinfo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 03:55:28 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 05:19:58 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		init_pathinfo(struct s_pathinfo **pathinfo)
{
	*pathinfo = (struct s_pathinfo *)ft_memalloc(sizeof(struct s_pathinfo));
	if (!(*pathinfo))
		return (print_error(E_ALLOC_ERROR));
	(*pathinfo)->pid_index = 0;
	(*pathinfo)->pid_bit = 0;
	(*pathinfo)->basepath_id = 0;
	(*pathinfo)->depth_level = 0;
	(*pathinfo)->pids_dni = 0;
	(*pathinfo)->s_pids_dni = 0;
	return (SUCCESS);
}

int		setup_pathinfo(struct s_pathinfo **pathinfo, struct s_solve *solve)
{
	*pathinfo = (struct s_pathinfo *)ft_memalloc(sizeof(struct s_pathinfo));
	if (!*pathinfo)
		return (print_error(E_ALLOC_ERROR));
	if (solve->max_pid_bit & 100000000000000000)
	{
		++(solve->max_pid_index);
		solve->max_pid_bit = 1;
	}
	else
		solve->max_pid_bit = solve->max_pid_bit << 1;
	(*pathinfo)->pid_index = solve->max_pid_index;
	(*pathinfo)->pid_bit = solve->max_pid_bit;
	(*pathinfo)->base_pid = solve->bfs_cur->pathinfo->base_pid;
	(*pathinfo)->depth_lvl = solve->bfs_cur->pathinfo->depth_lvl + 1;
	(*pathinfo)->pids_dni->size = solve->bfs_cur->pathinfo->pids_dni_size;
	(*pathinfo)->pids_dni->len = solve->bfs_cur->pathinfo->pids_dni_len;
	(*pathinfo)->pids_dni->pids = ft_memalloc(sizeof(size_t) *
			(*pathinfo)->pids_dni->size);
	if (!(*pathinfo)->pids_dni)
		return (print_error(E_ALLOC_ERROR));
	ft_memcpy((*pathinfo)->pids_dni->pids,
			solve->bfs_cur->pathinfo->pids_dni->pids,
			(*pathinfo)->pids_dni->len);
	return (0);
}

void	delete_pathinfo(struct s_pathinfo **pathinfo)
{
	if (*pathinfo && **pathinfo)
	{
		ft_memdel(&((*pathinfo)->pids_dni));
		ft_memdel((void **)pathinfo);
	}
}
