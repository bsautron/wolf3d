/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:55:36 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/07 11:56:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*temp_dst;
	unsigned char		*temp_src;

	temp_dst = dst;
	temp_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		if (temp_src[i] == (unsigned char)c)
			return (&temp_dst[i + 1]);
		i++;
	}
	return (NULL);
}
