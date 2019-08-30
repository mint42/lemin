/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:53:48 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/30 13:00:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

typedef struct s_farm		t_farm;
typedef struct s_list		t_list;
typedef struct s_pathset	t_pathset;
typedef struct s_bfs		t_bfs;

int		solve(t_farm *farm, char **solution);
int		search(t_bfs *cur, t_bfs *tail, t_farm *farm, size_t *delimiter);
int		update_pathsets(t_bfs *bfs, t_list *pathsets, t_pathset *solution,
			size_t *delimiter);
