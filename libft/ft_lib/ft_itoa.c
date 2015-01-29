/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:04:14 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/07 23:00:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*reverse(char *str)
{
	int		len;
	int		i;
	char	temp_char;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp_char = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp_char;
		i++;
	}
	return (str);
}

static char		*ft_itoa2(char *str, int n)
{
	char	*temp_str;
	int		i;
	int		signe;

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

static char		*ft_itoa_exept(char *str, int n)
{
	char	*temp_str;
	int		save;

	(void)save;
	temp_str = str;
	if (!n)
	{
		temp_str[0] = '0';
		temp_str[1] = '\0';
	}
	else if (n == -2147483648)
	{
		save = n % 10;
		n = n / 10;
		str = ft_reverse(ft_itoa2(str, n));
		str[10] = '8';
	}
	return (temp_str);
}

static int		int_len(int n, int len)
{
	if (n < 0)
		return (int_len(-n, len + 1));
	else if (n == 0)
		return (len);
	else
		return (int_len(n / 10, len + 1));
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		str = ft_strnew(1 + 1);
		str = ft_itoa_exept(str, 0);
	}
	else if (n == -2147483648)
	{
		str = ft_strnew(10 + 1);
		str = ft_itoa_exept(str, n);
	}
	else
	{
		len = int_len(n, 0);
		str = ft_strnew(len + 1);
		str = reverse(ft_itoa2(str, n));
	}
	return (str);
}
