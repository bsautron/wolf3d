/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:32:04 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/08 16:58:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)malloc(sizeof(len));
	ft_memcpy(temp_src, src, len);
	ft_memcpy(temp_dst, temp_src, len);
	free(temp_src);
	return (temp_dst);
}
