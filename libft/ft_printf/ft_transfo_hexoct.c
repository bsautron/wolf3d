/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfo_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:53:47 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:27:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_precision(char *str, t_format *fg)
{
	char	*dst;
	int		prec;

	prec = fg->precision - ft_pstrlen(str);
	if (fg->conversion == 'p')
		prec += 1;
	if (!fg->flag->tag && ft_pstrequ(str, "0")
		&& fg->did_p && fg->precision == 0)
		dst = ft_pstrdup("");
	else if (prec >= 0)
		dst = ft_putprecision_ho(str, dst, prec, fg);
	else
		dst = ft_pstrdup(str);
	return (dst);
}

static char	*ft_flags(char *str, t_format *fg)
{
	char	*dst;
	int		i;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	if (i != ft_pstrlen(str))
	{
		if (fg->flag->tag && (fg->conversion == 'o' || fg->conversion == 'O') &&
				ft_pstrlen(str) > fg->precision)
			dst = ft_strjoin_per("0", str);
		else if ((fg->flag->tag && fg->conversion == 'x'))
			dst = ft_strjoin_per("0x", str);
		else if (fg->flag->tag && fg->conversion == 'X')
			dst = ft_strjoin_per("0X", str);
		else
			dst = str;
	}
	else
		dst = ft_pstrdup(str);
	return (dst);
}

static void	ft_zero(char *dst, char *str, t_format *fg)
{
	str[1] = '0';
	if (fg->conversion == 'x' || fg->conversion == 'p')
		dst[1] = 'x';
	else if (fg->conversion == 'X')
		dst[1] = 'X';
}

static char	*ft_width(char *str, t_format *fg)
{
	char	*dst;
	int		width;

	width = fg->width - ft_pstrlen(str);
	if (width >= 0)
	{
		dst = ft_pstrnew(width);
		if (fg->flag->zero && !fg->flag->left && !fg->did_p)
		{
			dst = ft_pmemset(dst, '0', width);
			if (((fg->conversion == 'x' || fg->conversion == 'X')
						&& fg->flag->tag && !ft_pstrequ(str, "0"))
					|| fg->conversion == 'p')
				ft_zero(dst, str, fg);
			dst = ft_strjoin_per(dst, str);
		}
		else if (fg->flag->left)
			dst = ft_strjoin_per(str, ft_pmemset(dst, ' ', width));
		else
			dst = ft_strjoin_per(ft_pmemset(dst, ' ', width), str);
	}
	else
		dst = ft_pstrdup(str);
	return (dst);
}

char		*ft_transfo_hexoct(char *str, t_format *fg)
{
	char	*dst;
	int		prec;

	if (fg->conversion == 'x' && fg->did_p
		&& fg->precision == 0 && ft_pstrequ(str, "0"))
		str = ft_pstrdup("");
	if (fg->conversion == 'p' && ft_pstrequ(str, "0") && fg->did_p)
		str = ft_pstrdup("0x");
	else if (fg->conversion == 'p')
		str = ft_pstrjoin("0x", str);
	dst = ft_precision(str, fg);
	dst = ft_flags(dst, fg);
	dst = ft_width(dst, fg);
	return (dst);
}
