/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 04:40:00 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/23 05:56:11 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			key_hook(int keycode, t_env *env)
{
	dprintf(1, "%d\n", keycode);
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
	
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->w_win, env->h_win);
	ft_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	dprintf(1, "BRUNO: x = %f y = %f\n", env->bruno.pos.x, env->bruno.pos.y);
	dprintf(1, "ANGLE: = %f\n", env->bruno.angle);
	ft_putchar(10);
	return (0);
}