/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 20:32:16 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/28 20:09:36 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_draw_column(t_env *env, double alpha, int x)
{
	double		d;
	double		y;
	double		h;
	double		sol;
	double		plafond;

	y = env->mid;
	if (alpha >= 360)
		alpha -= 360;
	if (alpha < 0)
		alpha += 360;
	d = ft_calcul(*env, alpha);
	d = d * cos(ft_dtor(env->bruno.angle - alpha));
	h = env->sz_wall / d * env->bruno.d_proj;
	while (y <= env->h_win - 1 && y - env->mid < h / 2)
	{
		env->char_img[x * 4 + (int)y * env->size_line] = 0xFF;
		env->char_img[x * 4 + (int)y * env->size_line + 1] = 0xFF;
		env->char_img[x * 4 + (int)y * env->size_line + 2] = 0xFF;
		y++;
	}
	y = env->mid;
	while (y >= 0 && y - env->mid > -h / 2)
	{
		env->char_img[x * 4 + (int)y * env->size_line] = 0xFF;
		env->char_img[x * 4 + (int)y * env->size_line + 1] = 0xFF;
		env->char_img[x * 4 + (int)y * env->size_line + 2] = 0xFF;
		y--;
	}
	sol = env->h_win;
	while (sol > env->mid + h / 2)
	{
		env->char_img[x * 4 + (int)sol * env->size_line] = 0x20;
		env->char_img[x * 4 + (int)sol * env->size_line + 1] = 0x20;
		env->char_img[x * 4 + (int)sol * env->size_line + 2] = 0x60;
		sol--;
	}
	plafond = 0;
	while (plafond < env->mid - h / 2)
	{
		env->char_img[x * 4 + (int)plafond * env->size_line] = 0x0;
		env->char_img[x * 4 + (int)plafond * env->size_line + 1] = 0x50;
		env->char_img[x * 4 + (int)plafond * env->size_line + 2] = 0x0;
		plafond++;
	}
}

void	ft_draw(t_env *env)
{
	double	alpha;
	size_t	x;

	alpha = env->bruno.angle + 30;
	x = 0;
	while (x < env->w_win)
	{
		ft_draw_column(env, alpha, x);
		alpha = alpha - env->i_angle;
		x++;
	}
}
