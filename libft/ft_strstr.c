/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:31:17 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/15 08:41:08 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*temp_s1;
	int		len_s2;

	temp_s1 = (char *)s1;
	len_s2 = ft_strlen(s2);
	if (!len_s2)
		return (temp_s1);
	while (*temp_s1)
	{
		if (*temp_s1 == s2[0] && !ft_strncmp(temp_s1, s2, len_s2))
			return (temp_s1);
		temp_s1++;
	}
	return (NULL);
}
