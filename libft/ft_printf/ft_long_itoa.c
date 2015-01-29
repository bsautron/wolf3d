/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:04:14 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:14:27 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*reverse(char *str)
{
	long long int		len;
	long long int		i;
	char				temp_char;

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

static char				*ft_itoa2(char *str, long long int n)
{
	char			*temp_str;
	long long int	i;
	int				signe;

	signe = 1;
	temp_str = str;
	i = 0;
	if (n < 0)
	{
		signe = -1;
		n = -n;
	}
	while (n)
	{
		temp_str[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (signe == -1)
		temp_str[i] = '-';
	return (temp_str);
}

static char				*ft_itoa_exept(char *str, long long int n)
{
	char			*temp_str;
	long long int	save;

	temp_str = str;
	if (!n)
	{
		temp_str[0] = '0';
		temp_str[1] = '\0';
	}
	return (temp_str);
}

static long long int	int_len(long long int n, long long int len)
{
	if (n < 0)
		return (int_len(-n, len + 1));
	else if (n == 0)
		return (len);
	else
		return (int_len(n / 10, len + 1));
}

char					*ft_long_itoa(long long int n)
{
	char			*str;
	long long int	len;

	if (n == -9223372036854775807 - 1)
		str = ft_pstrdup("-9223372036854775808");
	else if (n == 0)
		str = ft_pstrdup("0");
	else
	{
		len = int_len(n, 0);
		str = ft_pstrnew(len + 1);
		str = reverse(ft_itoa2(str, n));
	}
	return (str);
}
