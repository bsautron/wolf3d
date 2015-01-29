/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfo_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:53:47 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:27:47 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_prec_str(char *str, t_format *f, int *tab_b, int len_b)
{
	char	*dst;
	int		i;
	int		i_b;
	int		j;

	i = 0;
	j = 0;
	i_b = tab_b[0];
	if (f->conversion == 'S' || (f->conversion == 's' && f->over_flag->l_long))
	{
		while (i < f->precision)
		{
			if (i == i_b)
			{
				j++;
				i_b += tab_b[j];
			}
			i++;
		}
		if (i != i_b)
			f->precision = i_b - tab_b[j];
	}
	dst = ft_pstrdup(str);
	dst[f->precision] = '\0';
	return (dst);
}

static char	*ft_precision(char *str, t_format *fg, int *tab_b, int len_b)
{
	char	*dst;
	int		prec;

	prec = fg->precision - ft_pstrlen(str);
	if (prec >= 0 && fg->conversion != 'c' && fg->conversion != 'C'
			&& fg->conversion != 's' && fg->conversion != 'S')
		dst = ft_putprecision(str, dst, prec, fg);
	else if ((fg->conversion == 's' || fg->conversion == 'S') && fg->did_p)
		dst = ft_prec_str(str, fg, tab_b, len_b);
	else if (fg->precision == 0 && ft_pstrequ("0", str) && fg->did_p)
		return ("");
	else
		dst = str;
	return (dst);
}

static char	*ft_flags(char *str, t_format *fg)
{
	char	*dst;

	if (fg->conversion != 'u' && fg->conversion != 'U'
		&& fg->conversion != 'c' && fg->conversion != 'C'
		&& fg->conversion != 'S' && fg->conversion != 's')
	{
		if (fg->flag->signe && str[0] != '-')
			dst = ft_strjoin_per_aux("+", str);
		else if (fg->flag->blank && str[0] != '-')
			dst = ft_strjoin_per_aux(" ", str);
		else
			dst = str;
	}
	else
		dst = str;
	return (dst);
}

static char	*ft_width(char *str, t_format *fg)
{
	char	*dst;
	int		width;
	int		len;

	if (ft_pstrlen(str) == 0 && str[0] == 0)
		len = 1;
	else
		len = ft_pstrlen(str);
	width = fg->width - len;
	if ((fg->conversion == 's' || fg->conversion == 'S')
		&& fg->did_p && fg->precision == 0)
		width++;
	if (width > 0)
		dst = ft_putwidth(str, width, fg);
	else
		dst = str;
	return (dst);
}

char		*ft_transfo_int(char *str, t_format *fg, int *tab_b, int len_b)
{
	char	*dst;
	int		prec;

	dst = ft_precision(str, fg, tab_b, len_b);
	dst = ft_flags(dst, fg);
	dst = ft_width(dst, fg);
	return (dst);
}
