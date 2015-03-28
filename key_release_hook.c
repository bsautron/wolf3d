/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 05:34:39 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/28 19:19:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_release_hook(int keycode, t_env *env)
{
	if (keycode == ESP)
		exit(0);
	if (keycode == UP)
		env->input.up = 0;
	if (keycode == DOWN)
		env->input.down = 0;
	if (keycode == LEFT)
		env->input.left= 0;
	if (keycode == RIGHT)
		env->input.right = 0;
	if (keycode == W_UP)
		env->input.w_up = 0;
	if (keycode == W_DOWN)
		env->input.w_down = 0;
	if (keycode == W_LEFT)
		env->input.w_left = 0;
	if (keycode == W_RIGHT)
		env->input.w_right = 0;
	if (keycode == RUN)
		env->input.run = 0;
	if (keycode == ACCURACY)
		env->input.accu = 0;
	return (0);
}
