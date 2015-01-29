/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:44:59 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:19:11 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pstrnew(unsigned int size)
{
	char	*dst;

	dst = ft_pmemalloc(size + 1);
	if (!dst)
		return (NULL);
	return (dst);
}
