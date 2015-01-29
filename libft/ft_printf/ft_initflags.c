/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 07:04:38 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/14 23:26:59 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initflags(t_format **fg)
{
	*fg = (t_format *)malloc(sizeof(t_format));
	(*fg)->flag = (struct s_flag *)malloc(sizeof(struct s_flag));
	(*fg)->over_flag = (struct s_over *)malloc(sizeof(struct s_over));
	(*fg)->flag->left = 0;
	(*fg)->flag->zero = 0;
	(*fg)->flag->signe = 0;
	(*fg)->flag->blank = 0;
	(*fg)->flag->tag = 0;
	(*fg)->width = 0;
	(*fg)->precision = 0;
	(*fg)->did_p = 0;
	(*fg)->my_god = 0;
	(*fg)->over_flag->l_long = 0;
	(*fg)->over_flag->l_short = 0;
	(*fg)->over_flag->l_double = 0;
	(*fg)->over_flag->l_intmax_t = 0;
	(*fg)->over_flag->l_z = 0;
	(*fg)->conversion = 0;
}
