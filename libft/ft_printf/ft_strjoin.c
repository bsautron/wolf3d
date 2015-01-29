/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:17:28 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:18:28 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pstrjoin(char const *s1, char const *s2)
{
	int		len_all;
	char	*dst;

	if (s1 && s2)
	{
		len_all = ft_pstrlen(s1) + ft_pstrlen(s2);
		dst = ft_pmemalloc(len_all + 1);
		if (dst)
		{
			ft_pstrncat(ft_pstrncpy(dst, s1, ft_pstrlen(s1)), s2, ft_pstrlen(s2));
			return (dst);
		}
	}
	return (NULL);
}
