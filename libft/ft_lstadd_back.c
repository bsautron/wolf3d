/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 23:15:02 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/10 17:19:34 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*tmp_lst;

	tmp_lst = *alst;
	if (tmp_lst)
	{
		while (tmp_lst->next)
			tmp_lst = tmp_lst->next;
		tmp_lst->next = new;
	}
	else
		*alst = new;
}
