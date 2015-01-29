/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:39:21 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:16:28 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_pmemalloc(unsigned int size)
{
	void	*dst;

	dst = NULL;
	if (size)
	{
		dst = malloc(sizeof(dst) * size);
		if (dst)
			ft_pbzero(dst, size);
		else
			return (NULL);
	}
	return (dst);
}
