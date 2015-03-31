/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viseur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 07:44:58 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/31 07:46:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	ft_viseur_too(t_env *env, int i, int j)
{
	env->img.char_img[i * 4 + (env->h_win / 2) * env->img.size_line] = 0x01;
	env->img.char_img[i * 4 + (env->h_win / 2) * env->img.size_line + 1] = 0x44;
	env->img.char_img[i * 4 + (env->h_win / 2) * env->img.size_line + 2] = 0xB7;
	env->img.char_img[j * 4 + (env->h_win / 2) * env->img.size_line] = 0x01;
	env->img.char_img[j * 4 + (env->h_win / 2) * env->img.size_line + 1] = 0x44;
	env->img.char_img[j * 4 + (env->h_win / 2) * env->img.size_line + 2] = 0xB7;
}

static void	ft_viseur_too2(t_env *env, int i, int j)
{
	env->img.char_img[env->w_win / 2 * 4 + i * env->img.size_line] = 0x01;
	env->img.char_img[env->w_win / 2 * 4 + i * env->img.size_line + 1] = 0x44;
	env->img.char_img[env->w_win / 2 * 4 + i * env->img.size_line + 2] = 0xB7;
	env->img.char_img[env->w_win / 2 * 4 + j * env->img.size_line] = 0x01;
	env->img.char_img[env->w_win / 2 * 4 + j * env->img.size_line + 1] = 0x44;
	env->img.char_img[env->w_win / 2 * 4 + j * env->img.size_line + 2] = 0xB7;
}

void		ft_viseur(t_env *env)
{
	int		i;
	int		j;

	i = env->w_win / 2 - 10;
	j = env->w_win / 2 + 10;
	while (i < (int)env->w_win / 2 - 2)
		ft_viseur_too(env, i++, j--);
	i = env->h_win / 2 - 10;
	j = env->h_win / 2 + 10;
	while (i < (int)env->h_win / 2 - 2)
		ft_viseur_too2(env, i++, j--);
	env->img.char_img[env->w_win / 2 * 4
		+ env->h_win / 2 * env->img.size_line] = 0x01;
	env->img.char_img[env->w_win / 2 * 4
		+ env->h_win / 2 * env->img.size_line + 1] = 0x44;
	env->img.char_img[env->w_win / 2 * 4
		+ env->h_win / 2 * env->img.size_line + 2] = 0xB7;
}
