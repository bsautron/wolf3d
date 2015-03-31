/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 20:32:16 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/31 06:35:47 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_plafond(t_env *env, int x, double h)
{
	double		plafond;

	plafond = 0;
	while (plafond < env->mid - h / 2)
	{
		env->img.char_img[x * 4 + (int)plafond * P0L] = 70;
		env->img.char_img[x * 4 + (int)plafond * P0L + 1] = 70;
		env->img.char_img[x * 4 + (int)plafond * P0L + 2] = 70;
		plafond++;
	}
}

static void	ft_floor(t_env *env, int x, double h)
{
	double		sol;
	double		y_p;

	sol = HEIGHT - 1;
	y_p = 0;
	while (sol > env->mid + h / 2)
	{
		env->img.char_img[x * 4 + (int)sol * P0L] = 50;
		env->img.char_img[x * 4 + (int)sol * P0L + 1] = 50;
		env->img.char_img[x * 4 + (int)sol * P0L + 2] = 50;
		y_p++;
		sol--;
	}
}

static void	ft_pt(t_env *env, POS, int y_p, int the_x)
{
	int			nuance;

	nuance = 0;
	if (env->vorh == 'h' && env->alpha >= 0 && env->alpha < 180)
		nuance = 0x0066FF;
	else if (env->vorh == 'h' && env->alpha >= 180)
		nuance = 0xAA6699;
	else if (env->vorh == 'v' && env->alpha >= 90 && env->alpha < 270)
		nuance = 0xFF0033;
	else if (env->vorh == 'v' && (env->alpha < 90 || env->alpha >= 270))
		nuance = 0xFFFF00;
	env->img.char_img[x * 4 + (int)y * P0L] =
		env->pic[0].char_img[(int)the_x * 4 + (int)y_p
		* P_0LINE] + 0.1 * (unsigned char)nuance;
	env->img.char_img[x * 4 + (int)y * P0L + 1] =
		env->pic[0].char_img[(int)the_x * 4 + (int)y_p
		* P_0LINE + 1] + 0.1 * (unsigned char)(nuance >> 8);
	env->img.char_img[x * 4 + (int)y * P0L + 2] =
		env->pic[0].char_img[(int)the_x * 4 + (int)y_p
		* P_0LINE + 2] + 0.1 * (unsigned char)(nuance >> 16);
}

static void	ft_mursup(t_env *env, int x, double h, int the_x)
{
	double		y;
	double		y_p;

	y = env->mid;
	y_p = env->pic[0].height / 2;
	while (y >= 0 && y - env->mid > -h / 2)
	{
		if (y_p < 0)
			y_p = 0;
		ft_pt(env, x, y, y_p, the_x);
		y_p -= env->pic[0].height / h;
		y--;
	}
}

static void	ft_murinf(t_env *env, int x, double h, int the_x)
{
	double		y;
	double		y_p;

	y = env->mid;
	y_p = env->pic[0].height / 2;
	while (y <= env->h_win - 1 && y - env->mid < h / 2)
	{
		if (y_p > env->pic[0].height - 1)
			y_p = env->pic[0].height - 1;
		ft_pt(env, x, y, y_p, the_x);
		y_p += env->pic[0].height / h;
		y++;
	}
}

static int	ft_the_m(t_env *env)
{
	double	d;
	int		the_mur_x;

	if (env->alpha >= 360)
		env->alpha -= 360;
	if (env->alpha < 0)
		env->alpha += 360;
	d = ft_calcul(env, env->alpha);
	d = d * cos(ft_dtor(env->bruno.angle - env->alpha));
	env->h = env->sz_wall / d * env->bruno.d_proj;
	if (env->input.accu)
		env->h *= 1.5;
	if (env->vorh == 'h')
		the_mur_x = ((int)env->hit.x
				* env->pic[0].width / env->sz_wall) % (int)env->pic[0].width;
	else
		the_mur_x = ((int)env->hit.y
				* env->pic[0].width / env->sz_wall) % (int)env->pic[0].width;
	return (the_mur_x);
}

static void	ft_prev(t_env *env)
{
	env->alpha = env->bruno.angle + 30;
	if (env->input.up)
		env->bruno.move += 0.14;
	else
		env->bruno.move = 0;
	if (env->input.accu)
	{
		env->i_angle = 40.0 / (double)env->w_win;
		env->alpha -= 10;
	}
	else
		env->i_angle = 60.0 / (double)env->w_win;
}

void		ft_draw(t_env *env)
{
	size_t		x;
	int			the_mur_x;

	ft_prev(env);
	x = 0;
	while (x < env->w_win)
	{
		the_mur_x = ft_the_m(env);
		ft_plafond(env, x, env->h);
		ft_murinf(env, x, env->h, the_mur_x);
		ft_mursup(env, x, env->h, the_mur_x);
		ft_floor(env, x, env->h);
		env->alpha = env->alpha - env->i_angle;
		x++;
	}
	if (env->input.accu)
		ft_arme(env, 1);
	else
		ft_arme(env, 0);
}
