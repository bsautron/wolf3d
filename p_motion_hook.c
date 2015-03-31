/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_motion_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 07:09:01 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/31 07:21:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		p_motion_hook(int x, int y, t_env *env)
{
	env->mid = env->h_win / 2 + 3 * (env->h_win / 2 - y);
	if (env->mid < 0)
		env->mid = 0;
	env->bruno.angle = (360 - x) / 2;
	if (env->bruno.angle >= 360)
		env->bruno.angle -= 360;
	env->bruno.angle = (int)env->bruno.angle % 360;
	return (0);
}
