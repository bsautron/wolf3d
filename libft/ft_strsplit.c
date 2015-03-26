/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:35:29 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/27 21:24:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_words(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			len++;
		else if (s[i] != c && !s[i + 1])
			len++;
		i++;
	}
	return (len);
}

static int		len_split(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char		*cpy_split(char *dst, char const *src, char c)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	tab = NULL;
	if (s)
	{
		words = nb_words(s, c);
		tab = (char **)malloc(sizeof(char *) * (words + 1));
		while (i < words)
		{
			while (*s == c)
				s++;
			tab[i] = (char *)malloc(sizeof(char) * (len_split(s, c) + 1));
			cpy_split(tab[i], s, c);
			s += len_split(s, c);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
