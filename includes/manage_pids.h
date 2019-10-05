/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pids.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 01:04:45 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/05 01:04:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_PIDS
# define MANAGE_PIDS

# include <stddef.h>

int		add_pid(size_t **array, size_t *size, size_t index, size_t bit);
int		realloc_pids_array(size_t **array, size_t *size, size_t new_min_size);

#endif
