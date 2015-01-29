/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 20:23:52 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:05:04 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putwidth(char *str, int width, t_format *fg)
{
	char	*dst;

	dst = ft_pstrnew(width);
	if (fg->flag->zero && !fg->flag->left
		&& (!fg->did_p || fg->conversion == 'c' || fg->conversion == 's'
		|| fg->conversion == 'C' || fg->conversion == 'S'
		|| !ft_charcheck_in_str(fg->conversion, "sSpdDioOuUxXcC")))
	{
		dst = ft_pmemset(dst, '0', width);
		if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		{
			dst[0] = str[0];
			str[0] = '0';
		}
		dst = ft_strjoin_per_aux(dst, str);
	}
	else if (fg->flag->left)
		dst = ft_strjoin_per_aux(str, ft_pmemset(dst, ' ', width));
	else
		dst = ft_strjoin_per_aux(ft_pmemset(dst, ' ', width), str);
	return (dst);
}
