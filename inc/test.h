/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:10:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/19 20:12:06 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include "ftpf_backend.h"
# include "libftprintf.h"


# define TEST_OUTPUT_FILENAME "test_results.txt"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define DBL_INF    0x7FF0000000000000
#define DBL_NINF   0xFFF0000000000000
#define DBL_NAN    0x7FF0000000100000
#define DBL_PZERO  0x0000000000000000
#define DBL_NZERO  0x8000000000000000

#define LDBL_INF   0x7FFF0000000000000000L
#define LDBL_NINF  0xFFFF0000000000000000L
#define LDBL_NAN   0x7FFF0000000001000000L
#define LDBL_PZERO 0x00000000000000000000L
#define LDBL_NZERO 0x80000000000000000000L

typedef struct	s_testrange_dict_entry
{
	const char	*keyword;
	int			start;
	int			end;
}				t_testrange_dict_entry;
extern const t_testrange_dict_entry	g_testranges_dict[];

int		test(const char *fmt, ...);

typedef	int	(* t_unit_test) (void);
extern const t_unit_test	g_unit_tests[];
extern const char *g_unit_test_names[];
void	run_all_tests(void);
void	run_tests(int from_num, int to_num);
void	append_to_log(const char *fmt, ...);
int			assert_str(char *actual, char *expected);

#endif
