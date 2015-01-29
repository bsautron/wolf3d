/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 01:32:34 by gbadi             #+#    #+#             */
/*   Updated: 2015/01/14 15:24:02 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 4095
# define MAX_FILES 256
# define GETBUF(x) save[x].buf
# define GETREAD(x) save[x].read
# define GETREADED(x) save[x].readed
# define GETOFFSET(x) (GETBUF(x) + GETREADED(x))
# define SWAP(x, y, z) {z = y; free(x); x = z;}
# define OHOHOHAHAHAH return(0);free(buffer)
# define GY {return (-1);}
# define GX buffer = (char*)malloc(BUFF_SIZE+1);if(fd<0||line==NULL||fd>255) GY

typedef struct	s_buf
{
	char		*buf;
	ssize_t		read;
	ssize_t		readed;
}				t_buf;

int				get_next_line(int fd, char **line);

#endif
