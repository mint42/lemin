#ifndef QUEUE_BFS_H
# define QUEUE_BFS_H

struct s_farm;
struct s_solve;

int		setup_bfs(struct s_solve *solve, struct s_farm *farm);
void	delete_bfs_path(struct s_solve *solve);
int		update_bfs_queue(struct s_solve *solve, struct s_farm *farm,
				uint8_t *path_status);

#endif
