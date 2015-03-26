/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:31:04 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/15 08:41:04 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] - s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		i--;
	return (s1[i] - s2[i]);
}
