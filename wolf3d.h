/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 03:22:26 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/28 19:51:47 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WLOF3D_H

# include <mlx.h>
# include <X11/Xlib.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

#include <stdio.h>//////////////////

# define ESP		65307
# define UP			119
# define DOWN		115
# define LEFT		97
# define RIGHT		100
# define W_UP		65362
# define W_DOWN		65364
# define W_RIGHT	65363
# define W_LEFT		65361
# define RUN		65505

typedef struct		s_pt2d
{
	double	x;
	double	y;
}					t_pt2d;

typedef struct		s_pt3d
{
	double	x;
	double	y;
	double	z;
}					t_pt3d;

typedef struct		s_map
{
	t_pt2d			c;
	int				obs;
}					t_map;

typedef struct		s_perso
{
	t_pt2d		pos;
	double		angle;
	double		d_proj;
}					t_perso;

typedef struct		s_input
{
	char			up;
	char			down;
	char			left;
	char			right;
	char			w_up;
	char			w_down;
	char			w_left;
	char			w_right;
	char			run;
}					t_input;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	size_t	h_win;
	size_t	w_win;
	t_map	**map;
	size_t	w_minimap;
	size_t	h_minimap;
	size_t	h_map;
	size_t	w_map;
	void	*img;
	char	*char_img;
	int		size_line;
	int		endian;
	int		bpp;
	size_t	sz_wall;
	double	i_angle;
	t_perso	bruno;
	t_input	input;
	int		mid;
	void	*pic;
	char	*char_pic;
	int		h_pic;
	int		w_pic;
	int		bpp_pic;
	int		size_line_pic;
	int		endian_pic;
}					t_env;


int			key_hook(int keycode, t_env *env);
int			key_press_hook(int keycode, t_env *env);
int			key_release_hook(int keycode, t_env *env);
int			expose_hook(t_env *env);
int			pointer_motion_hook(int x, int y, t_env *env);

void		ft_getmap(t_env *env, char *file);
void		ft_zoom_map(t_env *env);
double		ft_calcul(t_env env,  double angle);
void		ft_draw(t_env *env);
double		ft_dtor(float degre);
t_pt2d		ft_make_increment(t_env env, double angle, char axe);
t_pt2d		ft_regu_maxmap(t_pt2d pn);
t_pt2d		ft_minicase(t_env env, t_pt2d pn);


#endif