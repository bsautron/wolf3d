/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_hexoct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:56:17 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:26:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_trans(int nb, char *dst, t_format *fg, int len)
{
	if (nb > 9 && fg->conversion == 'X')
		dst[len - 1] = nb + 'A' - 10;
	else if (nb > 9)
		dst[len - 1] = nb + 'a' - 10;
	else
		dst[len - 1] = nb + '0';
}

char		*ft_bin_to_hexoct(char *str, int conv, t_format *fg)
{
	int		len;
	int		i;
	int		j;
	int		nb;
	char	*dst;

	i = ft_pstrlen(str);
	len = i / conv;
	if (i % conv)
		len++;
	dst = ft_pstrnew(len);
	while (i > 0)
	{
		nb = 0;
		j = 0;
		while (j < conv && i > 0)
		{
			nb += (str[i - 1] - '0') * ft_ppow(2, j);
			i--;
			j++;
		}
		ft_trans(nb, dst, fg, len);
		len--;
	}
	return (dst);
}
