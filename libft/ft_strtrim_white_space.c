/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_white_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 08:51:37 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/26 00:37:55 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_no_white_space(char const *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!(str[i] <= ' '))
			len++;
		i++;
	}
	return (len);
}

static char		*cpy_no_white_space(char *dst, const char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (!(src[i] <= ' '))
		{
			dst[j] = src[i];
			j++;
		}
		i++;
	}
	return (dst);
}

char			*ft_strtrim_white_space(char const *s)
{
	char	*dest_s;

	if (s)
	{
		dest_s = ft_memalloc(len_no_white_space(s) + 1);
		if (dest_s)
		{
			dest_s = cpy_no_white_space(dest_s, s);
			return (dest_s);
		}
	}
	return (NULL);
}
