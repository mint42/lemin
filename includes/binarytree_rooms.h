#ifndef BINARYTREE_ROOMS_H
# define  BINARYTREE_ROOMS_H

struct s_binarytree;
struct s_room;

int 	rearrange_rooms_by_name(struct s_binarytree **rooms_by_coordinate);
int		insert_room_by_name(struct s_binarytree **rooms,
				struct s_binarytree *room);
int		insert_room_by_coordinates(struct s_binarytree **rooms,
				struct s_room *room);

#endif
