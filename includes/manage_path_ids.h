/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_path_ids.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 01:23:04 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 01:25:30 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_PATH_IDS
# define MANAGE_PATH_IDS

# include <stddef.h>

int		add_pid(size_t **array, size_t *size, size_t index, size_t bit);
int		realloc_pids_array(size_t **array, size_t *size, size_t new_min_size);

#endif
