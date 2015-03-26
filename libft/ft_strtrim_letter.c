/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_letter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 04:56:15 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/19 06:37:49 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_letter(char *str)
{
	char	*temp;
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (str)
	{
		temp = ft_strnew(27);
		while (str[i])
		{
			if (!ft_charcheck_in_str(str[i], temp))
			{
				temp[j] = str[i];
				j++;
			}
			i++;
		}
		dest = ft_strdup(temp);
		free(temp);
		if (dest)
			return (dest);
	}
	return (NULL);
}
