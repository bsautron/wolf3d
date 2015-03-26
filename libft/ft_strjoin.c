/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:17:28 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/08 18:36:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_all;
	char	*dst;

	if (s1 && s2)
	{
		len_all = ft_strlen(s1) + ft_strlen(s2);
		dst = ft_memalloc(len_all + 1);
		if (dst)
		{
			ft_strcat(ft_strcpy(dst, s1), s2);
			return (dst);
		}
	}
	return (NULL);
}
