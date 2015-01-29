/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:07:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:25:05 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pisdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}