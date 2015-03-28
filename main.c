/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 03:23:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/29 00:03:18 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_initenv(t_env *env, int width, int height)
{
	if (!(env->mlx = mlx_init()))
	{
		ft_putendl_fd("Error: env", 2);
		exit(1);
	}
	env->win = mlx_new_window(env->mlx, width, height, "TITRE DE MEEEEEEEERDE");
	env->w_win = width;
	env->h_win = height;
	env->sz_wall = 128;
	env->img.img = mlx_new_image(env->mlx, env->w_win, env->h_win);
	env->img.char_img = mlx_get_data_addr(env->img.img, &env->img.bpp, &env->img.size_line, &env->img.endian);
	env->pic[0].img = mlx_xpm_file_to_image(env->mlx, "mur.xpm", &env->pic[0].width, &env->pic[0].height);
	env->pic[1].img = mlx_xpm_file_to_image(env->mlx, "arme.xpm", &env->pic[1].width, &env->pic[1].height);
	env->pic[2].img = mlx_xpm_file_to_image(env->mlx, "arme0.xpm", &env->pic[2].width, &env->pic[2].height);
	env->pic[0].char_img = mlx_get_data_addr(env->pic[0].img, &env->pic[0].bpp, &env->pic[0].size_line, &env->pic[0].endian);
	env->pic[1].char_img = mlx_get_data_addr(env->pic[1].img, &env->pic[1].bpp, &env->pic[1].size_line, &env->pic[1].endian);
	env->pic[2].char_img = mlx_get_data_addr(env->pic[2].img, &env->pic[2].bpp, &env->pic[2].size_line, &env->pic[2].endian);
	ft_bzero(&env->input, sizeof(env->input));
}

int		main(int argc, char **argv)
{
	t_env		env;
	size_t		i;
	size_t		j;


	env.bruno.pos.x = 111;
	env.bruno.pos.y = 111;
	env.bruno.angle = 300;
	if (argc == 2)
	{
		ft_initenv(&env, WIDTH, HEIGHT);
		env.bruno.d_proj = (env.w_win / 2) / tan(ft_dtor(30));
		env.i_angle = 60.0 / (double)env.w_win;
		ft_getmap(&env, argv[1]);
		ft_zoom_map(&env);
		i = 0;
		while (i < env.h_minimap)
		{
			j = 0;
			while (j < env.w_minimap)
			{
				if (env.map[i][j].obs == 0)
					dprintf(1, "  ");
				else
					dprintf(1, "%d ", env.map[i][j].obs);
				j++;
			}
			dprintf(1, "%s\n", "");
			i++;
		}
		env.mid = env.h_win / 2;
		ft_draw(&env);
		mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
		mlx_do_key_autorepeatoff(env.mlx);
		mlx_hook(env.win, KeyPress, KeyPressMask, key_press_hook, &env);
		mlx_hook(env.win, KeyRelease, KeyReleaseMask, key_release_hook, &env);
		mlx_hook(env.win, MotionNotify, PointerMotionMask, pointer_motion_hook, &env);
		mlx_loop_hook(env.mlx, &expose_hook, &env);
		mlx_loop(env.mlx);
	}
	else
	{
		ft_putendl_fd("Error: give me 1 map", 2);
		return (1);
	}
	return (0);
}
