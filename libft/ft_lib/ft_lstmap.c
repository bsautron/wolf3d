/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:00:02 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/09 17:26:30 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*t_start;

	new_lst = f(lst);
	t_start = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = f(lst);
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (t_start);
}
