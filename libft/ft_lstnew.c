/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:37:01 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/08 16:24:13 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->next = NULL;
	if (content)
	{
		new_element->content = malloc(content_size);
		if (new_element->content)
			ft_memcpy(new_element->content, content, content_size);
		new_element->content_size = content_size;
	}
	else
	{
		new_element->content = NULL;
		new_element->content_size = 0;
	}
	return (new_element);
}
