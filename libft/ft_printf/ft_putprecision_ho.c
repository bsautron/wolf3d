/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprecision_ho.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 03:51:29 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:05:56 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putprecision_ho(char *str, char *dst, int prec, t_format *fg)
{
	dst = ft_pstrnew(prec + 2);
	if (str[0] == '-'
		|| str[0] == '+'
		|| (fg->conversion == 'p' && str[1] == 'x'))
	{
		prec++;
		dst = ft_pmemset(dst, '0', prec);
		if (str[0] == '-')
			dst[0] = '-';
		else if (str[0] == '+')
			dst[0] = '+';
		else if (fg->conversion == 'p' && str[1] == 'x')
		{
			dst[1] = 'x';
			str[1] = '0';
		}
		str[0] = '0';
	}
	else
		dst = ft_pmemset(dst, '0', prec);
	dst = ft_strjoin_per(dst, str);
	return (dst);
}
