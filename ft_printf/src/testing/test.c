/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:53:02 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/20 17:20:04 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "libftprintf.h"
#include "ftpf_backend.h"
#include "test.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int				test_num;

void	run_all_tests(void)
{
	run_tests(0, -1);
}

void	run_tests(int from_num, int to_num)
{
	test_num = from_num;
	if (to_num < from_num) to_num = 2147483647;
	int fail = 0;
	int num_fails = 0;
	int	num_run = 0;
	for (int i = from_num; i <= to_num && g_unit_tests[i] != NULL; i++)
	{
		printf("Test %4i:  %-42s [",test_num, g_unit_test_names[i]);
		fail = g_unit_tests[i]();
		if (fail)
			printf(RED "FAIL" RESET);
		else
			printf(GRN "PASS" RESET);
		printf("]\n");
		num_fails += fail;
		num_run++;
		test_num++;
	}
	printf("Tests completed. %i/%i tests passed.\n",
			num_run - num_fails, num_run);
	if (num_run - num_fails != num_run)
		printf("See %s for details.\n", TEST_OUTPUT_FILENAME);
}

int		test(const char *fmt, ...)
{
	va_list			args;
	va_list			args_copy;
	t_stringbuilder	*sb;
	char			*ret_mine;
	char			*ret_sys;
	int				ret_val_mine;
	int				ret_val_sys;
	int				failed = 0;
	int				fd;
	
	//initialize test
	sb = ft_sbnew();
	va_start(args, fmt);
	va_copy(args_copy, args);
	//get mine
	ret_val_mine = ft_vsbprintf(sb, fmt, args);
	ret_mine = ft_sbtostr(sb);
	//get system
	ret_val_sys = vasprintf(&ret_sys, fmt, args_copy);
	//compare
	if (ret_val_mine != ret_val_sys || strcmp(ret_mine, ret_sys) != 0)
		failed = 1;
	if (failed)
	{
		fd = open(TEST_OUTPUT_FILENAME, O_CREAT | O_WRONLY | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
		dprintf(fd, "Test %3i (%s) : FAILED.\n", test_num, g_unit_test_names[test_num]);
		dprintf(fd, "    Returned expected %i, actual %i\n",
				ret_val_sys, ret_val_mine);
		dprintf(fd, "      expected: \"%s\"\n", ret_sys);
		dprintf(fd, "      actual:   \"%s\"\n", ret_mine);
		close(fd);
	}
	//clean up
	ft_sbdel(&sb);
	free(ret_mine);
	free(ret_sys);
	va_end(args);
	va_end(args_copy);
	return (failed);
}


void	append_to_log(const char *fmt, ...)
{
	va_list			args;
	int				fd;
	
	va_start(args, fmt);
	fd = open(TEST_OUTPUT_FILENAME, O_CREAT | O_WRONLY | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd > 0)
	{
		vdprintf(fd, fmt, args);
		close(fd);
	}
	va_end(args);
}

