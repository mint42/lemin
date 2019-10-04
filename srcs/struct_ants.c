/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 02:02:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 22:53:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		defragment(size_t *i, struct s_ant *ants_on_line, size_t n_ants_on_line)
{
	size_t	j;

	while (*i < n_ants_on_line)
	{
		if (ants_on_line[*i]->location == 0)
		{
			j = i + 1;
			while (j < n_ants_on_line && ants_on_line[j]->location == 0)
				++j;
			if (j >= n_ants_on_line)
				return ;
			ants_on_line[*i]->ant_num = ants_on_line[j]->ant_num;
			ants_on_line[*i]->ant_numlen = ants_on_line[j]->ant_numlen;
			ants_on_line[*i]->location = ants_on_line[j]->location;
			ants_on_line[j]->location = 0;
		}
		++(*i);
	}
}
void		update_ants(size_t *ant_number, struct s_ant *ants_on_line, size_t n_ants_on_line, struct pathset *solution)
{
	static size_t	path_num;
	static size_t	current_max;
	size_t			i;

	i = 0;
	if (*ant_number != 0)
		defragment(&i, ants_on_line, n_ants_on_line);
	while (i < n_ants_on_line)
	{
		++(*ant_number);
		++path_num;
		if (path_num == current_max)
		{
			if (current_max < solution->s_min_ant_num_for_path &&
				*ant_number >= solution->min_ant_num_for_path[current_max])
				++current_max;
			else 
				path = 1;
		}
		ants_on_line[i]->ant_num = ant_num;
		ants_on_line[i]->ant_numlen = ft_numlen(ants_on_line[i]->ant_num);
		ants_on_line[i]->location = solution->paths[path_num];
		++i;
	}
}

int			setup_ants(struct s_ants **ants_on_line, size_t n_ants_on_line, struct s_pathset *solution)
{
	size_t	i;

	*ants_on_line = (ant *)ft_memalloc(sizeof(ant) * n_ants_on_line);
	if (!ants_on_line)
		return (print_error(E_ALLOC_ERROR));
	i = 0;
	while (i < n_ants_on_line)
	{
		(*ants_on_line)[i]->ant_number = 0;
		(*ants_on_line)[i]->location = 0;
		++i;
	}
	return (0);
}
