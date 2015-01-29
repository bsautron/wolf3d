/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:04:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:06:54 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_positif(unsigned long long int nb)
{
	char					*dst;
	unsigned long long int	tmp;
	int						i;

	tmp = nb;
	i = 0;
	while (tmp > 0)
	{
		tmp /= 2;
		i++;
	}
	dst = ft_pstrnew(i);
	tmp = nb;
	while (tmp > 0)
	{
		dst[i - 1] = tmp % 2 + '0';
		tmp /= 2;
		i--;
	}
	return (dst);
}

char			*ft_binary(unsigned long long int nb, t_format *fg)
{
	char			*dst;

	if (nb == 0)
		dst = ft_pstrdup("0");
	else
		dst = ft_positif(nb);
	return (dst);
}
