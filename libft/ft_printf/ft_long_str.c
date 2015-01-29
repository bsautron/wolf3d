/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 04:56:24 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:28:54 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FUCKCHAR	char *dst, char *bin
#define FUCKCCHAR	const char *f, char *dst
#define FUCKINT		int **tab_b, int *nb_bytes

static int	*ft_add_int(int *tab_b, int nb, int len)
{
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * (len + 1));
	i = 0;
	while (i < len)
	{
		tab[i] = tab_b[i];
		i++;
	}
	tab[i] = nb;
	free(tab_b);
	return (tab);
}

static char	*ft_str_spec2(int *tab, FUCKCHAR, FUCKINT, t_format *fg)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * 2);
	while (tab[i])
	{
		if (tab[i] > 127)
		{
			bin = ft_binary(tab[i], fg);
			temp = ft_split_bytes(bin, nb_bytes);
			*tab_b = ft_add_int(*tab_b, *nb_bytes, i);
		}
		else
		{
			*tab_b = ft_add_int(*tab_b, 1, i);
			temp[0] = tab[i];
			temp[1] = '\0';
		}
		dst = ft_pstrjoin(dst, temp);
		i++;
	}
	return (dst);
}

static char	*ft_str_spec(char *dst, FUCKINT, va_list ap, t_format *fg)
{
	int				*tab;
	char			*bin;
	int				i;

	tab = (int *)malloc(sizeof(int) * 65);
	tab = va_arg(ap, int *);
	if (!tab)
		dst = ft_pstrdup("(null)");
	else
		dst = ft_str_spec2(tab, dst, bin, tab_b, nb_bytes, fg);
	dst = ft_transfo_int(dst, fg, *tab_b, i);
	return (dst);
}

char		*ft_long_str(va_list ap, FUCKCCHAR, FUCKINT, t_format *fg)
{
	if (*f == 'S' || (*f == 's' && fg->over_flag->l_long))
		dst = ft_str_spec(dst, tab_b, nb_bytes, ap, fg);
	else
	{
		dst = va_arg(ap, char *);
		if (!dst)
			dst = ft_pstrdup("(null)");
		dst = ft_transfo_int(dst, fg, *tab_b, ft_pstrlen(dst));
	}
	return (dst);
}
