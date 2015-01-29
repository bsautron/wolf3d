/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 12:34:07 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/21 02:35:37 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_params(char **argv, int argc)
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
			while (argv[i][j] == argv[save_i][j])
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
