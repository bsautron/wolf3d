/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 15:46:36 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/27 08:50:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static double	ft_hit_horizontal(t_env *env, double angle)
{
	t_pt2d	pa;
	t_pt2d	pi;
	t_pt2d	pn;
	t_pt2d	pcase;

	if (angle > 0 && angle < 180)
		pa.y = floor(env->bruno.pos.y / env->sz_wall) * env->sz_wall - 0.000001;
	else
		pa.y = floor(env->bruno.pos.y / env->sz_wall)
			* env->sz_wall + env->sz_wall;
	pa.x = env->bruno.pos.x + (env->bruno.pos.y - pa.y) / tan(ft_dtor(angle));
	pn.y = pa.y;
	pn.x = pa.x;
	pi = ft_make_increment(*env, angle, 'h');
	pcase = ft_minicase(*env, pn);
	while (pcase.x > 0 && pcase.y > 0 && pcase.x < env->w_minimap && pcase.y <
			env->h_minimap && env->map[(int)pcase.y][(int)pcase.x].obs == 0)
	{
		pn.y = pn.y + pi.y;
		pn.x = pn.x + pi.x;
		pcase = ft_minicase(*env, pn);
	}
	env->hit_h = pn;
	return (
	sqrt(pow(env->bruno.pos.x - pn.x, 2) + pow(env->bruno.pos.y - pn.y, 2)));
}

static double	ft_hit_vertical(t_env *env, double angle)
{
	t_pt2d	pa;
	t_pt2d	pi;
	t_pt2d	pn;
	t_pt2d	pcase;

	if (angle < 90 || angle > 270)
		pa.x = floor(env->bruno.pos.x / env->sz_wall)
			* env->sz_wall + env->sz_wall;
	else
		pa.x = floor(env->bruno.pos.x / env->sz_wall) * env->sz_wall - 0.000001;
	pa.y = env->bruno.pos.y + (env->bruno.pos.x - pa.x) * tan(ft_dtor(angle));
	pn.y = pa.y;
	pn.x = pa.x;
	pcase = ft_minicase(*env, pn);
	pi = ft_make_increment(*env, angle, 'v');
	while (pcase.x > 0 && pcase.y > 0 && pcase.x < env->w_minimap && pcase.y <
			env->h_minimap && env->map[(int)pcase.y][(int)pcase.x].obs == 0)
	{
		pn.y = pn.y + pi.y;
		pn.x = pn.x + pi.x;
		pcase = ft_minicase(*env, pn);
	}
	env->hit_v = pn;
	return (
	sqrt(pow(env->bruno.pos.x - pn.x, 2) + pow(env->bruno.pos.y - pn.y, 2)));
}

double			ft_calcul(t_env *env, double angle)
{
	double		wall_horizontal;
	double		wall_vertical;
	double		d;

	wall_horizontal = ft_hit_horizontal(env, angle);
	wall_vertical = ft_hit_vertical(env, angle);
	if (wall_horizontal < wall_vertical)
	{
		d = wall_horizontal;
		env->hit = env->hit_h;
		env->vorh = 'h';
	}
	else
	{
		d = wall_vertical;
		env->hit = env->hit_v;
		env->vorh = 'v';
	}
	return (d);
}
