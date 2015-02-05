/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 20:32:16 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/05 04:25:06 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_draw_column(t_env *env, double alpha, int x)
{
	double		d;
	double		y;
	double		y_p;
	double		h;
	double		sol;
	double		plafond;
	double		the_x;

	y = env->mid;
	y_p = env->h_pic / 2;
	if (alpha >= 360)
		alpha -= 360;
	if (alpha < 0)
		alpha += 360;
	d = ft_calcul(env, alpha);
	d = d * cos(ft_dtor(env->bruno.angle - alpha));
	h = env->sz_wall / d * env->bruno.d_proj;
	the_x = ((float)env->sz_wall / (float)env->w_pic) * ((int)env->hit.x % env->w_pic);
	dprintf(1, "%d\n", (int)the_x);
	while (y <= env->h_win - 1 && y - env->mid < h / 2)
	{
		if (y_p > env->h_pic - 1)
			y_p = env->h_pic - 1;
		env->char_img[x * 4 + (int)y * env->size_line] = env->char_pic[(int)the_x + (int)y_p * env->size_line_pic];
		env->char_img[x * 4 + (int)y * env->size_line + 1] = env->char_pic[(int)the_x + (int)y_p * env->size_line_pic + 1];
		env->char_img[x * 4 + (int)y * env->size_line + 2] = env->char_pic[(int)the_x + (int)y_p * env->size_line_pic + 2];
		y_p++;
		y++;
	}
	y = env->mid;
	y_p = env->h_pic / 2;
	while (y >= 0 && y - env->mid > -h / 2)
	{
		if (y_p < 0)
			y_p = 0;
		env->char_img[x * 4 + (int)y * env->size_line] = env->char_pic[(int)the_x + (int)y_p * env->size_line_pic];
		env->char_img[x * 4 + (int)y * env->size_line + 1] = env->char_pic[(int)the_x + (int)y_p * env->size_line_pic + 1];
		env->char_img[x * 4 + (int)y * env->size_line + 2] = env->char_pic[(int)the_x + (int)y_p * env->size_line_pic + 2];
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
