/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 21:06:41 by bsautron          #+#    #+#             */
/*   Updated: 2014/07/16 23:14:43 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort(char **argv, int argc)
{
	char	*save;
	int		save_i;
	int		i;
	int		j;

	j = 0;
	save_i = 0;
	while (save_i < argc)
	{
		i = save_i + 1;
		while (i < argc)
		{
			while (argv[i][j] == argv[save_i][j] && argv[i][j])
				j++;
			if (argv[i][j] < argv[save_i][j])
			{
				save = argv[i];
				argv[i] = argv[save_i];
				argv[save_i] = save;
			}
			j = 0;
			i++;
		}
		save_i++;
	}
}

void	ft_sort_wordtab(char **tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	sort(tab, len);
}
