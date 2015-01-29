/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_increment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 06:48:21 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/21 06:45:53 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pt2d		ft_make_increment(t_env env, double angle, char axe)
{
	t_pt2d	pi;

	if (axe == 'h')
	{
		if (angle == 90 || angle == 270)
			pi.x = 0;
		else
			pi.x = env.sz_wall / tan(ft_dtor(angle));
		if (angle > 180 && angle < 360)
			pi.x = -pi.x;
		pi.y = env.sz_wall;
		if (angle > 0 && angle < 180)
			pi.y = -pi.y;
	}
	else if (axe == 'v')
	{
		if (angle == 0 || angle == 180)
			pi.y = 0;
		else
			pi.y = env.sz_wall * -tan(ft_dtor(angle));
		if (angle > 90 && angle < 270)
			pi.y = -pi.y;
		pi.x = env.sz_wall;
		if ((angle > 90 && angle < 270))
			pi.x = -pi.x;
	}
	return (pi);
}
