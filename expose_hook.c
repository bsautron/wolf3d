/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 19:08:01 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/28 19:43:22 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	go_up(t_env *env, float run)
{
	t_pt2d		pc;
	t_pt2d		tmp;

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

static void	go_down(t_env *env, float run)
{
	t_pt2d		pc;
	t_pt2d		tmp;

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

static void	go_left(t_env *env, float run)
{
	t_pt2d		pc;
	t_pt2d		tmp;

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
	t_pt2d      pc;
	t_pt2d      tmp;
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

static void	ft_process(t_env *env)
{
	float		run;

	run = 4;
	if (env->input.run == 1)
		run = 8.5;
	if (env->input.up == 1)
		go_up(env, run);
	if (env->input.down == 1)
		go_down(env, run);
	if (env->input.left == 1)
		go_left(env, run);
	if (env->input.right == 1)
		go_right(env, run);
	if (env->input.w_up == 1)
		env->mid += 50;
	if (env->input.w_down == 1)
		env->mid -= 50;
	if (env->input.w_left == 1)
		env->bruno.angle += 3.5;
	if (env->input.w_right == 1)
		env->bruno.angle -= 3.5;
	if (env->bruno.angle >= 360)
		env->bruno.angle -= 360;
	if (env->bruno.angle < 0)
		env->bruno.angle += 360;
	if (env->mid > (int)env->h_win - 1)
		env->mid = env->h_win - 2;
	if (env->mid < 50)
		env->mid = 51;
}

static void	ft_viseur(t_env *env)
{
	int		i;
	int		j;

	i = env->w_win / 2 - 10;
	j = env->w_win / 2 + 10;
	while (i < (int)env->w_win / 2 - 2)
	{
		env->char_img[i * 4 + (env->h_win / 2) * env->size_line] = 0x01;
		env->char_img[i * 4 + (env->h_win / 2) * env->size_line + 1] = 0x44;
		env->char_img[i * 4 + (env->h_win / 2) * env->size_line + 2] = 0xB7;
		env->char_img[j * 4 + (env->h_win / 2) * env->size_line] = 0x01;
		env->char_img[j * 4 + (env->h_win / 2) * env->size_line + 1] = 0x44;
		env->char_img[j * 4 + (env->h_win / 2) * env->size_line + 2] = 0xB7;
		j--;
		i++;
	}
	i = env->h_win / 2 - 10;
	j = env->h_win / 2 + 10;
	while (i < (int)env->h_win / 2 - 2)
	{
		env->char_img[env->w_win / 2 * 4 + i * env->size_line] = 0x01;
		env->char_img[env->w_win / 2 * 4 + i * env->size_line + 1] = 0x44;
		env->char_img[env->w_win / 2 * 4 + i * env->size_line + 2] = 0xB7;
		env->char_img[env->w_win / 2 * 4 + j * env->size_line] = 0x01;
		env->char_img[env->w_win / 2 * 4 + j * env->size_line + 1] = 0x44;
		env->char_img[env->w_win / 2 * 4 + j * env->size_line + 2] = 0xB7;
		j--;
		i++;
	}
	env->char_img[env->w_win / 2 * 4 + env->h_win / 2 * env->size_line] = 0x01;
	env->char_img[env->w_win / 2 * 4 + env->h_win / 2 * env->size_line + 1] = 0x44;
	env->char_img[env->w_win / 2 * 4 + env->h_win / 2 * env->size_line + 2] = 0xB7;
}

static void	ft_string(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 50, 50, 0xB74401, "Up:     W");
	mlx_string_put(env->mlx, env->win, 50, 70, 0xB74401, "Down:   S");
	mlx_string_put(env->mlx, env->win, 50, 90, 0xB74401, "Right:  D");
	mlx_string_put(env->mlx, env->win, 50, 110, 0xB74401, "Down:   S");
	mlx_string_put(env->mlx, env->win, 150, 50, 0xB74401, "Turn Left:   <-");
	mlx_string_put(env->mlx, env->win, 150, 70, 0xB74401, "Turn Right:  ->");
	mlx_string_put(env->mlx, env->win, 150, 90, 0xB74401, "Run:         Shift");
	mlx_string_put(env->mlx, env->win, env->w_win / 2 - 15, 70, 0xB74401, ft_itoa(env->bruno.pos.y));
	mlx_string_put(env->mlx, env->win, env->w_win / 2 + 15, 70, 0xB74401, ft_itoa(env->bruno.pos.x));
	mlx_string_put(env->mlx, env->win, env->w_win / 2 + 45, 70, 0xB74401, ft_itoa((int)env->bruno.angle));
	if (env->bruno.angle > 45 && env->bruno.angle <= 135)
		mlx_string_put(env->mlx, env->win, env->w_win / 2, 50, 0xB74401, "North");
	if (env->bruno.angle > 135 && env->bruno.angle <= 225)
		mlx_string_put(env->mlx, env->win, env->w_win / 2, 50, 0xB74401, "West");
	if (env->bruno.angle > 225 && env->bruno.angle <= 315)
		mlx_string_put(env->mlx, env->win, env->w_win / 2, 50, 0xB74401, "South");
	if ((env->bruno.angle > 315 && env->bruno.angle <= 360) || (env->bruno.angle >= 0 && env->bruno.angle <= 45))
		mlx_string_put(env->mlx, env->win, env->w_win / 2, 50, 0xB74401, "East");
}

int		expose_hook(t_env *env)
{
	ft_process(env);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, env->w_win, env->h_win);
	ft_draw(env);
	ft_viseur(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	ft_string(env);
	return (0);
}