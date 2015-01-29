/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minicase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:34:09 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/24 08:32:50 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pt2d	ft_minicase(t_env env, t_pt2d pn)
{
	t_pt2d	pc;

	pc.x = pn.x / (int)env.sz_wall;
	pc.y = pn.y / (int)env.sz_wall;
	return (pc);
}
