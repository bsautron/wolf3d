/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 23:10:52 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:19:39 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strncat_p(char *s1, const char *s2, int len, int len_all)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}

static char	*ft_strncpy_p(char *dst, const char *src, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char		*ft_pstrnjoin(char const *s1, char const *s2, int len_s, int len_t)
{
	int		len_s2;
	char	*dst;

	if (s1 && s2)
	{
		len_s2 = len_t - len_s;
		dst = ft_pmemalloc(len_t + 1);
		if (dst)
		{
			dst = ft_strncpy_p(dst, s1, len_s);
			dst = ft_strncat_p(dst, s2, len_s, len_t);
			return (dst);
		}
	}
	return (NULL);
}
