/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 08:12:59 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/17 19:38:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putflags(char flg, t_format **fg)
{
	if (flg == '#')
		(*fg)->flag->tag = 1;
	if (flg == '-')
		(*fg)->flag->left = 1;
	if (flg == '0')
		(*fg)->flag->zero = 1;
	if (flg == '+')
		(*fg)->flag->signe = 1;
	if (flg == ' ')
		(*fg)->flag->blank = 1;
	if (flg == 'h')
		(*fg)->over_flag->l_short += 1;
	if (flg == 'l')
		(*fg)->over_flag->l_long += 1;
	if (flg == 'j')
		(*fg)->over_flag->l_intmax_t = 1;
	if (flg == 'z')
		(*fg)->over_flag->l_z = 1;
}
