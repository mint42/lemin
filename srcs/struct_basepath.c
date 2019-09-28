/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_basepath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 01:20:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/28 01:06:22 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_basepath(t_basepath *basepath)
{
	basepath->start_or_end = 0;
	basepath->base_path_id = 0;
	basepath->paths_in_base = 0;
	basepath->npaths_in_base = 0;
	basepath->mpaths_in_base = 0;
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
		(solve->basepaths)->mpaths_in_base = SQUARE(solve->npaths_delimiter) / NBITS_SIZE_T;
		(solve->basepaths)[i]->origin = START;
		(solve->basepaths)[i]->npaths = (farm->rooms)[farm->start_rid]->nlinks;
		++i;
		(solve_basepaths)[i]->basepath_id = i;
		(solve_startpaths)[i / 64] = (solve_startpaths)[i / 64] & (1 << i % 64);
	}
	while (i < solve->nbasepaths)
	{
		init_basepath(solve->basepaths[i]);
		(solve->basepaths)->mpaths_in_base = SQUARE(solve->npaths_delimiter) / NBITS_SIZE_T;
		(solve->basepaths)[i]->origin = END;
		(solve->basepaths)[i]->npaths = (farm->graph)[farm->end_rid]->nlinks;
		++i;
		(solve_basepaths)[i]->basepath_id = i;
	}
}

