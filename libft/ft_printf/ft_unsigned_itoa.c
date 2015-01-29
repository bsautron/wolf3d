/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:04:14 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:29:23 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*reverse(char *str)
{
	t_ullong	len;
	t_ullong	i;
	char		temp_char;

	i = 0;
	len = ft_pstrlen(str);
	while (i < len / 2)
	{
		temp_char = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp_char;
		i++;
	}
	return (str);
}

static char		*ft_itoa2(char *str, t_ullong n)
{
	char		*temp_str;
	t_ullong	i;

	temp_str = str;
	i = 0;
	while (n)
	{
		temp_str[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (temp_str);
}

static char		*ft_itoa_exept(char *str, t_ullong n)
{
	char		*temp_str;
	t_ullong	save;

	temp_str = str;
	if (!n)
	{
		temp_str[0] = '0';
		temp_str[1] = '\0';
	}
	return (temp_str);
}

static t_ullong	int_len(t_ullong n, t_ullong len)
{
	if (n == 0)
		return (len);
	else
		return (int_len(n / 10, len + 1));
}

char			*ft_unsigned_itoa(t_ullong n)
{
	t_ullong	len;
	char		*str;

	if (n == 0)
		str = ft_pstrdup("0");
	else
	{
		len = int_len(n, 0);
		str = ft_pstrnew(len + 1);
		str = reverse(ft_itoa2(str, n));
	}
	return (str);
}
