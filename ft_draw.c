/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 20:32:16 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/27 07:36:33 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_plafond(t_env *env, int x, double h)
{
	double		plafond;

	plafond = 0;
	while (plafond < env->mid - h / 2)
	{
		env->img.char_img[x * 4 + (int)plafond * env->img.size_line] = 70;
		env->img.char_img[x * 4 + (int)plafond * env->img.size_line + 1] = 70;
		env->img.char_img[x * 4 + (int)plafond * env->img.size_line + 2] = 70;
		plafond++;
	}
}

static void	ft_floor(t_env *env, int x, double h, int the_x)
{
	double		sol;
	double		y_p;

	sol = HEIGHT - 1;
	y_p = 0;
	(void)the_x;
	while (sol > env->mid + h / 2)
	{
		/*
		   if (y_p > env->pic[1].height - 1)
		   y_p = env->pic[1].height - 1;
		   */
		env->img.char_img[x * 4 + (int)sol * env->img.size_line] = 50;
		//env->pic[1].char_img[(int)the_x * 4 +  (int)y_p * env->pic[1].size_line];
		env->img.char_img[x * 4 + (int)sol * env->img.size_line + 1] = 50;
		//env->pic[1].char_img[(int)the_x * 4 +  (int)y_p * env->pic[1].size_line + 1];
		env->img.char_img[x * 4 + (int)sol * env->img.size_line + 2] = 50;
		//env->pic[1].char_img[(int)the_x * 4 +  (int)y_p * env->pic[1].size_line + 2];
		y_p++;
		sol--;
	}
}

static void	ft_mursup(t_env *env, int x, double h, int the_x)
{
	double		y;
	double		y_p;
	int			nuance;

	y = env->mid;
	y_p = env->pic[0].height / 2;
	nuance = 0;
	while (y >= 0 && y - env->mid > -h / 2)
	{
		if (y_p < 0)
			y_p = 0;
		if (env->vorh == 'h' && env->alpha >= 0 && env->alpha < 180)
			nuance = 0x0066FF;
		else if (env->vorh == 'h' && env->alpha >= 180)
			nuance = 0xAA6699;
		else if (env->vorh == 'v' && env->alpha >= 90 && env->alpha < 270)
			nuance = 0xFF0033;
		else if (env->vorh == 'v' && (env->alpha < 90 || env->alpha >= 270))
			nuance = 0xFFFF00;
		env->img.char_img[x * 4 + (int)y * env->img.size_line] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line] + 0.1 * (unsigned char)nuance;
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 1] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 1] + 0.1 * (unsigned char)(nuance >> 8);
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 2] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 2] + 0.1 * (unsigned char)(nuance >> 16);
		y_p -= env->pic[0].height / h;
		y--;
	}
}


static void	ft_murinf(t_env *env, int x, double h, int the_x)
{
	double		y;
	double		y_p;
	int			nuance;

	y = env->mid;
	y_p = env->pic[0].height / 2;

	while (y <= env->h_win - 1 && y - env->mid < h / 2)
	{
		if (y_p > env->pic[0].height - 1)
			y_p = env->pic[0].height - 1;


		if (env->vorh == 'h' && env->alpha >= 0 && env->alpha < 180)
			nuance = 0x0066FF;
		else if (env->vorh == 'h' && env->alpha >= 180)
			nuance = 0xAA6699;
		else if (env->vorh == 'v' && env->alpha >= 90 && env->alpha < 270)
			nuance = 0xFF0033;
		else if (env->vorh == 'v' && (env->alpha < 90 || env->alpha >= 270))
			nuance = 0xFFFF00;
		env->img.char_img[x * 4 + (int)y * env->img.size_line] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line] + 0.1 * (unsigned char)nuance;
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 1] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 1] + 0.1 * (unsigned char)(nuance >> 8);
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 2] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 2] + 0.1 * (unsigned char)(nuance >> 16);
		y_p += env->pic[0].height / h;
		y++;
	}
}

void		ft_draw(t_env *env)
{
	size_t		x;
	double		d;
	double		h;
	int			the_mur_x;
	int			the_floor_x;

	env->alpha = env->bruno.angle + 30;
	x = 0;
	while (x < env->w_win)
	{
		if (env->alpha >= 360)
			env->alpha -= 360;
		if (env->alpha < 0)
			env->alpha += 360;
		d = ft_calcul(env, env->alpha);
		d = d * cos(ft_dtor(env->bruno.angle - env->alpha));
		h = env->sz_wall / d * env->bruno.d_proj;
		if (env->vorh == 'h')
			the_mur_x = ((int)env->hit.x * env->pic[0].width / env->sz_wall) % (int)env->pic[0].width;
		else
			the_mur_x = ((int)env->hit.y * env->pic[0].width / env->sz_wall) % (int)env->pic[0].width;
		the_floor_x = x * 3;
		ft_plafond(env, x, h);
		ft_murinf(env, x, h, the_mur_x);
		ft_mursup(env, x, h, the_mur_x);
		ft_floor(env, x, h, the_floor_x);
		env->alpha = env->alpha - env->i_angle;
		x++;
	}
}
