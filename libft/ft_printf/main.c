/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 09:34:58 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/18 04:23:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <limits.h>
#include <locale.h>

//#define TEST_COMP_INT
//#define TEST_COMP_HEX
//#define TEST_COMP_OCT
//#define TEST_ERROR
//#define TEST_RANDOM

int		main(int argc, char **argv)
{
	int				i;
	char			*fmt;
	long long int	nb;
	int				n1 = 232;
	int				n2 = 206;
	int				n3 = 177;
	int				ret;
	int				retm;

	char *l = setlocale(LC_ALL, "en_US.UTF-8"); 
/*
	if (l == NULL) 
		printf("Locale not set\n"); 
	else
		printf("Locale set to %s\n", l); 
*/
	nb = ft_patoi(argv[1]);
	ret = dprintf(1, "{%.5p}\n", 0);
	dprintf(1, "ret = %d\n", ret);
	ft_pputstr("-----------\n");
	retm = ft_printf("{%.5p}\n", 0);
	dprintf(1, "retm = %d\n", retm);
#ifdef TEST_COMP_OCT
	i = 1;
	dprintf(1, "{red}%s{eoc}\n", "---Le test avec les OCT seulement---");

	//TEST 01
	dprintf(1, "%d = %o\n", i, (int)nb);
	ft_printf("%d = %o\n", i, nb);
	i++;

	//TEST 02
	dprintf(1, "%d = %#o\n", i, (int)nb);
	ft_printf("%d = %#o\n", i, nb);
	i++;

	//TEST 03
	dprintf(1, "%d = %10o\n", i, (int)nb);
	ft_printf("%d = %10o\n", i, nb);
	i++;

	//TEST 04
	dprintf(1, "%d = %#5o\n", i, (int)nb);
	ft_printf("%d = %#5o\n", i, nb);
	i++;

	//TEST 05
	dprintf(1, "%d = %07o\n", i, (int)nb);
	ft_printf("%d = %07o\n", i, nb);
	i++;

	//TEST 06
	dprintf(1, "%d = %#-8o\n", i, (int)nb);
	ft_printf("%d = %#-8o\n", i, nb);
	i++;

	//TEST 07
	dprintf(1, "%d = %#08o\n", i, (int)nb);
	ft_printf("%d = %#08o\n", i, nb);
	i++;

	//TEST 08
	dprintf(1, "%d = %.10o\n", i, (int)nb);
	ft_printf("%d = %.10o\n", i, nb);
	i++;

	//TEST 09
	dprintf(1, "%d = %#2.3o\n", i, (int)nb);
	ft_printf("%d = %#2.3o\n", i, nb);
	i++;

	//TEST 10
	dprintf(1, "%d = %-.10o\n", i, (int)nb);
	ft_printf("%d = %-.10o\n", i, nb);
	i++;

#endif
#ifdef TEST_COMP_HEX
	i = 1;
	dprintf(1, "---Le test avec les HEX seulement---\n");
	//TEST 01
	dprintf(1, "%d = %#X\n", i, (int)nb);
	ft_printf("%d = %#X\n", i, nb);
	i++;

	//TEST 02
	dprintf(1, "%d = %#x\n", i, (int)nb);
	ft_printf("%d = %#x\n", i, nb);
	i++;

	//TEST 03
	dprintf(1, "%d = %10x\n", i, (int)nb);
	ft_printf("%d = %10x\n", i, nb);
	i++;

	//TEST 04
	dprintf(1, "%d = %#5x\n", i, (int)nb);
	ft_printf("%d = %#5x\n", i, nb);
	i++;

	//TEST 05
	dprintf(1, "%d = %07x\n", i, (int)nb);
	ft_printf("%d = %07x\n", i, nb);
	i++;

	//TEST 06
	dprintf(1, "%d = %#-8x\n", i, (int)nb);
	ft_printf("%d = %#-8x\n", i, nb);
	i++;

	//TEST 07
	dprintf(1, "%d = %#08x\n", i, (int)nb);
	ft_printf("%d = %#08x\n", i, nb);
	i++;

	//TEST 08
	dprintf(1, "%d = %.10x\n", i, (int)nb);
	ft_printf("%d = %.10x\n", i, nb);
	i++;

	//TEST 09
	dprintf(1, "%d = %#5.10x\n", i, (int)nb);
	ft_printf("%d = %#5.10x\n", i, nb);
	i++;

	//TEST 10
	dprintf(1, "%d = %-.10x\n", i, (int)nb);
	ft_printf("%d = %-.10x\n", i, nb);
	i++;
#endif
#ifdef TEST_COMP_INT
	i = 1;
	dprintf(1, "---Le test avec les INT seulement---\n");
	//TEST 01
	dprintf(1, "%d = %d\n", i, (int)nb);
	ft_printf("%d = %d\n", i, nb);
	i++;

	//TEST 02
	dprintf(1, "%d = %d\n", i, -(int)nb);
	ft_printf("%d = %d\n", i, -nb);
	i++;

	//TEST 03
	dprintf(1, "%d = %05d\n", i, (int)nb);
	ft_printf("%d = %05d\n", i, nb);
	i++;

	//TEST 04
	dprintf(1, "%d = %05d\n", i, -(int)nb);
	ft_printf("%d = %05d\n", i, -nb);
	i++;

	//TEST 05
	dprintf(1, "%d = %5d\n", i, (int)nb);
	ft_printf("%d = %5d\n", i, nb);
	i++;

	//TEST 06
	dprintf(1, "%d = %+10d\n", i, (int)nb);
	ft_printf("%d = %+10d\n", i, nb);
	i++;

	//TEST 07
	dprintf(1, "%d = %+10d\n", i, -(int)nb);
	ft_printf("%d = %+10d\n", i, -nb);
	i++;

	//TEST 08
	dprintf(1, "%d = %+010d\n", i, (int)nb);
	ft_printf("%d = %+010d\n", i, nb);
	i++;

	//TEST 09
	dprintf(1, "%d = %+010d\n", i, (int)-nb);
	ft_printf("%d = %+010d\n", i, -nb);
	i++;

	//TEST 10
	dprintf(1, "%d = %-9d\n", i, (int)nb);
	ft_printf("%d = %-9d\n", i, nb);
	i++;

	//TEST 11
	dprintf(1, "%d = %-9d\n", i, (int)-nb);
	ft_printf("%d = %-9d\n", i, -nb);
	i++;

	//TEST 12
	dprintf(1, "%d = % d\n", i, (int)nb);
	ft_printf("%d = % d\n", i, nb);
	i++;

	//TEST 13
	dprintf(1, "%d = %.11d\n", i, (int)nb);
	ft_printf("%d = %.11d\n", i, nb);
	i++;

	//TEST 14
	dprintf(1, "%d = %.11d\n", i, (int)-nb);
	ft_printf("%d = %.11d\n", i, -nb);
	i++;

	//TEST 15
	dprintf(1, "%d = % .3d\n", i, (int)nb);
	ft_printf("%d = % .3d\n", i, nb);
	i++;

	//TEST 16
	dprintf(1, "%d = %**.3d\n", i, 3, 9, (int)nb);
	ft_printf("%d = %**.3d\n", i, 3, 9, nb);
	i++;

#endif

#ifdef TEST_ERROR
	/*
	   i = 1;
	   ft_putstr("---Le test avec des ERRORs---\n");
	//TEST 01
	dprintf(1, "%d = %-5]d\n", i, nb);
	ft_printf("%d = %-5]d\n", i, nb);
	i++;

	//TEST 02
	dprintf(1, "%d = %-5.5-10-d\n", i, nb);
	ft_printf("%d = %-5-d\n", i, nb);
	i++;
	 */
#endif
#ifdef TEST_RANDOM	
	i = 1;
	dprintf(1, "---RANDOM party---\n");
	//dprintf(1, "%d = %19.5d\n",i ,23);
	//dprintf(1,"%D\n", nb);
	dprintf(1 ,"envirion %025p des francais sont con!\n", &i);
	ft_printf("envirion %025p des francais sont con!\n",  &i);

	printf("%d = 4567 |%-10]5d| plip\n", 12);
	ft_printf("%d = 4567 |%-10]5d| plip\n", 12);

	printf("%d = 44567 |%10]5d| plip\n", i, 12);
	ft_printf("%d = 44567 |%10]5d| plip\n", i, 12);
	i++;

	printf("%d = 4|%10.5d|\n", i, -12);
	ft_printf("%d = 4|%10.5d|\n", i, -12);
	i++;

	printf("%d = 4|%10d|\n", i, -12);
	ft_printf("%d = 4|%10d|\n", i, -12);
	i++;

	printf("%d = 4|%010d|\n", i, -12); 
	ft_printf("%d = 4|%010d|\n", i, -12); 
	i++;

	printf("%d = 4|%-10.5d|\n", i, -12);
	ft_printf("%d = 4|%-10.5d|\n", i, -12);
	i++;

	printf("%d = 4|%-010.5d|\n", i, -12);
	ft_printf("%d = 4|%-010.5d|\n", i, -12);
	i++;

	printf("%010.5d\n", -42);
	printf("%010.5u\n", 42);
	printf("%010.5i\n", -42);
	printf("%010.5U\n", 42);
	printf("%010.5x\n", 0xff);
	printf("%010.5X\n", 0xff);
	printf("%010.5o\n", 0732);
	printf("%010.5O\n", 042);
	printf("%025.20s\n", "This is a string");
	printf("%010.5c\n", 'c');
	ft_pputstr("--------------------------------\n");
	ft_printf("%010.5d\n", -42);
	ft_printf("%010.5u\n", 42);
	ft_printf("%010.5i\n", -42);
	ft_printf("%010.5U\n", 42);
	ft_printf("%010.5x\n", 0xff);
	ft_printf("%010.5X\n", 0xff);
	ft_printf("%010.5o\n", 0732);
	ft_printf("%010.5O\n", 042);
	ft_printf("%025.20s\n", "This is a string");
	ft_printf("%010.5c\n", 'c');
#endif
	return 0;
}
