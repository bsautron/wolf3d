/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_increment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 06:48:21 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/31 07:05:08 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_pt2d		ft_h(t_env env, double angle)
{
	t_pt2d	pi;

	if (angle == 90 || angle == 270)
		pi.x = 0;
	else
		pi.x = env.sz_wall / tan(ft_dtor(angle));
	if (angle > 180 && angle < 360)
		pi.x = -pi.x;
	pi.y = env.sz_wall;
	if (angle > 0 && angle < 180)
		pi.y = -pi.y;
	return (pi);
}

static t_pt2d		ft_v(t_env env, double angle)
{
	t_pt2d	pi;

	if (angle == 0 || angle == 180)
		pi.y = 0;
	else
		pi.y = env.sz_wall * -tan(ft_dtor(angle));
	if (angle > 90 && angle < 270)
		pi.y = -pi.y;
	pi.x = env.sz_wall;
	if ((angle > 90 && angle < 270))
		pi.x = -pi.x;
	return (pi);
}

t_pt2d				ft_make_increment(t_env env, double angle, char axe)
{
	t_pt2d	pi;

	if (axe == 'h')
		pi = ft_h(env, angle);
	else if (axe == 'v')
		pi = ft_v(env, angle);
	return (pi);
}
