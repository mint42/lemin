/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_basepath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 01:20:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/04 01:58:13 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_basepath(t_basepath *basepath)
{
	basepath->origin = 0;
	basepath->child_pids = 0;
	basepath->child_pids_size = 0;
}

int		setup_basepaths(t_solve *solve, t_farm *farm)
{
	size_t	i;

	solve->basepaths = (size_t *)ft_memalloc(sizeof(size_t) * solve->nbasepaths);
	if (!solve->basepaths)
		return (print_error(E_ALLOC_ERROR));
	i = 0;
	while (i < (farm->graph)[farm->start_rid]->nlinks)
	{
		init_basepath(solve->basepaths[i]);
		(solve->basepaths)->child_pids_size = SQUARE(solve->npaths_delimiter) / NBITS_SIZE_T;
		(solve->basepaths)[i]->origin = START;
		++i;
		(solve->start_pids)[i / 64] = (solve->start_pids)[i / 64] & (1 << i % 64);
	}
	while (i < solve->nbasepaths)
	{
		init_basepath(solve->basepaths[i]);
		(solve->basepaths)->child_pids_size = SQUARE(solve->npaths_delimiter) / NBITS_SIZE_T;
		(solve->basepaths)[i]->origin = END;
		++i;
	}
}

