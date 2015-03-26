/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 01:44:28 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/28 12:04:45 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			gnl_has_newline(t_buff *fd)
{
	while (fd->buff[fd->read] != '\n' && fd->buff[fd->read] != '\0')
		fd->read++;
	return ((fd->buff[fd->read] == '\n') ? 1 : 0);
}

static char			*gnl_buff_join(t_buff *fd, char *buff, int read_buff_len)
{
	int				i;
	int				k;
	int				j;
	char			*new;

	if (read_buff_len == 0)
		return (fd->buff);
	i = 0;
	k = fd->last_line + 1;
	fd->read -= k;
	new = (char*)malloc(sizeof(char) * (fd->len - k + read_buff_len + 1));
	j = fd->len - fd->last_line - 1;
	while (i < j)
		new[i++] = fd->buff[k++];
	k = 0;
	while (k < read_buff_len)
		new[i++] = buff[k++];
	fd->len = fd->len - (fd->last_line + 1) + read_buff_len;
	fd->last_line = -1;
	new[i] = '\0';
	return (new);
}

static int			gnl_get_buffer_line(t_buff *fd, char **line)
{
	int		start;
	int		i;
	char	*temp;

	start = (fd->last_line >= 0) ? fd->last_line + 1 : 0;
	if (fd->buff[start] == '\0')
		return (0);
	i = 0;
	*line = (char*)malloc(sizeof(char) * (fd->read - start + 1));
	while (start < fd->read)
		(*line)[i++] = fd->buff[start++];
	(*line)[i] = '\0';
	if (fd->buff[fd->read] == '\n')
	{
		fd->last_line = fd->read;
		fd->read++;
	}
	else
	{
		fd->len = 0;
		fd->read = 0;
		fd->last_line = -1;
		FT_SWAP(fd->buff, ft_strnew(0), temp);
	}
	return (1);
}

static void			new_fd(t_buff *fd)
{
	fd->last_line = -1;
	fd->buff = ft_strnew(0);
	fd->read = 0;
	fd->len = 0;
}

int					get_next_line(const int fd, char **line)
{
	static t_buff		buff_lst[256];
	char				*buff;
	char				*temp;
	int					r;

	if (line == NULL || fd < 0 || fd > 255)
		return (-1);
	r = 1;
	buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff_lst[fd].buff)
		new_fd(buff_lst + fd);
	while (!gnl_has_newline(&buff_lst[fd]) && r > 0)
	{
		r = read(fd, buff, BUFF_SIZE);
		buff[r] = '\0';
		FT_SWAP(buff_lst[fd].buff, gnl_buff_join(&buff_lst[fd], buff, r), temp);
	}
	free(buff);
	if (r < 0)
		return (-1);
	return (gnl_get_buffer_line(&buff_lst[fd], line));
}
