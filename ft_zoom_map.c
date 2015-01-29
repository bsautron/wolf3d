/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 06:40:14 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/20 22:12:37 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_zoom_map(t_env *env)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < env->h_map)
	{
		j = 0;
		while (j < env->w_map)
		{
			env->map[i][j].c.x *= env->sz_wall;
			env->map[i][j].c.y *= env->sz_wall;
			j++;
		}
		i++;
	}
}
