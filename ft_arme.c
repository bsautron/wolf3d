/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arme.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 06:25:00 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/31 06:52:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

#define SIN_CARRE   (int)(sin(env->bruno.move) * sin(env->bruno.move) * 30)

static void ft_arme1_aux(int i, int j, POS, t_env *env)
{
	env->img.char_img[j * 4 + i * P0L] =
		env->pic[1].char_img[(int)x * 4 + (int)y * P_1LINE];
	env->img.char_img[j * 4 + i * P0L + 1] =
		env->pic[1].char_img[(int)x * 4 + (int)y * P_1LINE + 1];
	env->img.char_img[j * 4 + (int)i * P0L + 2] =
		env->pic[1].char_img[(int)x * 4 + (int)y * P_1LINE + 1];
}

static void ft_arme1(t_env *env)
{
	int		i;
	int		j;
	double	y;
	double	x;
	int		trans;

	i = HEIGHT / 2 - 40;
	y = 0;
	trans = env->pic[1].char_img[0];
	while (i < HEIGHT - 1 && y < env->pic[1].height)
	{
		j = WIDTH / 2 - (env->pic[1].width * (double)env->h_win) / 120 - 5;
		x = 0;
		while (j < WIDTH - 1 && x < env->pic[1].width)
		{
			if (env->pic[1].char_img[(int)x * 4 + (int)y * P_1LINE] != trans)
				ft_arme1_aux(i, j, x, y, env);
			x += 2 * 120 / fmin((double)env->h_win, (double)env->w_win);
			j++;
		}
		y += 2 * 120 / fmin((double)env->h_win, (double)env->w_win);
		i++;
	}
}

static void ft_arme0_aux(int i, int j, POS, t_env *env)
{
	env->img.char_img[j * 4 + (i - SIN_CARRE) * P0L] =
		env->pic[2].char_img[(int)x * 4 + (int)y * P_2LINE];
	env->img.char_img[j * 4 + (i - SIN_CARRE) * P0L + 1] =
		env->pic[2].char_img[(int)x * 4 + (int)y * P_2LINE + 1];
	env->img.char_img[j * 4 + (i - SIN_CARRE) * P0L + 2] =
		env->pic[2].char_img[(int)x * 4 + (int)y * P_2LINE + 1];
}

static void ft_arme0(t_env *env)
{
	int		i;
	int		j;
	double	y;
	double	x;
	int		trans;

	i = HEIGHT / 2 + HEIGHT / 15;
	y = 0;
	trans = env->pic[2].char_img[0];
	while (i - SIN_CARRE < HEIGHT - 1 && y < env->pic[2].height)
	{
		j = WIDTH / 2;
		x = 0;
		while (j < WIDTH - 1 && x < env->pic[2].width)
		{
			if (env->pic[2].char_img[(int)x * 4 + (int)y * P_2LINE] != trans)
				ft_arme0_aux(i, j, x, y, env);
			x += 2 * 120 / fmin((double)env->h_win, (double)env->w_win);
			j++;
		}
		y += 2 * 120 / fmin((double)env->h_win, (double)env->w_win);
		i++;
	}
}

void		ft_arme(t_env *env, int repo)
{
	if (repo == 1)
		ft_arme1(env);
	else
		ft_arme0(env);
}
