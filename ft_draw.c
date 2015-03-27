/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 20:32:16 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/27 01:06:45 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_plafond(t_env *env, int x, double h)
{
	double		plafond;

	plafond = 0;
	while (plafond < env->mid - h / 2)
	{
		env->img.char_img[x * 4 + (int)plafond * env->img.size_line] = 0x0;
		env->img.char_img[x * 4 + (int)plafond * env->img.size_line + 1] = 0x50;
		env->img.char_img[x * 4 + (int)plafond * env->img.size_line + 2] = 0x0;
		plafond++;
	}
}

static void	ft_floor(t_env *env, int x, double h, int the_x)
{
	double		sol;
	double		y_p;

	sol = env->h_win;
	y_p = 0;
	(void)the_x;
	while (sol > env->mid + h / 2)
	{
		/*
		if (y_p > env->pic[1].height - 1)
			y_p = env->pic[1].height - 1;
			*/
		env->img.char_img[x * 4 + (int)sol * env->img.size_line] = 0x20;
			//env->pic[1].char_img[(int)the_x * 4 +  (int)y_p * env->pic[1].size_line];
		env->img.char_img[x * 4 + (int)sol * env->img.size_line + 1] = 0x20;
			//env->pic[1].char_img[(int)the_x * 4 +  (int)y_p * env->pic[1].size_line + 1];
		env->img.char_img[x * 4 + (int)sol * env->img.size_line + 2] = 0x20;
			//env->pic[1].char_img[(int)the_x * 4 +  (int)y_p * env->pic[1].size_line + 2];
		y_p++;
		sol--;
	}
}

static void	ft_mursup(t_env *env, int x, double h, int the_x)
{
	double		y;
	double		y_p;

	y = env->mid;
	y_p = env->pic[0].height / 2;
	while (y >= 10 && y - env->mid > -h / 2)
	{
		if (y_p < 0)
			y_p = 0;
		env->img.char_img[x * 4 + (int)y * env->img.size_line] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line];
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 1] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 1];
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 2] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 2];
		y_p -= env->pic[0].height / h;
		y--;
	}
}

static void	ft_mursup2(t_env *env, int x, double h, int the_x)
{
	double		y;
	double		y_p;

	y = env->mid - h / 2;
	(void)the_x;
	y_p = env->pic[0].height / 2;
	while (y >= 0 && y - env->mid > -h)
	{
		if (y_p < 0)
			y_p = 0;
		env->img.char_img[x * 4 + (int)y * env->img.size_line] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line];
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 1] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 1];
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 2] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 2];
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
		env->img.char_img[x * 4 + (int)y * env->img.size_line] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line];
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 1] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 1];
		env->img.char_img[x * 4 + (int)y * env->img.size_line + 2] =
			env->pic[0].char_img[(int)the_x * 4 + (int)y_p * env->pic[0].size_line + 2];
		y_p += env->pic[0].height / h;
		y++;
	}
}

void		ft_draw(t_env *env)
{
	double		alpha;
	size_t		x;
	double		d;
	double		h;
	int			the_mur_x;
	int			the_floor_x;

	alpha = env->bruno.angle + 30;
	x = 0;
	while (x < env->w_win)
	{
		if (alpha >= 360)
			alpha -= 360;
		if (alpha < 0)
			alpha += 360;
		d = ft_calcul(env, alpha);
		d = d * cos(ft_dtor(env->bruno.angle - alpha));
		h = env->sz_wall / d * env->bruno.d_proj;
		if (env->vorh == 'h')
			the_mur_x = ((int)env->hit.x * env->pic[0].width / env->sz_wall) % (int)env->pic[0].width;
		else
			the_mur_x = ((int)env->hit.y * env->pic[0].width / env->sz_wall) % (int)env->pic[0].width;
		the_floor_x = x * 3;
		//ft_plafond(env, x, h);
		(void)ft_plafond;
		ft_murinf(env, x, h, the_mur_x);
		ft_mursup2(env, x, h, the_mur_x);
		ft_mursup(env, x, h, the_mur_x);
		//ft_floor(env, x, h, the_floor_x);
		(void)ft_floor;
		alpha = alpha - env->i_angle;
		x++;
	}
}
