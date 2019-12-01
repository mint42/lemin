/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:22:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/30 12:23:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "struct_farm.h"
#include "struct_pathinfo.h"
#include "struct_bfs_node.h"
#include "struct_solve.h"
#include "ft_mem.h"

//#include "errors.h"
//#include "lemin.h"
//#include "struct_basepath.h"
//#include "struct_bfs_node.h"
//#include "struct_farm.h"
//#include "struct_path_info.h"
//#include "struct_room.h"
//#include "struct_solve.h"
//#include "ft_mem.h"
//#include <stddef.h>
//#include <stdint.h>

int				setup_bfs_queue(struct s_solve *solve, struct s_farm *farm)
{
	if (init_bfs_node(&(solve->bfs_head)) == ERROR)
		return (ERROR);
	if (init_pathinfo(&(solve->bfs_head->pathinfo)) == ERROR)
		return (ERROR);
	(solve->bfs_head)->pathinfo->pid_bit = 1;
	(solve->bfs_head)->rid = farm->start_rid;
	if (init_bfs_node(&((solve->bfs_head)->next)) == ERROR)
		return (ERROR);
	if (init_pathinfo(&(solve->bfs_head->next->pathinfo)) == ERROR)
		return (ERROR);
	solve->bfs_tail = solve->bfs_head->next;
	(solve->bfs_tail)->prev = solve->bfs_head;
	(solve->bfs_tail)->pathinfo->pid_bit = 2;
	(solve->bfs_tail)->rid = farm->end_rid;
	return (0);
}

static void		inspect_link(struct s_room *link, struct s_solve *solve,
						uint8_t *path_status)
{
	struct s_basepath	basepath;
	size_t				i;

	i = 0;
	basepath = (solve->basepaths)[solve->bfs_cur->path_info->base_pid];
	while (*path_status == IN_PROGRESS && i < link->pids_met_len && i < basepath.child_pids_len && i < solve->start_pids_len)
	{
		if (link->pids_met[i] & basepath.child_pids[i])
			*path_status = DROPPED;
		if ((basepath.origin == START_ROOM) && (link->pids_met[i] & ~solve->start_pids[i]))
			*path_status = COMPLETED;
		else if ((basepath.origin == END_ROOM) && (link->pids_met[i] & solve->start_pids[i]))
			*path_status = COMPLETED;
		++i;
	}
}

int				update_bfs_queue(struct s_solve *solve, struct s_farm *farm,
						uint8_t *path_status)
{
	static size_t	i;
	struct s_room	room;
	struct s_bfs	*new_node;

	room = (farm->graph)[solve->bfs_cur->rid];
	while (i < room.nlinks)
	{
		if (room.links[i] != solve->bfs_cur->rid)
		{
			inspect_link(&((farm->graph)[room.links[i]]), solve, path_status);
			if (*path_status != IN_PROGRESS)
				return (0);
			if (setup_bfs_node(&new_node, solve, farm, i) == ERROR)
				return (ERROR);
			solve->bfs_tail->next = new_node;
			new_node->prev = solve->bfs_tail;
			new_node->path_prev = solve->bfs_cur;
			solve->bfs_tail = new_node;
		}
		++i;
	}
	i = 0;
	return (0);
}

/*
**	TODO: move bfs cursor
*/

void			delete_bfs_path(struct s_solve *solve)
{
	struct s_bfs_node	*cur;
	struct s_bfs_node	*to_delete;

	cur = solve->bfs_cur;
	while (cur->path_prev &&
			cur->pathinfo->pid_index == solve->bfs_cur->pathinfo->pid_index &&
			cur->pathinfo->pid_bit == solve->bfs_cur->pathinfo->pid_bit)
	{
		to_delete = cur;
		cur = cur->path_prev;
		delete_bfs_node(&to_delete);
	}
	cur = solve->bfs_cur;
	while (cur->path_next &&
			cur->pathinfo->pid_index == solve->bfs_cur->pathinfo->pid_index &&
			cur->pathinfo->pid_bit == solve->bfs_cur->pathinfo->pid_bit)
	{
		to_delete = cur;
		cur = cur->path_next;
		delete_bfs_node(&to_delete);
	}
	delete_bfs_node(&(solve->bfs_cur));
}
