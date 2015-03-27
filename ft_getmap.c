/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 05:24:06 by bsautron          #+#    #+#             */
/*   Updated: 2015/03/27 05:18:43 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_nbcol(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] > ' ' && str[i + 1] <= ' ')
			nb++;
		i++;
	}
	return (nb);
}

static void	ft_makemap(t_env *env, char *file)
{
	int		fd;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*line;
	
	i = 0;
	fd = open(file, O_RDONLY);
	env->map = (t_map **)malloc(sizeof(t_map *) * (env->h_map));
	while (get_next_line(fd, &line) > 0)
	{
		env->map[i] = (t_map *)malloc(sizeof(t_map) * (env->w_map));
		j = 0;
		k = 0;
		while (j < env->w_map)
		{
			while (line[k] && line[k] <= ' ')
				k++;
			env->map[i][j].c.y = (float)i;
			env->map[i][j].c.x = (float)j;
			env->map[i][j].obs = ft_atoi(&line[k]);
			if (line[k] == 'a')
			{
				env->map[i][j].obs = ft_atoi(&line[k + 1]);
				env->bruno.pos.y = i * env->sz_wall + env->sz_wall / 2;
				env->bruno.pos.x = j * env->sz_wall + env->sz_wall / 2;
				env->bruno.angle = env->map[i][j].obs;
				env->map[i][j].obs = 0;
			}
			k += ft_strlen_esp(&line[k])+ 1;
			j++;
		}
		i++;
		free(line);
	}
	env->map[i] = NULL;
	close(fd);
}

void		ft_getmap(t_env *env, char *file)
{
	int		fd;
	char	*line;
	int		ret;

	env->h_map = 0;
	env->w_map = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Error: open", 2);
		exit(1);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		env->w_map = fmax(env->w_map, ft_nbcol(line));
		env->h_map = env->h_map + 1;
		free(line);
	}
	env->w_minimap = env->w_map;
	env->h_minimap = env->h_map;
	if (ret == -1)
	{
		ft_putendl_fd("Error: file id a Directory", 2);
		exit(1);
	}
	close(fd);
	ft_makemap(env, file);
}
