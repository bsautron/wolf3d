/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:43:25 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:16:52 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ppow(int base, int pow)
{
	if (pow == 0)
		return (1);
	else if (pow == 1)
		return (base);
	else
		return (base * ft_ppow(base, pow - 1));
}
