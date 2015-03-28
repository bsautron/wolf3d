/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 04:14:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/28 19:19:16 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press_hook(int keycode, t_env *env)
{
	if (keycode == UP)
	{
		env->input.up = 1;
		env->input.down = 0;
	}
	if (keycode == DOWN)
	{
		env->input.up = 0;
		env->input.down = 1;
	}
	if (keycode == LEFT)
	{
		env->input.left = 1;
		env->input.right = 0;
	}
	if (keycode == RIGHT)
	{
		env->input.left = 0;
		env->input.right = 1;
	}
	if (keycode == W_UP)
	{
		env->input.w_up = 1;
		env->input.w_down = 0;
	}
	if (keycode == W_DOWN)
	{
		env->input.w_up = 0;
		env->input.w_down = 1;
	}
	if (keycode == W_LEFT)
	{
		env->input.w_left = 1;
		env->input.w_right = 0;
	}
	if (keycode == W_RIGHT)
	{
		env->input.w_left = 0;
		env->input.w_right = 1;
	}
	if (keycode == RUN)
		env->input.run = 1;
	if (keycode == ACCURACY)
		env->input.accu = 1;
	return (0);
}
