/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 04:40:00 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/27 02:49:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			key_hook(int keycode, t_env *env)
{
	dprintf(1, "%s\n", "iuhferfiuherfouefr");
	if (keycode == ESP)
		exit(0);
	if (keycode == UP)
	{
		env->bruno.pos.x += 20 * cos(ft_dtor(env->bruno.angle));
		env->bruno.pos.y -= 20 * sin(ft_dtor(env->bruno.angle));
	}
	if (keycode == DOWN)
	{
		env->bruno.pos.x -= 20 * cos(ft_dtor(env->bruno.angle));
		env->bruno.pos.y += 20 * sin(ft_dtor(env->bruno.angle));
	}
	if (keycode == LEFT)
	{
		env->bruno.pos.x -= 20 * cos(ft_dtor(env->bruno.angle + 90));
		env->bruno.pos.y += 20 * sin(ft_dtor(env->bruno.angle + 90));
	}
	if (keycode == RIGHT)
	{
		env->bruno.pos.x += 20 * cos(ft_dtor(env->bruno.angle + 90));
		env->bruno.pos.y -= 20 * sin(ft_dtor(env->bruno.angle + 90));
	}
	if (keycode == W_LEFT)
		env->bruno.angle -= 10;
	if (keycode == W_RIGHT)
		env->bruno.angle += 10;
	if (env->bruno.angle >= 360)
		env->bruno.angle -= 360;
	if (env->bruno.angle < 0)
		env->bruno.angle += 360;
	return (0);
}
