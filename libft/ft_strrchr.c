/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:17:26 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/14 01:42:08 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp_s;

	temp_s = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (temp_s[i] == (char)c)
			return (&temp_s[i]);
		i--;
	}
	return (NULL);
}
