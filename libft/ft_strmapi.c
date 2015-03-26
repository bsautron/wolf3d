/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:57:51 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/07 21:27:06 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))

{
	char	*new_s;
	int		i;

	i = 0;
	new_s = NULL;
	if (s && f)
	{
		new_s = ft_strnew(ft_strlen(s));
		while (s[i])
		{
			new_s[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (new_s);
}
