/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:34:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/18 23:14:20 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DBL_MANTISSA 0x000FFFFFFFFFFFFFlu
#define DBL_EXPONENT 0x7FF0000000000000lu
#define DBL_SIGNBIT  0x8000000000000000lu
#define DBL_IMPLCT_1 0x0010000000000000lu


void		print_bits(unsigned long *p, unsigned long start,
				unsigned long stop, int dot);
double		make_dbl(unsigned long mantissa, int exponent, int sign);
int			get_exp(double dbl);

void		float_freeform_test(int argc, char **argv)
{
	double dbl = 1.5;
	printf("Handling the double: %.18f\n", dbl);
	usleep(100000);
	ft_printf("Output: \"%f\"\n", dbl);

	(void)argc;
	(void)argv;
}

void 		freeform_test(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int num = 0x12345678;
	unsigned long long n2 = 0x123456789abcde67;

	ft_printf("precision d:  % m\n", &num);
	ft_printf("precision d:  %#b\n", &num);
	ft_printf("precision 0:  %.0m\n", &num);
	ft_printf("precision 0:  %.0b\n", &num);

	ft_printf("precision 2:  %.2m\n", &num);
	ft_printf("precision 2:  %.2b\n", &num);

	ft_printf("precision 4:  %.4m\n", &num);
	ft_printf("precision 4:  %.4b\n", &num);

	ft_printf("precision 8:  % .8m\n", &n2);
	ft_printf("precision 8:  %#.8b\n", &n2);

	ft_printf("precision 16: %.16m\n", &num);
	ft_printf("precision 16: %.16b\n", &num);

	ft_printf("precision h:  %hm\n", &num);
	ft_printf("precision h:  %hb\n", &num);

	ft_printf("precision hh: % hhm\n", &num);
	ft_printf("precision hh: %#hhb\n", &num);

	ft_printf("precision ll: %llm\n", &n2);
	ft_printf("precision ll: %llb\n", &n2);

	ft_printf("precision l:  %lm\n", &n2);
	ft_printf("precision l:  %lb\n", &n2);

	ft_printf("precision L:  %Lm\n", &n2);
	ft_printf("precision L:  %Lb\n", &n2);
	ft_printf("width 45 rj:  \"%#45b\"\n", &num);
	ft_printf("width 45 lj:  \"%-#45b\"\n", &num);



	ft_printf("precision 16 with space padding: % .16m\n", &num);
	ft_printf("width 13:    \"%13m\"\n", &num);
	ft_printf("width 13 lj: \"%-13m\"\n", &num);

	char s1[] = "Hello, World!";
	ft_printf("normal:  \"%.30m\"\n", s1);
	ft_printf("altform: \"%#.30m\"\n", s1);
	ft_printf("w/ spce: \"% #.30m\"\n", s1);


	/*
	if (argc == 2)
	{
		ft_printf(argv[1]);
		ft_printf("\n");
	}
	else if (argc == 3)
		ft_printf("%s%s\n", argv[1], argv[2]);
	else if (argc >= 4)
		ft_printf("%s%s%s\n", argv[1], argv[2], argv[3]);
	*/
}

void	unit_testing(int argc, char **argv)
{
	int from, to;
	int i = 0;
	if (argc > 1)
	{
		while (g_testranges_dict[i].keyword != NULL
				&& strcmp(g_testranges_dict[i].keyword, argv[1]) != 0)
			i++;
		if (g_testranges_dict[i].keyword != NULL)
		{
			from = g_testranges_dict[i].start;
			to = g_testranges_dict[i].end;
		}
		else
		{
			from = atoi(argv[1]);
			if (argc > 2)
				to = atoi(argv[2]);
			else
				to = -1;
		}
		run_tests(from, to);
	}
	else
	{
		run_all_tests();
	}
}

int main(int argc, char **argv)
{
	unit_testing(argc, argv);
	//float_freeform_test(argc, argv);
	//freeform_test(argc, argv);
	return (0);
}




/*
const static unsigned long	prec_upper_limits[20] =
{
	0u,
	9u,
	99u,
	999u,
	9999u,
	99999u,
	999999u,
	9999999u,
	99999999u,
	999999999u,
	9999999999u,
	99999999999u,
	999999999999u,
	9999999999999u,
	99999999999999u,
	999999999999999u,
	9999999999999999u,
	99999999999999999u,
	999999999999999999u,
	9999999999999999999u
};
*/


void		print_bits(unsigned long *p, unsigned long start, unsigned long stop, int dot)
{
	unsigned long mask;

	mask = 1lu << (unsigned long)(stop);
	for (unsigned long i = start; i <= stop; i++)
	{
		if ((*p) & mask)
			printf("1");
		else
			printf("0");
		if (dot && (i + 1) % 4 == 0)
			printf(".");
		mask >>= 1;
	}
}

double	make_dbl(unsigned long mantissa, int exponent, int sign)
{
	unsigned long	dbl;
	unsigned long	exp;

	dbl = mantissa;
	exp = ((unsigned long)(exponent + 1023));
	dbl |= (exp << 52);
	if (sign)
		dbl |= (1lu << 63);
	return (*((double *)(&dbl)));
}

int		get_exp(double dbl)
{
	unsigned long	exp;

	exp = (*((unsigned long *)(&dbl))) & DBL_EXPONENT;
	return ((exp >> 52) - 1023);
}
