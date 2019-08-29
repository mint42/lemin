/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:53:48 by rreedy            #+#    #+#             */
/*   Updated: 2019/08/28 22:41:40 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

typedef struct s_farm	t_farm;
typedef struct s_paths	t_paths;

int		solve(t_farm *farm, t_paths *solution);
