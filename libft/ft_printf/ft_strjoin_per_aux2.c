/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_per.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 15:07:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:11:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen_per_aux(const char *str)
{
	int		i;
	int		stop;

	stop = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			stop++;
		i++;
		if (stop == 2)
			break ;
	}
	return (i);
}

char		*ft_strjoin_per_aux2(const char *s1, const char *s2)
{
	int		len_all;
	char	*dst;

	if (s1 && s2)
	{
		len_all = ft_strlen_per_aux(s1) + ft_strlen_per(s2);
		dst = ft_pmemalloc(len_all + 1);
		if (dst)
		{
			ft_pstrncpy(dst, s1, ft_strlen_per_aux(s1));
			ft_pstrncat(dst, s2, ft_strlen_per(s2));
			return (dst);
		}
	}
	return (NULL);
}
