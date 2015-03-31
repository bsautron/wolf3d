/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 07:23:03 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/31 07:30:49 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void go_up(t_env *env, float run)
{
	t_pt2d	pc;
	t_pt2d	tmp;

	tmp.y = env->bruno.pos.y;
	tmp.x = env->bruno.pos.x + run * cos(ft_dtor(env->bruno.angle));
	pc = ft_minicase(*env, tmp);
	if (env->map[(int)pc.y][(int)pc.x].obs != 1)
		env->bruno.pos.x = tmp.x;
	tmp.y = env->bruno.pos.y - run * sin(ft_dtor(env->bruno.angle));
	tmp.x = env->bruno.pos.x;
	pc = ft_minicase(*env, tmp);
	if (env->map[(int)pc.y][(int)pc.x].obs != 1)
		env->bruno.pos.y = tmp.y;
}

static void go_down(t_env *env, float run)
{
	t_pt2d	pc;
	t_pt2d	tmp;

	tmp.y = env->bruno.pos.y;
	tmp.x = env->bruno.pos.x - run / 2 * cos(ft_dtor(env->bruno.angle));
	pc = ft_minicase(*env, tmp);
	if (env->map[(int)pc.y][(int)pc.x].obs != 1)
		env->bruno.pos.x = tmp.x;
	tmp.y = env->bruno.pos.y + run / 2 * sin(ft_dtor(env->bruno.angle));
	tmp.x = env->bruno.pos.x;
	pc = ft_minicase(*env, tmp);
	if (env->map[(int)pc.y][(int)pc.x].obs != 1)
		env->bruno.pos.y = tmp.y;
}

static void go_left(t_env *env, float run)
{
	t_pt2d	pc;
	t_pt2d	tmp;

	tmp.y = env->bruno.pos.y;
	tmp.x = env->bruno.pos.x + run / 2 * cos(ft_dtor(env->bruno.angle + 90));
	pc = ft_minicase(*env, tmp);
	if (env->map[(int)pc.y][(int)pc.x].obs != 1)
		env->bruno.pos.x = tmp.x;
	tmp.y = env->bruno.pos.y - run / 2 * sin(ft_dtor(env->bruno.angle + 90));
	tmp.x = env->bruno.pos.x;
	pc = ft_minicase(*env, tmp);
	if (env->map[(int)pc.y][(int)pc.x].obs != 1)
		env->bruno.pos.y = tmp.y;
}

static void go_right(t_env *env, float run)
{
	t_pt2d	pc;
	t_pt2d	tmp;

	tmp.y = env->bruno.pos.y;
	tmp.x = env->bruno.pos.x - run / 2 * cos(ft_dtor(env->bruno.angle + 90));
	pc = ft_minicase(*env, tmp);
	if (env->map[(int)pc.y][(int)pc.x].obs != 1)
		env->bruno.pos.x = tmp.x;
	tmp.y = env->bruno.pos.y + run / 2 * sin(ft_dtor(env->bruno.angle + 90));
	tmp.x = env->bruno.pos.x;
	pc = ft_minicase(*env, tmp);
	if (env->map[(int)pc.y][(int)pc.x].obs != 1)
		env->bruno.pos.y = tmp.y;
}

void		ft_go(t_env *env, float run, char go)
{
	if (go == 'u')
		go_up(env, run);
	else if (go == 'd')
		go_down(env, run);
	else if (go == 'r')
		go_right(env, run);
	else if (go == 'l')
		go_left(env, run);
}
