/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:25:33 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:18:00 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pstrdup(const char *s1)
{
	char	*dst;

	dst = (char*)malloc(sizeof(char) * (ft_pstrlen(s1) + 1));
	ft_pstrncpy(dst, s1, ft_pstrlen(s1) + 1);
	return (dst);
}
