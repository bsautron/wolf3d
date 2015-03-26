/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:29:50 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/07 12:06:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_s;

	temp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*temp_s == (unsigned char)c)
			return (temp_s);
		temp_s++;
		i++;
	}
	return (NULL);
}
