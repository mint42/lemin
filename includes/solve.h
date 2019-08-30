/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:53:48 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/29 23:53:53 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

typedef struct s_farm		t_farm;
typedef struct s_list		t_list;
typedef struct s_pathset	t_pathset;
typedef struct s_bfs		t_bfs;

int		solve(t_farm *farm, t_bfs *bfs, char **solution);
int		search(t_bfs *cur, t_bfs *tail, t_farm *farm, size_t *delimiter);
int		update_pathsets(t_bfs *bfs, t_list *pathsets, t_pathset *solution,
			size_t *delimiter);
