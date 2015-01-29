/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 09:06:17 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:02:45 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*ft_putmask(char *mask, char *bin)
{
	int		i;
	int		j;

	i = ft_pstrlen(mask) - 1;
	j = ft_pstrlen(bin) - 1;
	while (i >= 0)
	{
		if (mask[i] == 'x')
		{
			if (j >= 0)
				mask[i] = bin[j];
			else
				mask[i] = '0';
			j--;
		}
		i--;
	}
	return (mask);
}

static char				**ft_make_unicode(char *mask, char *bin, int *nb_bytes)
{
	char	**tab;
	int		k;

	tab = (char **)malloc(sizeof(char *) * (*nb_bytes + 1));
	mask = ft_putmask(mask, bin);
	k = 0;
	while (k < *nb_bytes)
	{
		tab[k] = (char *)malloc(sizeof(char) * 9);
		tab[k] = ft_pstrncpy(tab[k], mask, 8);
		mask += 8;
		k++;
	}
	tab[k] = 0;
	return (tab);
}

static unsigned int		ft_conv_bin_to_dec(char *bin)
{
	int		i;
	int		j;
	int		nb;

	j = 0;
	nb = 0;
	i = ft_pstrlen(bin) - 1;
	while (i >= 0)
	{
		nb += ft_ppow(2, j) * (bin[i] - '0');
		j++;
		i--;
	}
	return (nb);
}

static unsigned char	*ft_make_int(char **tab)
{
	unsigned char	*dst;
	int				i;

	i = 0;
	while (tab[i])
		i++;
	dst = (unsigned char *)malloc(sizeof(unsigned char) * (i + 1));
	i = 0;
	while (tab[i])
	{
		dst[i] = ft_conv_bin_to_dec(tab[i]);
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char					*ft_split_bytes(char *bin, int *nb_bytes)
{
	char			**tab;
	char			*tab_wchar;
	int				nb_bits;
	char			*mask[4];

	(*nb_bytes) = 0;
	mask[0] = ft_pstrdup("0xxxxxxx");
	mask[1] = ft_pstrdup("110xxxxx10xxxxxx");
	mask[2] = ft_pstrdup("1110xxxx10xxxxxx10xxxxxx");
	mask[3] = ft_pstrdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	nb_bits = ft_pstrlen(bin);
	if (++(*nb_bytes) && nb_bits <= 7)
		tab = ft_make_unicode(mask[0], bin, nb_bytes);
	else if (++(*nb_bytes) && nb_bits <= 11)
		tab = ft_make_unicode(mask[1], bin, nb_bytes);
	else if (++(*nb_bytes) && nb_bits <= 16)
		tab = ft_make_unicode(mask[2], bin, nb_bytes);
	else if (++(*nb_bytes))
		tab = ft_make_unicode(mask[3], bin, nb_bytes);
	tab_wchar = (char *)ft_make_int(tab);
	return (tab_wchar);
}
