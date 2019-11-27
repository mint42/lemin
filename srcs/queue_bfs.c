#include "errors.h"
#include "struct_farm.h"
#include "struct_pathinfo.h"
#include "struct_bfs_node.h"
#include "struct_solve.h"
#include "ft_mem.h"

int		setup_bfs(struct s_solve *solve, struct s_farm *farm)
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

/*
**	move bfs cursor
*/

void	delete_bfs_path(struct s_solve *solve)
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
