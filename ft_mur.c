/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 06:45:32 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/31 07:06:52 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void ft_pt(t_env *env, POS, int y_p, int the_x)
{
	int	nuance;

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

void		ft_mur(t_env *env, int x, double h, int the_x)
{
	double	y;
	double	y_p;

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
