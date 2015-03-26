/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 03:23:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/05 04:29:31 by bsautron         ###   ########.fr       */
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
	env->win = mlx_new_window(env->mlx, width, height, "TITRE DE MEEEEEEEEREDE");
	env->w_win = width;
	env->h_win = height;
	env->sz_wall = 100;
	env->img = mlx_new_image(env->mlx, env->w_win, env->h_win);
	env->char_img = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);
	env->pic = mlx_xpm_file_to_image(env->mlx, "mur.xpm", &env->w_pic, &env->h_pic);
	env->char_pic = mlx_get_data_addr(env->pic, &env->bpp_pic, &env->size_line_pic, &env->endian_pic);
	ft_bzero(&env->input, sizeof(env->input));
}

int		main(int argc, char **argv)
{
	t_env	env;
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
		mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
		mlx_do_key_autorepeatoff(env.mlx);
		mlx_hook(env.win, 2, (1L<<0), key_press_hook, &env);
		mlx_hook(env.win, 3, (1L<<1), key_release_hook, &env);
		mlx_hook(env.win, 6, (1L<<6), pointer_motion_hook, &env);
		mlx_loop_hook(env.mlx, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	else
	{
		ft_putendl_fd("Error: give me 1 map", 2);
		return (1);
	}
	return (0);
}
