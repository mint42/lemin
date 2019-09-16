/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_basepath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 01:20:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/09/16 02:48:22 by rreedy           ###   ########.fr       */
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
