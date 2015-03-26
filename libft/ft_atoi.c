/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 23:19:32 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/07 16:04:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rec_atoi(const char *str, int rez)
{
	if (ft_isdigit(*str))
		return (rec_atoi(str + 1, 10 * rez + (*str - '0')));
	return (rez);
}

int			ft_atoi(const char *str)
{
	int		signe;

	signe = 1;
	while (*str <= ' ')
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || signe == -1)
		str++;
	if (ft_isdigit(*str))
		return (signe * rec_atoi(str, 0));
	return (0);
}
