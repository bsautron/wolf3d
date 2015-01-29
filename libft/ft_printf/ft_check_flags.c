/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 07:50:56 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:28:09 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check_flags_aux2(char *my_fg, t_format **fg)
{
	int		i;
	char	*flags;

	i = 0;
	flags = ft_pstrdup("lhjz");
	while (ft_charcheck_in_str(my_fg[i], flags))
	{
		ft_putflags(my_fg[i], fg);
		i++;
	}
	return (i);
}

static int		ft_check_flags_aux(char *my_fg, t_format **fg)
{
	int		i;
	char	*flags;

	i = 0;
	flags = ft_pstrdup("#0-+ lhjz");
	while (ft_charcheck_in_str(my_fg[i], flags))
	{
		ft_putflags(my_fg[i], fg);
		i++;
	}
	return (i);
}

static char		*ft_makeprec(char *my_fg, int *i, t_format **fg)
{
	while (my_fg[*i + 1] == '0')
		(*i)++;
	(*fg)->precision = ft_patoi(&my_fg[*i + 1]);
	(*fg)->did_p = 1;
	if (!ft_pisdigit(my_fg[*i + 1]) && my_fg[*i] == '.')
		(*i)++;
	else if (!ft_pisdigit(my_fg[*i + 1]))
		(*i) += 0;
	else
		(*i) += ft_pintlen((*fg)->precision) + 1;
	return (my_fg);
}

int				ft_check_flags(const char *str, t_format **fg, va_list ap)
{
	char	*my_fg;
	char	*conversion;
	int		i;
	int		nb;
	int		j;

	i = 0;
	ft_initflags(fg);
	conversion = ft_pstrdup("sSpdDioOuUxXcC");
	my_fg = ft_pstrdup(&str[1]);
	nb = 0;
	i += ft_check_flags_aux(my_fg, fg);
	(*fg)->width = ft_patoi(&my_fg[i]);
	if ((*fg)->width != 0)
		i += ft_pintlen((*fg)->width);
	if (my_fg[i] == '.')
		my_fg = ft_makeprec(my_fg, &i, fg);
	if (my_fg[i] == '0')
		i++;
	i += ft_check_flags_aux(&my_fg[i], fg);
	if (ft_charcheck_in_str(my_fg[i], conversion))
		(*fg)->conversion = my_fg[i];
	else
		(*fg)->flag->blank = 0;
	return (i + 1);
}
