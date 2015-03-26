/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:39:21 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/05 20:05:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dst;

	dst = NULL;
	if (size)
	{
		dst = malloc(sizeof(dst) * size);
		if (dst)
			ft_bzero(dst, size);
		else
			return (NULL);
	}
	return (dst);
}
