/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:15:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/21 00:06:39 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** Add unit tests to this file. Return 1 if fail, 0 if pass.
**
** All functions of the prototype:
**
**     int    foo(void)
**
** will be considered a unit test.
*/

const t_testrange_dict_entry g_testranges_dict[] = {
	{"nospec", 0, 2}, 				//no specifiers
	{NULL, -1, -1}
};

//Tests with no specifiers
int		no_specifier_test(void){return test("hello, world!");}
int		empty_string(void){return test("");}
int		some_escaped_chars(void){return test("\t\n\r\v\f\n");}

//%% Tests
int		pct_basic(void){return test("%%");}
int		pct_5w(void){return test("%5%");}
int		pct_5wlj(void){return test("%-5%");}
int		pct_5wzp(void){return test("%05%");}
int		pct_5wljzp(void){return test("%-05%");}

//Null specifier tests
int		nullspec_basic(void){return test("%");}
int		nullspec_5w(void){return test("%5");}
int		nullspec_5wzp(void){return test("%05");}
int		nullspec_5wzplj(void){return test("%-05");}
int		nullspec_5wlj(void){return test("%-5");}

//String specifiers - no modifiers
int		basic_string_expansion(void){return test("hello, %s.", "gavin");}
int		only_string_expansion(void){return test("%s", "testing testing");}
int		two_string_expansions(void){return test("%s%s", "hello", "world");}
int		two_string_expansions2(void){return test("..%s stuff %s", "a", "b");}
int		empty_string_expansion(void){return test("this %s is empty", "");}
int		full_then_empty_string(void){return test("this %s is %s", "hello", "");}
int		empty_then_full_string(void){return test("this %s is %s", "", "hello");}
int		three_strings(void){return test("%s%s%s", "1", "2", "3's a charm");}
//String specifiers with field_width, space- or zero-padded
int		space_padded_field_width(void){return test("%32s", "abc");}
int		space_padded_field_width2(void){return test("%16s", "nark nark");}
int		space_padded_over_field_width(void){return test("%5s", "goes over");}
int		zero_padded_field_width(void){return test("%021s", "abc");}
int		zero_padded_over_field_width(void){return test("%05s", "goes over");}
//String specifiers with field_width, space- or zero-padded, left-justified
int		space_padded_field_width_lj(void){return test("%-32s", "abc");}
int		space_padded_field_width2_lj(void){return test("%-16s", "nark nark");}
int		space_padded_over_field_width_lj(void){return test("%-5s", "goes over");}
int		zero_padded_field_width_lj(void){return test("%-021s", "abc");}
int		zero_padded_over_field_width_lj(void){return test("%-05s", "goes over");}
//String specifiers with precision
int		string_prec_notrunc(void){return test("%.7s", "hello");}
int		string_prec_trunc(void){return test("%.3s", "hello");}
int		string_prec_default(void){return test("%.s", "hello");}
int		string_prec_zero(void){return test("%.0s", "hello");}
int		two_strings_prec_2trunc(void){return test("%.3s%.2s", "holla", "bitch");}
int		two_strings_prec_1trunc_a(void){return test("%.2s%.7s", "hello", "world");}
int		two_strings_prec_1trunc_b(void){return test("%.7s%.2s", "hello", "world");}
int		two_strings_prec_0trunc(void){return test("%.5s%7s", "yo", "boi");}
//String specifiers with both precision and field width
int		string_prec_width_notrunc(void){return test("%7.5s", "yolo");}
int		string_prec_width_trunc(void){return test("%7.5s", "bombastic");}
int		string_prec_width_notrunc_lj(void){return test("%-7.5s", "yolo");}
int		string_prec_width_trunc_lj(void){return test("%-7.5s", "tubular");}
int		two_str_prec_width_2fit_0trunc(void){return test("%7.7s%7.7s", "hello", "world");}
int		two_str_prec_width_1fit_a_0trunc(void){return test("%3.7s%7.7s", "hello", "world");}
int		two_str_prec_width_1fit_b_0trunc(void){return test("%7.7s%3.7s", "hello", "world");}
int		two_str_prec_width_0fit_0trunc(void){return test("%3.7s%3.7s", "hello", "world");}
int		two_str_prec_width_2fit_1trunc_a(void){return test("%7.3s%7.7s", "hello", "world");}
int		two_str_prec_width_1fit_a_1trunc_a(void){return test("%3.3s%7.7s", "hello", "world");}
int		two_str_prec_width_1fit_b_1trunc_a(void){return test("%7.3s%3.7s", "hello", "world");}
int		two_str_prec_width_0fit_1trunc_a(void){return test("%3.3s%3.7s", "hello", "world");}
int		two_str_prec_width_2fit_1trunc_b(void){return test("%7.7s%7.3s", "hello", "world");}
int		two_str_prec_width_1fit_a_1trunc_b(void){return test("%3.7s%7.3s", "hello", "world");}
int		two_str_prec_width_1fit_b_1trunc_b(void){return test("%7.7s%3.3s", "hello", "world");}
int		two_str_prec_width_0fit_1trunc_b(void){return test("%3.7s%3.3s", "hello", "world");}
int		two_str_prec_width_2fit_2trunc(void){return test("%7.3s%7.3s", "hello", "world");}
int		two_str_prec_width_1fit_a_2trunc(void){return test("%3.3s%7.3s", "hello", "world");}
int		two_str_prec_width_1fit_b_2trunc(void){return test("%7.3s%3.3s", "hello", "world");}
int		two_str_prec_width_0fit_2trunc(void){return test("%3.3s%3.3s", "hello", "world");}
int		two_str_prec_width_2trunc(void){return test("%3s%3s", "hello", "world");}
//String specifiers, other tests
int		two_strings_lj_and_rj(void){return test("%-7s%5s", "hello", "world");}
int		two_strings_rj_and_lj(void){return test("%7s%-5s", "hello", "world");}
int		two_strings_zrjtrunc_and_ljtrunc(void){return test("%04.3s%-7.4s", "hello", "world");}

//Signed integers - no modifers
int		basic_sint_pos(void){return test("this %i number", 17);}
int		basic_sint_neg(void){return test("this %i number", -267);}
int		basic_sint_zero(void){return test("this %i number", 0);}
int		basic_sint_onlypos(void){return test("%i", 3);}
int		basic_sint_onlyneg(void){return test("%i", -1);}
int		basic_sint_onlyzero(void){return test("%i", 0);}
int		basic_sint_pos_d(void){return test("this %d number", 17);}
int		basic_sint_neg_d(void){return test("this %d number", -267);}
int		basic_sint_zero_d(void){return test("this %d number", 0);}
int		sint_intmax(void){return test("%i", 2147483647);}
int		sint_intmin(void){return test("%i", -2147483678);}
//Signed integers with allsign ('+')
int		sint_allsign_pos(void){return test("%+i", 5);}
int		sint_allsign_neg(void){return test("%+i", -7);}
int		sint_intmax_allsign(void){return test("%+i", 2147483647);}
//Signed integers with field width
int		sint_width_pos_fits(void){return test("%7i", 33);}
int		sint_width_neg_fits(void){return test("%7i", -14);}
int		sint_width_zero_fits(void){return test("%3i", 0);}
int		sint_width_pos_exactfit(void){return test("%5i", 52625);}
int		sint_width_neg_exactfit(void){return test("%5i", -2562);}
int		sint_width_pos_nofit(void){return test("%4i", 94827);}
int		sint_width_neg_nofit(void){return test("%4i", -2464);}
int		sint_width_pos_fits_lj(void){return test("%-7i", 33);}
int		sint_width_neg_fits_lj(void){return test("%-7i", -14);}
int		sint_width_zero_fits_lj(void){return test("%-3i", 0);}
int		sint_width_pos_exactfit_lj(void){return test("%-5i", 52625);}
int		sint_width_neg_exactfit_lj(void){return test("%-5i", -2562);}
int		sint_width_pos_nofit_lj(void){return test("%-4i", 94827);}
int		sint_width_neg_nofit_lj(void){return test("%-4i", -2464);}
//signed integers with field width and allsign
int		sint_width_allsign_pos(void){return test("%+5i", 35);}
int		sint_width_allsign_zero(void){return test("%+7i", 0);}
int		sint_width_intmax_allsign(void){return test("%+24i", 2147483647);}
//signed integers with precision
int		sint_prec_fits_pos(void){return test("%.5i", 2);}
int		sint_prec_fits_neg(void){return test("%.6i", -3);}
int		sint_prec_fits_zero(void){return test("%.3i", 0);}
int		sint_prec_exactfit_pos(void){return test("%.4i", 5263);}
int		sint_prec_exactfit_neg(void){return test("%.4i", -2372);}
int		sint_prec_nofit_pos(void){return test("%.3i", 13862);}
int		sint_prec_nofit_neg(void){return test("%.3i",-23646);}
int		sint_prec_allsign_pos(void){return test("%+.7i", 234);}
int		sint_prec_allsign_neg(void){return test("%+.7i", -446);}
int		sint_prec_allsign_pos_nofit(void){return test("%+.3i", 3723);}
//Signed integers with zero field width padding
int		sint_zpad_pos_fits(void){return test("%05i", 43);}
int		sint_zpad_neg_fits(void){return test("%07i", -54);}
int		sint_zpad_zero_fits(void){return test("%03i", 0);}
int		sint_zpad_pos_exactfit(void){return test("%03i", 634);}
int		sint_zpad_neg_exactfit(void){return test("%04i", -532);}
int		sint_zpad_neg_minus1fit(void){return test("%04i", -4825);}
int		sint_zpad_allsign_fits(void){return test("%+05i", 432);}
int		sint_zpad_allsign_zero(void){return test("%+04i", 0);}
//Signed integers with field width and precision
int		sint_prec_width_fit_fit_pos(void){return test("%8.5i", 34);}
int		sint_prec_width_fit_fit_neg(void){return test("%10.5i", -216);}
int		sint_prec_width_fit_fit_zero(void){return test("%8.5i", 0);}
int		sint_prec_width_nofit_fit_pos(void){return test("%8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg(void){return test("%8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos(void){return test("%3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg(void){return test("%3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos(void){return test("%3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg(void){return test("%3.3i", -8462);}
//Signed integers with field width and precision, left-justified
int		sint_prec_width_fit_fit_pos_lj(void){return test("%-8.5i", 34);}
int		sint_prec_width_fit_fit_neg_lj(void){return test("%-10.5i", -216);}
int		sint_prec_width_fit_fit_zero_lj(void){return test("%-8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_lj(void){return test("%-8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_lj(void){return test("%-8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_lj(void){return test("%-3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_lj(void){return test("%-3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_lj(void){return test("%-3.3i", -8462);}
//Signed integers with field width and precision with allsign
int		sint_prec_width_fit_fit_pos_allsign(void){return test("%+8.5i", 34);}
int		sint_prec_width_fit_fit_neg_allsign(void){return test("%+10.5i", -216);}
int		sint_prec_width_fit_fit_zero_allsign(void){return test("%+8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_allsign(void){return test("%+8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_allsign(void){return test("%+8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_allsign(void){return test("%+3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_allsign(void){return test("%+3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_allsign(void){return test("%+3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_allsign(void){return test("%+3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign
int		sint_prec_width_fit_fit_pos_lj_allsign(void){return test("%+-8.5i", 34);}
int		sint_prec_width_fit_fit_neg_lj_allsign(void){return test("%+-10.5i", -216);}
int		sint_prec_width_fit_fit_zero_lj_allsign(void){return test("%+-8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_lj_allsign(void){return test("%+-8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_lj_allsign(void){return test("%+-8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_lj_allsign(void){return test("%+-3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_lj_allsign(void){return test("%+-3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_lj_allsign(void){return test("%+-3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_lj_allsign(void){return test("%+-3.3i", -8462);}
//Signed integers with field width and precision with zeropadding
int		sint_prec_width_ff_pos_zpad(void){return test("%08.5i", 34);}
int		sint_prec_width_ff_neg_zpad(void){return test("%010.5i", -216);}
int		sint_prec_width_ff_zero_zpad(void){return test("%08.5i", 0);}
int		sint_prec_width_nf_pos_zpad(void){return test("%08.3i", 8375);}
int		sint_prec_width_nf_neg_zpad(void){return test("%08.3i", -8473);}
int		sint_prec_width_fn_pos_zpad(void){return test("%03.7i", 3267);}
int		sint_prec_width_fn_neg_zpad(void){return test("%03.7i", -2375);}
int		sint_prec_width_nn_pos_zpad(void){return test("%03.3i", 6983);}
int		sint_prec_width_nn_neg_zpad(void){return test("%03.3i", -8462);}
//Signed integers with field width and precision, left-justified with zeropadding
int		sint_prec_width_ff_pos_lj_zpad(void){return test("%0-8.5i", 34);}
int		sint_prec_width_ff_neg_lj_zpad(void){return test("%0-10.5i", -216);}
int		sint_prec_width_ff_zero_lj_zpad(void){return test("%0-8.5i", 0);}
int		sint_prec_width_nf_pos_lj_zpad(void){return test("%0-8.3i", 8375);}
int		sint_prec_width_nf_neg_lj_zpad(void){return test("%0-8.3i", -8473);}
int		sint_prec_width_fn_pos_lj_zpad(void){return test("%0-3.7i", 3267);}
int		sint_prec_width_fn_neg_lj_zpad(void){return test("%0-3.7i", -2375);}
int		sint_prec_width_nn_pos_lj_zpad(void){return test("%0-3.3i", 6983);}
int		sint_prec_width_nn_neg_lj_zpad(void){return test("%0-3.3i", -8462);}
//Signed integers with field width and precision with allsign with zeropadding
int		sint_prec_width_ff_pos_allsign_zpad(void){return test("%0+8.5i", 34);}
int		sint_prec_width_ff_neg_allsign_zpad(void){return test("%0+10.5i", -216);}
int		sint_prec_width_ff_zero_allsign_zpad(void){return test("%0+8.5i", 0);}
int		sint_prec_width_nf_pos_allsign_zpad(void){return test("%0+8.3i", 8375);}
int		sint_prec_width_nf_neg_allsign_zpad(void){return test("%0+8.3i", -8473);}
int		sint_prec_width_fn_pos_allsign_zpad(void){return test("%0+3.7i", 3267);}
int		sint_prec_width_fn_neg_allsign_zpad(void){return test("%0+3.7i", -2375);}
int		sint_prec_width_nn_pos_allsign_zpad(void){return test("%0+3.3i", 6983);}
int		sint_prec_width_nn_neg_allsign_zpad(void){return test("%0+3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign with zeropadding
int		sint_prec_width_ff_pos_lj_allsign_zpad(void){return test("%0+-8.5i", 34);}
int		sint_prec_width_ff_neg_lj_allsign_zpad(void){return test("%0+-10.5i", -216);}
int		sint_prec_width_ff_zero_lj_allsign_zpad(void){return test("%0+-8.5i", 0);}
int		sint_prec_width_nf_pos_lj_allsign_zpad(void){return test("%0+-8.3i", 8375);}
int		sint_prec_width_nf_neg_lj_allsign_zpad(void){return test("%0+-8.3i", -8473);}
int		sint_prec_width_fn_pos_lj_allsign_zpad(void){return test("%0+-3.7i", 3267);}
int		sint_prec_width_fn_neg_lj_allsign_zpad(void){return test("%0+-3.7i", -2375);}
int		sint_prec_width_nn_pos_lj_allsign_zpad(void){return test("%0+-3.3i", 6983);}
int		sint_prec_width_nn_neg_lj_allsign_zpad(void){return test("%0+-3.3i", -8462);}
//Signed integers of varying size modifiers
char 		ch_pos_1 = 100, ch_neg_1 = -87;
short		sh_pos_1 = 3047, sh_neg_1 = -8875;
int			i_pos_1 = 878023, i_neg_1 = -992744;
long		l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
long		lmax	= 9223372036854775807;
long		lmin	= -9223372036854775807;
long long llmax = 9223372036854775807;
long		llmin = -9223372036854775807;
int		sint_size_hh_pos_casted(void){return test("%hhi", (char)45);}
int		sint_size_hh_neg_casted(void){return test("%hhi", (char)-45);}
int		sint_size_h_pos_casted(void){return test("%hi", (short)385);}
int		sint_size_h_neg_casted(void){return test("%hi", (short)-385);}
int		sint_size_l_pos_casted(void){return test("%li", (long)32);}
int		sint_size_l_neg_casted(void){return test("%li", (long)-32);}
int		sint_size_ll_pos_casted(void){return test("%lli", (long long)43);}
int		sint_size_ll_neg_casted(void){return test("%lli", (long long)-43);}
int		sint_size_hh_pos_ref(void){return test("%hhi", ch_pos_1);}
int		sint_size_hh_neg_ref(void){return test("%hhi", ch_neg_1);}
int		sint_size_h_pos_ref(void){return test("%hi", sh_pos_1);}
int		sint_size_h_neg_ref(void){return test("%hi", sh_neg_1);}
int		sint_size_l_pos_ref(void){return test("%li", l_pos_1);}
int		sint_size_l_neg_ref(void){return test("%li", l_neg_1);}
int		sint_size_ll_pos_ref(void){return test("%lli", ll_pos_1);}
int		sint_size_ll_neg_ref(void){return test("%lli", ll_neg_1);}
int		sint_size_l_pos_big(void){return test("%li", 22337203685477);}
int		sint_size_l_neg_big(void){return test("%li", -22337203685477);}
int		sint_size_ll_pos_big(void){return test("%lli", 522337203685470);}
int		sint_size_ll_neg_big(void){return test("%lli", -522337203685470);}
int		sint_llmax(void){return test("%lli", 9223372036854775807);}
int		sint_llmin(void){return test("%lli", llmin);}
int		sint_lmax(void){return test("%li", 9223372036854775807);}
int		sint_lmin(void){return test("%li", lmin);}
int		sint_hmax(void){return test("%hi", 32767);}
int		sint_hmin(void){return test("%hi", -32768);}
int		sint_hhmax(void){return test("%hhi", 127);}
int		sint_hhmin(void){return test("%hhi", -128);}

//Signed integers of varying size modifiers with some other modifiers
int		sint_size_l_pos_big_zpad(void){return test("%037li", 22337203685477);}
int		sint_size_l_neg_big_prec(void){return test("%.37li", -22337203685477);}
int		sint_size_ll_pos_big_width(void){return test("%37lli", 522337203685470);}
int		sint_size_ll_neg_big_lj(void){return test("%-37lli", -522337203685470);}
int		sint_size_l_pos_big_allsign(void){return test("%+li", 22337203685477);}
//Multiple signed integers in a row of varying sizes
int		sint_size_follows_i_i(void){return test("[%i] [%i]", i_pos_1, i_pos_1);}
int		sint_size_follows_i_l(void){return test("[%i] [%li]", i_pos_1, l_pos_1);}
int		sint_size_follows_i_ll(void){return test("[%i] [%lli]", i_pos_1, ll_pos_1);}
int		sint_size_follows_i_h(void){return test("[%i] [%hi]", i_pos_1, sh_pos_1);}
int		sint_size_follows_i_hh(void){return test("[%i] [%hhi]", i_pos_1, ch_pos_1);}
int		sint_size_ll_hh_ll(void){return test("%lli%hhi%lli", ll_pos_1, ch_neg_1, ll_neg_1);}
int		sint_size_h_l_hh(void){return test("%hi%li%hhi", sh_pos_1, l_neg_1, ch_neg_1);}
int		sint_size_l_hh_h(void){return test("%li%hhi%hi", l_neg_1, ch_pos_1, sh_pos_1);}
int		sint_size_n_ll_hh(void){return test("%i%lli%hhi", i_pos_1, ll_neg_1, ch_pos_1);}
int		sint_size_ll_n_l(void){return test("%lli%i%li", ll_neg_1, i_pos_1, l_pos_1);}
//Signed integers - space - no modifers
int		basic_sint_pos_sp(void){return test("this % i number", 17);}
int		basic_sint_neg_sp(void){return test("this % i number", -267);}
int		basic_sint_zero_sp(void){return test("this % i number", 0);}
int		basic_sint_onlypos_sp(void){return test("% i", 3);}
int		basic_sint_onlyneg_sp(void){return test("% i", -1);}
int		basic_sint_onlyzero_sp(void){return test("% i", 0);}
int		basic_sint_pos_d_sp(void){return test("this % d number", 17);}
int		basic_sint_neg_d_sp(void){return test("this % d number", -267);}
int		basic_sint_zero_d_sp(void){return test("this % d number", 0);}
int		sint_intmax_sp(void){return test("% i", 2147483647);}
int		sint_intmin_sp(void){return test("% i", -2147483678);}
//Signed integers - space with allsign ('+')
int		sint_allsign_pos_sp(void){return test("% +i", 5);}
int		sint_allsign_neg_sp(void){return test("% +i", -7);}
int		sint_intmax_allsign_sp(void){return test("% +i", 2147483647);}
//Signed integers - space with field width
int		sint_width_pos_fits_sp(void){return test("% 7i", 33);}
int		sint_width_neg_fits_sp(void){return test("% 7i", -14);}
int		sint_width_zero_fits_sp(void){return test("% 3i", 0);}
int		sint_width_pos_exactfit_sp(void){return test("% 5i", 52625);}
int		sint_width_neg_exactfit_sp(void){return test("% 5i", -2562);}
int		sint_width_pos_nofit_sp(void){return test("% 4i", 94827);}
int		sint_width_neg_nofit_sp(void){return test("% 4i", -2464);}
int		sint_width_pos_fits_lj_sp(void){return test("% -7i", 33);}
int		sint_width_neg_fits_lj_sp(void){return test("% -7i", -14);}
int		sint_width_zero_fits_lj_sp(void){return test("% -3i", 0);}
int		sint_width_pos_exactfit_lj_sp(void){return test("% -5i", 52625);}
int		sint_width_neg_exactfit_lj_sp(void){return test("% -5i", -2562);}
int		sint_width_pos_nofit_lj_sp(void){return test("% -4i", 94827);}
int		sint_width_neg_nofit_lj_sp(void){return test("% -4i", -2464);}
//signed integers with field width and allsign
int		sint_width_allsign_pos_sp(void){return test("% +5i", 35);}
int		sint_width_allsign_zero_sp(void){return test("% +7i", 0);}
int		sint_width_intmax_allsign_sp(void){return test("% +24i", 2147483647);}
//signed integers with precision
int		sint_prec_fits_pos_sp(void){return test("% .5i", 2);}
int		sint_prec_fits_neg_sp(void){return test("% .6i", -3);}
int		sint_prec_fits_zero_sp(void){return test("% .3i", 0);}
int		sint_prec_exactfit_pos_sp(void){return test("% .4i", 5263);}
int		sint_prec_exactfit_neg_sp(void){return test("% .4i", -2372);}
int		sint_prec_nofit_pos_sp(void){return test("% .3i", 13862);}
int		sint_prec_nofit_neg_sp(void){return test("% .3i",-23646);}
int		sint_prec_allsign_pos_sp(void){return test("% +.7i", 234);}
int		sint_prec_allsign_neg_sp(void){return test("% +.7i", -446);}
int		sint_prec_allsign_pos_nofit_sp(void){return test("% +.3i", 3723);}
//Signed integers - space with zero field width padding
int		sint_zpad_pos_fits_sp(void){return test("% 05i", 43);}
int		sint_zpad_neg_fits_sp(void){return test("% 07i", -54);}
int		sint_zpad_zero_fits_sp(void){return test("% 03i", 0);}
int		sint_zpad_pos_exactfit_sp(void){return test("% 03i", 634);}
int		sint_zpad_neg_exactfit_sp(void){return test("% 04i", -532);}
int		sint_zpad_neg_minus1fit_sp(void){return test("% 04i", -4825);}
int		sint_zpad_allsign_fits_sp(void){return test("% +05i", 432);}
int		sint_zpad_allsign_zero_sp(void){return test("% +04i", 0);}
//Signed integers - space with field width and precision
int		sint_prec_width_fit_fit_pos_sp(void){return test("% 8.5i", 34);}
int		sint_prec_width_fit_fit_neg_sp(void){return test("% 10.5i", -216);}
int		sint_prec_width_fit_fit_zero_sp(void){return test("% 8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_sp(void){return test("% 8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_sp(void){return test("% 8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_sp(void){return test("% 3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_sp(void){return test("% 3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_sp(void){return test("% 3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_sp(void){return test("% 3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified
int		sint_prec_width_fit_fit_pos_lj_sp(void){return test("% -8.5i", 34);}
int		sint_prec_width_fit_fit_neg_lj_sp(void){return test("% -10.5i", -216);}
int		sint_prec_width_fit_fit_zero_lj_sp(void){return test("% -8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_lj_sp(void){return test("% -8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_lj_sp(void){return test("% -8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_lj_sp(void){return test("% -3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_lj_sp(void){return test("% -3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_lj_sp(void){return test("% -3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_lj_sp(void){return test("% -3.3i", -8462);}
//Signed integers - space with field width and precision with allsign
int		sint_prec_width_fit_fit_pos_allsign_sp(void){return test("% +8.5i", 34);}
int		sint_prec_width_fit_fit_neg_allsign_sp(void){return test("% +10.5i", -216);}
int		sint_prec_width_fit_fit_zero_allsign_sp(void){return test("% +8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_allsign_sp(void){return test("% +8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_allsign_sp(void){return test("% +8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_allsign_sp(void){return test("% +3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_allsign_sp(void){return test("% +3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_allsign_sp(void){return test("% +3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_allsign_sp(void){return test("% +3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign
int		sint_prec_width_fit_fit_pos_lj_allsign_sp(void){return test("% +-8.5i", 34);}
int		sint_prec_width_fit_fit_neg_lj_allsign_sp(void){return test("% +-10.5i", -216);}
int		sint_prec_width_fit_fit_zero_lj_allsign_sp(void){return test("% +-8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_lj_allsign_sp(void){return test("% +-8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_lj_allsign_sp(void){return test("% +-8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_lj_allsign_sp(void){return test("% +-3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_lj_allsign_sp(void){return test("% +-3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_lj_allsign_sp(void){return test("% +-3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_lj_allsign_sp(void){return test("% +-3.3i", -8462);}
//Signed integers - space with field width and precision with zeropadding
int		sint_prec_width_ff_pos_zpad_sp(void){return test("% 08.5i", 34);}
int		sint_prec_width_ff_neg_zpad_sp(void){return test("% 010.5i", -216);}
int		sint_prec_width_ff_zero_zpad_sp(void){return test("% 08.5i", 0);}
int		sint_prec_width_nf_pos_zpad_sp(void){return test("% 08.3i", 8375);}
int		sint_prec_width_nf_neg_zpad_sp(void){return test("% 08.3i", -8473);}
int		sint_prec_width_fn_pos_zpad_sp(void){return test("% 03.7i", 3267);}
int		sint_prec_width_fn_neg_zpad_sp(void){return test("% 03.7i", -2375);}
int		sint_prec_width_nn_pos_zpad_sp(void){return test("% 03.3i", 6983);}
int		sint_prec_width_nn_neg_zpad_sp(void){return test("% 03.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with zeropadding
int		sint_prec_width_ff_pos_lj_zpad_sp(void){return test("% 0-8.5i", 34);}
int		sint_prec_width_ff_neg_lj_zpad_sp(void){return test("% 0-10.5i", -216);}
int		sint_prec_width_ff_zero_lj_zpad_sp(void){return test("% 0-8.5i", 0);}
int		sint_prec_width_nf_pos_lj_zpad_sp(void){return test("% 0-8.3i", 8375);}
int		sint_prec_width_nf_neg_lj_zpad_sp(void){return test("% 0-8.3i", -8473);}
int		sint_prec_width_fn_pos_lj_zpad_sp(void){return test("% 0-3.7i", 3267);}
int		sint_prec_width_fn_neg_lj_zpad_sp(void){return test("% 0-3.7i", -2375);}
int		sint_prec_width_nn_pos_lj_zpad_sp(void){return test("% 0-3.3i", 6983);}
int		sint_prec_width_nn_neg_lj_zpad_sp(void){return test("% 0-3.3i", -8462);}
//Signed integers - space with field width and precision with allsign with zeropadding
int		sint_prec_width_ff_pos_allsign_zpad_sp(void){return test("% 0+8.5i", 34);}
int		sint_prec_width_ff_neg_allsign_zpad_sp(void){return test("% 0+10.5i", -216);}
int		sint_prec_width_ff_zero_allsign_zpad_sp(void){return test("% 0+8.5i", 0);}
int		sint_prec_width_nf_pos_allsign_zpad_sp(void){return test("% 0+8.3i", 8375);}
int		sint_prec_width_nf_neg_allsign_zpad_sp(void){return test("% 0+8.3i", -8473);}
int		sint_prec_width_fn_pos_allsign_zpad_sp(void){return test("% 0+3.7i", 3267);}
int		sint_prec_width_fn_neg_allsign_zpad_sp(void){return test("% 0+3.7i", -2375);}
int		sint_prec_width_nn_pos_allsign_zpad_sp(void){return test("% 0+3.3i", 6983);}
int		sint_prec_width_nn_neg_allsign_zpad_sp(void){return test("% 0+3.3i", -8462);}
//Signed integers - space with field width and precision, left-justified with allsign with zeropadding
int		sint_prec_width_ff_pos_lj_allsign_zpad_sp(void){return test("% 0+-8.5i", 34);}
int		sint_prec_width_ff_neg_lj_allsign_zpad_sp(void){return test("% 0+-10.5i", -216);}
int		sint_prec_width_ff_zero_lj_allsign_zpad_sp(void){return test("% 0+-8.5i", 0);}
int		sint_prec_width_nf_pos_lj_allsign_zpad_sp(void){return test("% 0+-8.3i", 8375);}
int		sint_prec_width_nf_neg_lj_allsign_zpad_sp(void){return test("% 0+-8.3i", -8473);}
int		sint_prec_width_fn_pos_lj_allsign_zpad_sp(void){return test("% 0+-3.7i", 3267);}
int		sint_prec_width_fn_neg_lj_allsign_zpad_sp(void){return test("% 0+-3.7i", -2375);}
int		sint_prec_width_nn_pos_lj_allsign_zpad_sp(void){return test("% 0+-3.3i", 6983);}
int		sint_prec_width_nn_neg_lj_allsign_zpad_sp(void){return test("% 0+-3.3i", -8462);}
//Signed integers - space of varying size modifiers
int		sint_size_hh_pos_casted_sp(void){return test("% hhi", (char)45);}
int		sint_size_hh_neg_casted_sp(void){return test("% hhi", (char)-45);}
int		sint_size_h_pos_casted_sp(void){return test("% hi", (short)385);}
int		sint_size_h_neg_casted_sp(void){return test("% hi", (short)-385);}
int		sint_size_l_pos_casted_sp(void){return test("% li", (long)32);}
int		sint_size_l_neg_casted_sp(void){return test("% li", (long)-32);}
int		sint_size_ll_pos_casted_sp(void){return test("% lli", (long long)43);}
int		sint_size_ll_neg_casted_sp(void){return test("% lli", (long long)-43);}
int		sint_size_hh_pos_ref_sp(void){return test("% hhi", ch_pos_1);}
int		sint_size_hh_neg_ref_sp(void){return test("% hhi", ch_neg_1);}
int		sint_size_h_pos_ref_sp(void){return test("% hi", sh_pos_1);}
int		sint_size_h_neg_ref_sp(void){return test("% hi", sh_neg_1);}
int		sint_size_l_pos_ref_sp(void){return test("% li", l_pos_1);}
int		sint_size_l_neg_ref_sp(void){return test("% li", l_neg_1);}
int		sint_size_ll_pos_ref_sp(void){return test("% lli", ll_pos_1);}
int		sint_size_ll_neg_ref_sp(void){return test("% lli", ll_neg_1);}
int		sint_size_l_pos_big_sp(void){return test("% li", 22337203685477);}
int		sint_size_l_neg_big_sp(void){return test("% li", -22337203685477);}
int		sint_size_ll_pos_big_sp(void){return test("% lli", 522337203685470);}
int		sint_size_ll_neg_big_sp(void){return test("% lli", -522337203685470);}
int		sint_llmax_sp(void){return test("% lli", 9223372036854775807);}
int		sint_llmin_sp(void){return test("% lli", llmin);}
int		sint_lmax_sp(void){return test("% li", 9223372036854775807);}
int		sint_lmin_sp(void){return test("% li", lmin);}
int		sint_hmax_sp(void){return test("% hi", 32767);}
int		sint_hmin_sp(void){return test("% hi", -32768);}
int		sint_hhmax_sp(void){return test("% hhi", 127);}
int		sint_hhmin_sp(void){return test("% hhi", -128);}

//Switching between string and signed integers of various sizes
char	str_1[] = "hello world", str_2[] = "panda", str_3[] = "this is a longer string";
char	str_empty[] = "";
int		hhi_str_lli_str(void){return test("%hhi%s%lli%s", ch_pos_1, str_3, ll_neg_1, str_2);}
int		str_hi_str_li(void){return test("%s%hi%s%li", str_1, sh_neg_1, str_3, l_neg_1);}

//Unsigned integers - no modifers
int		basic_uint_pos(void){return test("this %u number", 17);}
int		basic_uint_zero(void){return test("this %u number", 0);}
int		basic_uint_onlypos(void){return test("%u", 3);}
int		uint_uintmax(void){return test("%u", 4294967295);}
//Unsigned integers with allsign ('+')
int		uint_allsign_pos(void){return test("%+u", 5);}
int		uint_allsign_zero(void){return test("%+u", 5);}
int		uint_uintmax_allsign(void){return test("%+u", 4294967295);}
//Unsigned integers with field width
int		uint_width_pos_fits(void){return test("%7u", 33);}
int		uint_width_zero_fits(void){return test("%3u", 0);}
int		uint_width_pos_exactfit(void){return test("%5u", 52625);}
int		uint_width_pos_nofit(void){return test("%4u", 94827);}
int		uint_width_pos_fits_lj(void){return test("%-7u", 33);}
int		uint_width_zero_fits_lj(void){return test("%-3u", 0);}
int		uint_width_pos_exactfit_lj(void){return test("%-5u", 52625);}
int		uint_width_pos_nofit_lj(void){return test("%-4u", 94827);}
//unsigned integers with field width and allsign
int		uint_width_allsign_pos(void){return test("%+5u", 35);}
int		uint_width_allsign_zero(void){return test("%+7u", 0);}
int		uint_width_uintmax_allsign(void){return test("%+24u", 4294967295);}
//unsigned integers with precision
int		uint_prec_fits_pos(void){return test("%.5u", 2);}
int		uint_prec_fits_zero(void){return test("%.3u", 0);}
int		uint_prec_exactfit_pos(void){return test("%.4u", 5263);}
int		uint_prec_nofit_pos(void){return test("%.3u", 13862);}
int		uint_prec_allsign_pos(void){return test("%+.7u", 234);}
int		uint_prec_allsign_pos_nofit(void){return test("%+.3u", 3723);}
//Unsigned integers with zero field width padding
int		uint_zpad_pos_fits(void){return test("%05u", 43);}
int		uint_zpad_zero_fits(void){return test("%03u", 0);}
int		uint_zpad_pos_exactfit(void){return test("%03u", 634);}
int		uint_zpad_allsign_fits(void){return test("%+05u", 432);}
int		uint_zpad_allsign_zero(void){return test("%+04u", 0);}
//Unsigned integers with field width and precision
int		uint_prec_width_fit_fit_pos(void){return test("%8.5u", 34);}
int		uint_prec_width_fit_fit_zero(void){return test("%8.5u", 0);}
int		uint_prec_width_nofit_fit_pos(void){return test("%8.3u", 8375);}
int		uint_prec_width_fit_nofit_pos(void){return test("%3.7u", 3267);}
int		uint_prec_width_nofit_nofit_pos(void){return test("%3.3u", 6983);}
//Unsigned integers with field width and precision, left-justified
int		uint_prec_width_fit_fit_pos_lj(void){return test("%-8.5u", 34);}
int		uint_prec_width_fit_fit_zero_lj(void){return test("%-8.5u", 0);}
int		uint_prec_width_nofit_fit_pos_lj(void){return test("%-8.3u", 8375);}
int		uint_prec_width_fit_nofit_pos_lj(void){return test("%-3.7u", 3267);}
int		uint_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3u", 6983);}
//Unsigned integers with field width and precision with allsign
int		uint_prec_width_fit_fit_pos_allsign(void){return test("%+8.5u", 34);}
int		uint_prec_width_fit_fit_zero_allsign(void){return test("%+8.5u", 0);}
int		uint_prec_width_nofit_fit_pos_allsign(void){return test("%+8.3u", 8375);}
int		uint_prec_width_fit_nofit_pos_allsign(void){return test("%+3.7u", 3267);}
int		uint_prec_width_nofit_nofit_pos_allsign(void){return test("%+3.3u", 6983);}
//Unsigned integers with field width and precision, left-justified with allsign
int		uint_prec_width_fit_fit_pos_lj_allsign(void){return test("%+-8.5u", 34);}
int		uint_prec_width_fit_fit_zero_lj_allsign(void){return test("%+-8.5u", 0);}
int		uint_prec_width_nofit_fit_pos_lj_allsign(void){return test("%+-8.3u", 8375);}
int		uint_prec_width_fit_nofit_pos_lj_allsign(void){return test("%+-3.7u", 3267);}
int		uint_prec_width_nofit_nofit_pos_lj_allsign(void){return test("%+-3.3u", 6983);}
//Unsigned integers with field width and precision with zeropadding
int		uint_prec_width_ff_pos_zpad(void){return test("%08.5u", 34);}
int		uint_prec_width_ff_zero_zpad(void){return test("%08.5u", 0);}
int		uint_prec_width_nf_pos_zpad(void){return test("%08.3u", 8375);}
int		uint_prec_width_fn_pos_zpad(void){return test("%03.7u", 3267);}
int		uint_prec_width_nn_pos_zpad(void){return test("%03.3u", 6983);}
//Unsigned integers with field width and precision, left-justified with zeropadding
int		uint_prec_width_ff_pos_lj_zpad(void){return test("%0-8.5u", 34);}
int		uint_prec_width_ff_zero_lj_zpad(void){return test("%0-8.5u", 0);}
int		uint_prec_width_nf_pos_lj_zpad(void){return test("%0-8.3u", 8375);}
int		uint_prec_width_fn_pos_lj_zpad(void){return test("%0-3.7u", 3267);}
int		uint_prec_width_nn_pos_lj_zpad(void){return test("%0-3.3u", 6983);}
//Unsigned integers with field width and precision with allsign with zeropadding
int		uint_prec_width_ff_pos_allsign_zpad(void){return test("%0+8.5u", 34);}
int		uint_prec_width_ff_zero_allsign_zpad(void){return test("%0+8.5u", 0);}
int		uint_prec_width_nf_pos_allsign_zpad(void){return test("%0+8.3u", 8375);}
int		uint_prec_width_fn_pos_allsign_zpad(void){return test("%0+3.7u", 3267);}
int		uint_prec_width_nn_pos_allsign_zpad(void){return test("%0+3.3u", 6983);}
//Unsigned integers with field width and precision, left-justified with allsign with zeropadding
int		uint_prec_width_ff_pos_lj_allsign_zpad(void){return test("%0+-8.5u", 34);}
int		uint_prec_width_ff_zero_lj_allsign_zpad(void){return test("%0+-8.5u", 0);}
int		uint_prec_width_nf_pos_lj_allsign_zpad(void){return test("%0+-8.3u", 8375);}
int		uint_prec_width_fn_pos_lj_allsign_zpad(void){return test("%0+-3.7u", 3267);}
int		uint_prec_width_nn_pos_lj_allsign_zpad(void){return test("%0+-3.3u", 6983);}
//Unsigned integers of varying size modifiers
unsigned char 		uch_pos_1 = 100;
unsigned short		ush_pos_1 = 3047;
unsigned int		ui_pos_1 = 878023;
unsigned long		ul_pos_1 = 22337203685477;
unsigned long long	ull_pos_1 = 22337203685477;
unsigned long long  ullmax = 9223372036854775807;
unsigned long  		ulmax = 9223372036854775807;
int		uint_size_hh_pos_casted(void){return test("%hhu", (unsigned char)45);}
int		uint_size_h_pos_casted(void){return test("%hu", (unsigned short)385);}
int		uint_size_l_pos_casted(void){return test("%lu", (unsigned long)32);}
int		uint_size_ll_pos_casted(void){return test("%llu", (long long)43);}
int		uint_size_hh_pos_ref(void){return test("%hhu", uch_pos_1);}
int		uint_size_h_pos_ref(void){return test("%hu", ush_pos_1);}
int		uint_size_l_pos_ref(void){return test("%lu", ul_pos_1);}
int		uint_size_ll_pos_ref(void){return test("%llu", ull_pos_1);}
int		uint_size_l_pos_big(void){return test("%lu", 22337203685477);}
int		uint_size_ll_pos_big(void){return test("%llu", 522337203685470);}
int		uint_ullmax(void){return test("%llu", ullmax);}
int		uint_ulmax(void){return test("%lu", ulmax);}
int		uint_uhmax(void){return test("%hu", 65535);}
int		uint_uhhmax(void){return test("%hhu", 255);}
//Unsigned integers of varying size modifiers with some other modifiers
int		uint_size_l_pos_big_zpad(void){return test("%037lu", 22337203685477);}
int		uint_size_ll_pos_big_width(void){return test("%37llu", 522337203685470);}
int		uint_size_l_pos_big_allsign(void){return test("%+lu", 22337203685477);}
//Multiple unsigned integers in a row of varying sizes
int		uint_size_ll_hh_ll(void){return test("%llu%hhu%llu", ull_pos_1, uch_pos_1, ull_pos_1);}
int		uint_size_h_l_hh(void){return test("%hu%lu%hhu", ush_pos_1, ul_pos_1, uch_pos_1);}
int		uint_size_l_hh_h(void){return test("%lu%hhu%hu", ul_pos_1, uch_pos_1, ush_pos_1);}
int		uint_size_n_ll_hh(void){return test("%u%llu%hhu", ui_pos_1, ull_pos_1, uch_pos_1);}
int		uint_size_ll_n_l(void){return test("%llu%u%lu", ull_pos_1, ui_pos_1, ul_pos_1);}

//Switching between string and unsigned integers of various sizes
int		hhu_str_llu_str(void){return test("%hhu%s%llu%s", uch_pos_1, str_3, ull_pos_1, str_2);}
int		str_hu_str_lu(void){return test("%s%hu%s%lu", str_1, ush_pos_1, str_3, ul_pos_1);}

//Mixing everything from all the tests so far
int		mixed_test_0001(void){return test(
		"%s%hihello%-17.14llu%lli%+08hu%s%017ssomestuff%s%hi%i%.24lu%llu%u%.2s%li","abc",sh_neg_1,
		ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",32767,0,ul_pos_1,0,ui_pos_1,"notall",l_pos_1);}

//Hexadecimal lowers - no modifers
int		basic_hexl_pos(void){return test("this %x number", 17);}
int		basic_hexl_zero(void){return test("this %x number", 0);}
int		basic_hexl_onlypos(void){return test("%x", 3);}
int		hexl_hexlmax(void){return test("%x", 4294967295);}
//Hexadecimal lowers with field width
int		hexl_width_pos_fits(void){return test("%7x", 33);}
int		hexl_width_zero_fits(void){return test("%3x", 0);}
int		hexl_width_pos_exactfit(void){return test("%5x", 52625);}
int		hexl_width_pos_nofit(void){return test("%2x", 94827);}
int		hexl_width_pos_fits_lj(void){return test("%-7x", 33);}
int		hexl_width_zero_fits_lj(void){return test("%-3x", 0);}
int		hexl_width_pos_exactfit_lj(void){return test("%-5x", 52625);}
int		hexl_width_pos_nofit_lj(void){return test("%-4x", 9648627);}
//Hexadecimal lowers with precision
int		hexl_prec_fits_pos(void){return test("%.5x", 21);}
int		hexl_prec_fits_zero(void){return test("%.3x", 0);}
int		hexl_prec_exactfit_pos(void){return test("%.4x", 5263);}
int		hexl_prec_nofit_pos(void){return test("%.3x", 938862);}
//Hexadecimal lowers with zero field width padding
int		hexl_zpad_pos_fits(void){return test("%05x", 43);}
int		hexl_zpad_zero_fits(void){return test("%03x", 0);}
int		hexl_zpad_pos_exactfit(void){return test("%03x", 698334);}
//Hexadecimal lowers with field width and precision
int		hexl_prec_width_fit_fit_pos(void){return test("%8.5x", 34);}
int		hexl_prec_width_fit_fit_zero(void){return test("%8.5x", 0);}
int		hexl_prec_width_nofit_fit_pos(void){return test("%8.3x", 8375);}
int		hexl_prec_width_fit_nofit_pos(void){return test("%2.7x", 3267);}
int		hexl_prec_width_nofit_nofit_pos(void){return test("%3.3x", 6983);}
//Hexadecimal lowers with field width and precision, left-justified
int		hexl_prec_width_fit_fit_pos_lj(void){return test("%-8.5x", 34);}
int		hexl_prec_width_fit_fit_zero_lj(void){return test("%-8.5x", 0);}
int		hexl_prec_width_nofit_fit_pos_lj(void){return test("%-8.3x", 8375);}
int		hexl_prec_width_fit_nofit_pos_lj(void){return test("%-2.7x", 3267);}
int		hexl_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3x", 6983);}
//Hexadecimal lowers with field width and precision with zeropadding
int		hexl_prec_width_ff_pos_zpad(void){return test("%08.5x", 34);}
int		hexl_prec_width_ff_zero_zpad(void){return test("%08.5x", 0);}
int		hexl_prec_width_nf_pos_zpad(void){return test("%08.3x", 8375);}
int		hexl_prec_width_fn_pos_zpad(void){return test("%02.7x", 3267);}
int		hexl_prec_width_nn_pos_zpad(void){return test("%03.3x", 6983);}
//Hexadecimal lowers with field width and precision, left-justified with zeropadding
int		hexl_prec_width_ff_pos_lj_zpad(void){return test("%0-8.5x", 34);}
int		hexl_prec_width_ff_zero_lj_zpad(void){return test("%0-8.5x", 0);}
int		hexl_prec_width_nf_pos_lj_zpad(void){return test("%0-8.3x", 8375);}
int		hexl_prec_width_fn_pos_lj_zpad(void){return test("%0-2.7x", 3267);}
int		hexl_prec_width_nn_pos_lj_zpad(void){return test("%0-3.3x", 6983);}
//Hexadecimal lowers of varying size modifiers
int		hexl_size_hh_pos_casted(void){return test("%hhx", (unsigned char)45);}
int		hexl_size_h_pos_casted(void){return test("%hx", (unsigned short)385);}
int		hexl_size_l_pos_casted(void){return test("%lx", (unsigned long)32);}
int		hexl_size_ll_pos_casted(void){return test("%llx", (long long)43);}
int		hexl_size_hh_pos_ref(void){return test("%hhx", uch_pos_1);}
int		hexl_size_h_pos_ref(void){return test("%hx", ush_pos_1);}
int		hexl_size_l_pos_ref(void){return test("%lx", ul_pos_1);}
int		hexl_size_ll_pos_ref(void){return test("%llx", ull_pos_1);}
int		hexl_size_l_pos_big(void){return test("%lx", 22337203685477);}
int		hexl_size_ll_pos_big(void){return test("%llx", 522337203685470);}
int		hexl_ullmax(void){return test("%llx", ullmax);}
int		hexl_ulmax(void){return test("%lx", ulmax);}
int		hexl_uhmax(void){return test("%hx", 65535);}
int		hexl_uhhmax(void){return test("%hhx", 255);}
//Hexadecimal lowers of varying size modifiers with some other modifiers
int		hexl_size_l_pos_big_zpad(void){return test("%037lx", 22337203685477);}
int		hexl_size_ll_pos_big_width(void){return test("%37llx", 522337203685470);}
//Multiple Hexadecimal lowers in a row of varying sizes
int		hexl_size_ll_hh_ll(void){return test("%llu%hhu%llx", ull_pos_1, uch_pos_1, ull_pos_1);}
int		hexl_size_h_l_hh(void){return test("%hu%lu%hhx", ush_pos_1, ul_pos_1, uch_pos_1);}
int		hexl_size_l_hh_h(void){return test("%lu%hhu%hx", ul_pos_1, uch_pos_1, ush_pos_1);}
int		hexl_size_n_ll_hh(void){return test("%u%llu%hhx", ui_pos_1, ull_pos_1, uch_pos_1);}
int		hexl_size_ll_n_l(void){return test("%llu%u%lx", ull_pos_1, ui_pos_1, ul_pos_1);}
//Hexadecimal lower (altform) - no modifers
int		basic_hexl_pos_af(void){return test("this %#x number", 17);}
int		basic_hexl_zero_af(void){return test("this %#x number", 0);}
int		basic_hexl_onlypos_af(void){return test("%#x", 3);}
int		hexl_hexlmax_af(void){return test("%#x", 4294967295);}
//Hexadecimal lower (altform) with field width
int		hexl_width_pos_fits_af(void){return test("%#7x", 33);}
int		hexl_width_zero_fits_af(void){return test("%#3x", 0);}
int		hexl_width_pos_exactfit_af(void){return test("%#5x", 52625);}
int		hexl_width_pos_nofit_af(void){return test("%#2x", 94827);}
int		hexl_width_pos_fits_lj_af(void){return test("%#-7x", 33);}
int		hexl_width_zero_fits_lj_af(void){return test("%#-3x", 0);}
int		hexl_width_pos_exactfit_lj_af(void){return test("%#-5x", 52625);}
int		hexl_width_pos_nofit_lj_af(void){return test("%#-4x", 9648627);}
//Hexadecimal lower (altform) with precision
int		hexl_prec_fits_pos_af(void){return test("%#.5x", 21);}
int		hexl_prec_fits_zero_af(void){return test("%#.3x", 0);}
int		hexl_prec_exactfit_pos_af(void){return test("%#.4x", 5263);}
int		hexl_prec_nofit_pos_af(void){return test("%#.3x", 938862);}
//Hexadecimal lower (altform) with zero field width padding
int		hexl_zpad_pos_fits_af(void){return test("%#05x", 43);}
int		hexl_zpad_zero_fits_af(void){return test("%#03x", 0);}
int		hexl_zpad_pos_exactfit_af(void){return test("%#03x", 698334);}
//Hexadecimal lower (altform) with field width and precision
int		hexl_prec_width_fit_fit_pos_af(void){return test("%#8.5x", 34);}
int		hexl_prec_width_fit_fit_zero_af(void){return test("%#8.5x", 0);}
int		hexl_prec_width_nofit_fit_pos_af(void){return test("%#8.3x", 8375);}
int		hexl_prec_width_fit_nofit_pos_af(void){return test("%#2.7x", 3267);}
int		hexl_prec_width_nofit_nofit_pos_af(void){return test("%#3.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision, left-justified
int		hexl_prec_width_fit_fit_pos_lj_af(void){return test("%#-8.5x", 34);}
int		hexl_prec_width_fit_fit_zero_lj_af(void){return test("%#-8.5x", 0);}
int		hexl_prec_width_nofit_fit_pos_lj_af(void){return test("%#-8.3x", 8375);}
int		hexl_prec_width_fit_nofit_pos_lj_af(void){return test("%#-2.7x", 3267);}
int		hexl_prec_width_nofit_nofit_pos_lj_af(void){return test("%#-3.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision with zeropadding
int		hexl_prec_width_ff_pos_zpad_af(void){return test("%#08.5x", 34);}
int		hexl_prec_width_ff_zero_zpad_af(void){return test("%#08.5x", 0);}
int		hexl_prec_width_nf_pos_zpad_af(void){return test("%#08.3x", 8375);}
int		hexl_prec_width_fn_pos_zpad_af(void){return test("%#02.7x", 3267);}
int		hexl_prec_width_nn_pos_zpad_af(void){return test("%#03.3x", 6983);}
//Hexadecimal lower (altform) with field width and precision, left-justified with zeropadding
int		hexl_prec_width_ff_pos_lj_zpad_af(void){return test("%#0-8.5x", 34);}
int		hexl_prec_width_ff_zero_lj_zpad_af(void){return test("%#0-8.5x", 0);}
int		hexl_prec_width_nf_pos_lj_zpad_af(void){return test("%#0-8.3x", 8375);}
int		hexl_prec_width_fn_pos_lj_zpad_af(void){return test("%#0-2.7x", 3267);}
int		hexl_prec_width_nn_pos_lj_zpad_af(void){return test("%#0-3.3x", 6983);}
//Hexadecimal lower (altform) of varying size modifiers
int		hexl_size_hh_pos_casted_af(void){return test("%#hhx", (unsigned char)45);}
int		hexl_size_h_pos_casted_af(void){return test("%#hx", (unsigned short)385);}
int		hexl_size_l_pos_casted_af(void){return test("%#lx", (unsigned long)32);}
int		hexl_size_ll_pos_casted_af(void){return test("%#llx", (long long)43);}
int		hexl_size_hh_pos_ref_af(void){return test("%#hhx", uch_pos_1);}
int		hexl_size_h_pos_ref_af(void){return test("%#hx", ush_pos_1);}
int		hexl_size_l_pos_ref_af(void){return test("%#lx", ul_pos_1);}
int		hexl_size_ll_pos_ref_af(void){return test("%#llx", ull_pos_1);}
int		hexl_size_l_pos_big_af(void){return test("%#lx", 22337203685477);}
int		hexl_size_ll_pos_big_af(void){return test("%#llx", 522337203685470);}
int		hexl_ullmax_af(void){return test("%#llx", ullmax);}
int		hexl_ulmax_af(void){return test("%#lx", ulmax);}
int		hexl_uhmax_af(void){return test("%#hx", 65535);}
int		hexl_uhhmax_af(void){return test("%#hhx", 255);}
//Hexadecimal lower (altform) of varying size modifiers with some other modifiers
int		hexl_size_l_pos_big_zpad_af(void){return test("%#037lx", 22337203685477);}
int		hexl_size_ll_pos_big_width_af(void){return test("%#37llx", 522337203685470);}
//Multiple Hexadecimal lower (altform) in a row of varying sizes
int		hexl_size_ll_hh_ll_af(void){return test("%#llu%hhu%#llx", ull_pos_1, uch_pos_1, ull_pos_1);}
int		hexl_size_h_l_hh_af(void){return test("%#hu%#lu%hhx", ush_pos_1, ul_pos_1, uch_pos_1);}
int		hexl_size_l_hh_h_af(void){return test("%#lu%hhu%#hx", ul_pos_1, uch_pos_1, ush_pos_1);}
int		hexl_size_n_ll_hh_af(void){return test("%#u%llu%hhx", ui_pos_1, ull_pos_1, uch_pos_1);}
int		hexl_size_ll_n_l_af(void){return test("%#llu%u%#lx", ull_pos_1, ui_pos_1, ul_pos_1);}

//Hexadecimal uppers - no modifers
int		basic_hexu_pos(void){return test("this %X number", 17);}
int		basic_hexu_zero(void){return test("this %X number", 0);}
int		basic_hexu_onlypos(void){return test("%X", 3);}
int		hexu_hexumax(void){return test("%X", 4294967295);}
//Hexadecimal uppers with field width
int		hexu_width_pos_fits(void){return test("%7X", 33);}
int		hexu_width_zero_fits(void){return test("%3X", 0);}
int		hexu_width_pos_exactfit(void){return test("%5X", 52625);}
int		hexu_width_pos_nofit(void){return test("%2X", 94827);}
int		hexu_width_pos_fits_lj(void){return test("%-7X", 33);}
int		hexu_width_zero_fits_lj(void){return test("%-3X", 0);}
int		hexu_width_pos_exactfit_lj(void){return test("%-5X", 52625);}
int		hexu_width_pos_nofit_lj(void){return test("%-4X", 9648627);}
//Hexadecimal uppers with precision
int		hexu_prec_fits_pos(void){return test("%.5X", 21);}
int		hexu_prec_fits_zero(void){return test("%.3X", 0);}
int		hexu_prec_exactfit_pos(void){return test("%.4X", 5263);}
int		hexu_prec_nofit_pos(void){return test("%.3X", 938862);}
//Hexadecimal uppers with zero field width padding
int		hexu_zpad_pos_fits(void){return test("%05X", 43);}
int		hexu_zpad_zero_fits(void){return test("%03X", 0);}
int		hexu_zpad_pos_exactfit(void){return test("%03X", 698334);}
//Hexadecimal uppers with field width and precision
int		hexu_prec_width_fit_fit_pos(void){return test("%8.5X", 34);}
int		hexu_prec_width_fit_fit_zero(void){return test("%8.5X", 0);}
int		hexu_prec_width_nofit_fit_pos(void){return test("%8.3X", 8375);}
int		hexu_prec_width_fit_nofit_pos(void){return test("%2.7X", 3267);}
int		hexu_prec_width_nofit_nofit_pos(void){return test("%3.3X", 6983);}
//Hexadecimal uppers with field width and precision, left-justified
int		hexu_prec_width_fit_fit_pos_lj(void){return test("%-8.5X", 34);}
int		hexu_prec_width_fit_fit_zero_lj(void){return test("%-8.5X", 0);}
int		hexu_prec_width_nofit_fit_pos_lj(void){return test("%-8.3X", 8375);}
int		hexu_prec_width_fit_nofit_pos_lj(void){return test("%-2.7X", 3267);}
int		hexu_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3X", 6983);}
//Hexadecimal uppers with field width and precision with zeropadding
int		hexu_prec_width_ff_pos_zpad(void){return test("%08.5X", 34);}
int		hexu_prec_width_ff_zero_zpad(void){return test("%08.5X", 0);}
int		hexu_prec_width_nf_pos_zpad(void){return test("%08.3X", 8375);}
int		hexu_prec_width_fn_pos_zpad(void){return test("%02.7X", 3267);}
int		hexu_prec_width_nn_pos_zpad(void){return test("%03.3X", 6983);}
//Hexadecimal uppers with field width and precision, left-justified with zeropadding
int		hexu_prec_width_ff_pos_lj_zpad(void){return test("%0-8.5X", 34);}
int		hexu_prec_width_ff_zero_lj_zpad(void){return test("%0-8.5X", 0);}
int		hexu_prec_width_nf_pos_lj_zpad(void){return test("%0-8.3X", 8375);}
int		hexu_prec_width_fn_pos_lj_zpad(void){return test("%0-2.7X", 3267);}
int		hexu_prec_width_nn_pos_lj_zpad(void){return test("%0-3.3X", 6983);}
//Hexadecimal uppers of varying size modifiers
int		hexu_size_hh_pos_casted(void){return test("%hhX", (unsigned char)45);}
int		hexu_size_h_pos_casted(void){return test("%hX", (unsigned short)385);}
int		hexu_size_l_pos_casted(void){return test("%lX", (unsigned long)32);}
int		hexu_size_ll_pos_casted(void){return test("%llX", (long long)43);}
int		hexu_size_hh_pos_ref(void){return test("%hhX", uch_pos_1);}
int		hexu_size_h_pos_ref(void){return test("%hX", ush_pos_1);}
int		hexu_size_l_pos_ref(void){return test("%lX", ul_pos_1);}
int		hexu_size_ll_pos_ref(void){return test("%llX", ull_pos_1);}
int		hexu_size_l_pos_big(void){return test("%lX", 22337203685477);}
int		hexu_size_ll_pos_big(void){return test("%llX", 522337203685470);}
int		hexu_ullmax(void){return test("%llX", ullmax);}
int		hexu_ulmax(void){return test("%lX", ulmax);}
int		hexu_uhmax(void){return test("%hX", 65535);}
int		hexu_uhhmax(void){return test("%hhX", 255);}
//Hexadecimal uppers of varying size modifiers with some other modifiers
int		hexu_size_l_pos_big_zpad(void){return test("%037lX", 22337203685477);}
int		hexu_size_ll_pos_big_width(void){return test("%37llX", 522337203685470);}
//Multiple Hexadecimal uppers in a row of varying sizes
int		hexu_size_ll_hh_ll(void){return test("%llu%hhu%llX", ull_pos_1, uch_pos_1, ull_pos_1);}
int		hexu_size_h_l_hh(void){return test("%hu%lu%hhX", ush_pos_1, ul_pos_1, uch_pos_1);}
int		hexu_size_l_hh_h(void){return test("%lu%hhu%hX", ul_pos_1, uch_pos_1, ush_pos_1);}
int		hexu_size_n_ll_hh(void){return test("%u%llu%hhX", ui_pos_1, ull_pos_1, uch_pos_1);}
int		hexu_size_ll_n_l(void){return test("%llu%u%lX", ull_pos_1, ui_pos_1, ul_pos_1);}
//Hex uppers (altform) - no modifers
int		basic_hexu_pos_af(void){return test("this %#X number", 17);}
int		basic_hexu_zero_af(void){return test("this %#X number", 0);}
int		basic_hexu_onlypos_af(void){return test("%#X", 3);}
int		hexu_hexumax_af(void){return test("%#X", 4294967295);}
//Hex uppers (altform) with field width
int		hexu_width_pos_fits_af(void){return test("%#7X", 33);}
int		hexu_width_zero_fits_af(void){return test("%#3X", 0);}
int		hexu_width_pos_exactfit_af(void){return test("%#7X", 52625);}
int		hexu_width_pos_nofit_af(void){return test("%#2X", 94827);}
int		hexu_width_pos_fits_lj_af(void){return test("%#-7X", 33);}
int		hexu_width_zero_fits_lj_af(void){return test("%#-3X", 0);}
int		hexu_width_pos_exactfit_lj_af(void){return test("%#-7X", 52625);}
int		hexu_width_pos_nofit_lj_af(void){return test("%#-4X", 9648627);}
//Hex uppers (altform) with precision
int		hexu_prec_fits_pos_af(void){return test("%#.5X", 21);}
int		hexu_prec_fits_zero_af(void){return test("%#.3X", 0);}
int		hexu_prec_exactfit_pos_af(void){return test("%#.4X", 5263);}
int		hexu_prec_nofit_pos_af(void){return test("%#.3X", 938862);}
//Hex uppers (altform) with zero field width padding
int		hexu_zpad_pos_fits_af(void){return test("%#05X", 43);}
int		hexu_zpad_zero_fits_af(void){return test("%#03X", 0);}
int		hexu_zpad_pos_exactfit_af(void){return test("%#03X", 698334);}
//Hex uppers (altform) with field width and precision
int		hexu_prec_width_fit_fit_pos_af(void){return test("%#8.5X", 34);}
int		hexu_prec_width_fit_fit_zero_af(void){return test("%#8.5X", 0);}
int		hexu_prec_width_nofit_fit_pos_af(void){return test("%#8.3X", 8375);}
int		hexu_prec_width_fit_nofit_pos_af(void){return test("%#2.7X", 3267);}
int		hexu_prec_width_nofit_nofit_pos_af(void){return test("%#3.3X", 6983);}
//Hex uppers (altform) with field width and precision, left-justified
int		hexu_prec_width_fit_fit_pos_lj_af(void){return test("%#-8.5X", 34);}
int		hexu_prec_width_fit_fit_zero_lj_af(void){return test("%#-8.5X", 0);}
int		hexu_prec_width_nofit_fit_pos_lj_af(void){return test("%#-8.3X", 8375);}
int		hexu_prec_width_fit_nofit_pos_lj_af(void){return test("%#-2.7X", 3267);}
int		hexu_prec_width_nofit_nofit_pos_lj_af(void){return test("%#-3.3X", 6983);}
//Hex uppers (altform) with field width and precision with zeropadding
int		hexu_prec_width_ff_pos_zpad_af(void){return test("%#08.5X", 34);}
int		hexu_prec_width_ff_zero_zpad_af(void){return test("%#08.5X", 0);}
int		hexu_prec_width_nf_pos_zpad_af(void){return test("%#08.3X", 8375);}
int		hexu_prec_width_fn_pos_zpad_af(void){return test("%#02.7X", 3267);}
int		hexu_prec_width_nn_pos_zpad_af(void){return test("%#03.3X", 6983);}
//Hex uppers (altform) with field width and precision, left-justified with zeropadding
int		hexu_prec_width_ff_pos_lj_zpad_af(void){return test("%#0-8.5X", 34);}
int		hexu_prec_width_ff_zero_lj_zpad_af(void){return test("%#0-8.5X", 0);}
int		hexu_prec_width_nf_pos_lj_zpad_af(void){return test("%#0-8.3X", 8375);}
int		hexu_prec_width_fn_pos_lj_zpad_af(void){return test("%#0-2.7X", 3267);}
int		hexu_prec_width_nn_pos_lj_zpad_af(void){return test("%#0-3.3X", 6983);}
//Hex uppers (altform) of varying size modifiers
int		hexu_size_hh_pos_casted_af(void){return test("%#hhX", (unsigned char)45);}
int		hexu_size_h_pos_casted_af(void){return test("%#hX", (unsigned short)385);}
int		hexu_size_l_pos_casted_af(void){return test("%#lX", (unsigned long)32);}
int		hexu_size_ll_pos_casted_af(void){return test("%#llX", (long long)43);}
int		hexu_size_hh_pos_ref_af(void){return test("%#hhX", uch_pos_1);}
int		hexu_size_h_pos_ref_af(void){return test("%#hX", ush_pos_1);}
int		hexu_size_l_pos_ref_af(void){return test("%#lX", ul_pos_1);}
int		hexu_size_ll_pos_ref_af(void){return test("%#llX", ull_pos_1);}
int		hexu_size_l_pos_big_af(void){return test("%#lX", 22337203685477);}
int		hexu_size_ll_pos_big_af(void){return test("%#llX", 522337203685470);}
int		hexu_ullmax_af(void){return test("%#llX", ullmax);}
int		hexu_ulmax_af(void){return test("%#lX", ulmax);}
int		hexu_uhmax_af(void){return test("%#hX", 65535);}
int		hexu_uhhmax_af(void){return test("%#hhX", 255);}
//Hex uppers (altform) of varying size modifiers with some other modifiers
int		hexu_size_l_pos_big_zpad_af(void){return test("%#037lX", 22337203685477);}
int		hexu_size_ll_pos_big_width_af(void){return test("%#37llX", 522337203685470);}
//Multiple Hex uppers (altform) in a row of varying sizes
int		hexu_size_ll_hh_ll_af(void){return test("%#llu%#hhu%#llX", ull_pos_1, uch_pos_1, ull_pos_1);}
int		hexu_size_h_l_hh_af(void){return test("%#hu%lu%#hhX", ush_pos_1, ul_pos_1, uch_pos_1);}
int		hexu_size_l_hh_h_af(void){return test("%#lu%#hhu%hX", ul_pos_1, uch_pos_1, ush_pos_1);}
int		hexu_size_n_ll_hh_af(void){return test("%#u%#llu%#hhX", ui_pos_1, ull_pos_1, uch_pos_1);}
int		hexu_size_ll_n_l_af(void){return test("%#llu%u%#lX", ull_pos_1, ui_pos_1, ul_pos_1);}

//Octals - no modifers
int		basic_octl_pos(void){return test("this %o number", 17);}
int		basic_octl_zero(void){return test("this %o number", 0);}
int		basic_octl_onlypos(void){return test("%o", 3);}
int		octl_octlmax(void){return test("%o", 4294967295);}
//Octals with field width
int		octl_width_pos_fits(void){return test("%7o", 33);}
int		octl_width_zero_fits(void){return test("%3o", 0);}
int		octl_width_pos_exactfit(void){return test("%6o", 52625);}
int		octl_width_pos_nofit(void){return test("%2o", 94827);}
int		octl_width_pos_fits_lj(void){return test("%-7o", 33);}
int		octl_width_zero_fits_lj(void){return test("%-3o", 0);}
int		octl_width_pos_exactfit_lj(void){return test("%-6o", 52625);}
int		octl_width_pos_nofit_lj(void){return test("%-4o", 9648627);}
//Octals with precision
int		octl_prec_fits_pos(void){return test("%.5o", 21);}
int		octl_prec_fits_zero(void){return test("%.3o", 0);}
int		octl_prec_exactfit_pos(void){return test("%.5o", 5263);}
int		octl_prec_nofit_pos(void){return test("%.3o", 938862);}
//Octals with zero field width padding
int		octl_zpad_pos_fits(void){return test("%05o", 43);}
int		octl_zpad_zero_fits(void){return test("%03o", 0);}
int		octl_zpad_pos_exactfit(void){return test("%07o", 698334);}
//Octals with field width and precision
int		octl_prec_width_fit_fit_pos(void){return test("%8.5o", 34);}
int		octl_prec_width_fit_fit_zero(void){return test("%8.5o", 0);}
int		octl_prec_width_nofit_fit_pos(void){return test("%8.3o", 8375);}
int		octl_prec_width_fit_nofit_pos(void){return test("%2.7o", 3267);}
int		octl_prec_width_nofit_nofit_pos(void){return test("%3.3o", 6983);}
//Octals with field width and precision, left-justified
int		octl_prec_width_fit_fit_pos_lj(void){return test("%-8.5o", 34);}
int		octl_prec_width_fit_fit_zero_lj(void){return test("%-8.5o", 0);}
int		octl_prec_width_nofit_fit_pos_lj(void){return test("%-8.3o", 8375);}
int		octl_prec_width_fit_nofit_pos_lj(void){return test("%-2.7o", 3267);}
int		octl_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3o", 6983);}
//Octals with field width and precision with zeropadding
int		octl_prec_width_ff_pos_zpad(void){return test("%08.5o", 34);}
int		octl_prec_width_ff_zero_zpad(void){return test("%08.5o", 0);}
int		octl_prec_width_nf_pos_zpad(void){return test("%08.3o", 8375);}
int		octl_prec_width_fn_pos_zpad(void){return test("%02.7o", 3267);}
int		octl_prec_width_nn_pos_zpad(void){return test("%03.3o", 6983);}
//Octals with field width and precision, left-justified with zeropadding
int		octl_prec_width_ff_pos_lj_zpad(void){return test("%0-8.5o", 34);}
int		octl_prec_width_ff_zero_lj_zpad(void){return test("%0-8.5o", 0);}
int		octl_prec_width_nf_pos_lj_zpad(void){return test("%0-8.3o", 8375);}
int		octl_prec_width_fn_pos_lj_zpad(void){return test("%0-2.7o", 3267);}
int		octl_prec_width_nn_pos_lj_zpad(void){return test("%0-3.3o", 6983);}
//Octals of varying size modifiers
int		octl_size_hh_pos_casted(void){return test("%hho", (unsigned char)45);}
int		octl_size_h_pos_casted(void){return test("%ho", (unsigned short)385);}
int		octl_size_l_pos_casted(void){return test("%lo", (unsigned long)32);}
int		octl_size_ll_pos_casted(void){return test("%llo", (long long)43);}
int		octl_size_hh_pos_ref(void){return test("%hho", uch_pos_1);}
int		octl_size_h_pos_ref(void){return test("%ho", ush_pos_1);}
int		octl_size_l_pos_ref(void){return test("%lo", ul_pos_1);}
int		octl_size_ll_pos_ref(void){return test("%llo", ull_pos_1);}
int		octl_size_l_pos_big(void){return test("%lo", 22337203685477);}
int		octl_size_ll_pos_big(void){return test("%llo", 522337203685470);}
int		octl_ullmax(void){return test("%llo", ullmax);}
int		octl_ulmax(void){return test("%lo", ulmax);}
int		octl_uhmax(void){return test("%ho", 65535);}
int		octl_uhhmax(void){return test("%hho", 255);}
//Octals of varying size modifiers with some other modifiers
int		octl_size_l_pos_big_zpad(void){return test("%037lo", 22337203685477);}
int		octl_size_ll_pos_big_width(void){return test("%37llo", 522337203685470);}
//Multiple Octals in a row of varying sizes
int		octl_size_ll_hh_ll(void){return test("%llu%hhu%llo", ull_pos_1, uch_pos_1, ull_pos_1);}
int		octl_size_h_l_hh(void){return test("%hu%lu%hho", ush_pos_1, ul_pos_1, uch_pos_1);}
int		octl_size_l_hh_h(void){return test("%lu%hhu%ho", ul_pos_1, uch_pos_1, ush_pos_1);}
int		octl_size_n_ll_hh(void){return test("%u%llu%hho", ui_pos_1, ull_pos_1, uch_pos_1);}
int		octl_size_ll_n_l(void){return test("%llu%u%lo", ull_pos_1, ui_pos_1, ul_pos_1);}
//Octal (Altform)s - no modifers
int		basic_octl_pos_af(void){return test("this %#o number", 17);}
int		basic_octl_zero_af(void){return test("this %#o number", 0);}
int		basic_octl_onlypos_af(void){return test("%#o", 3);}
int		octl_octlmax_af(void){return test("%#o", 4294967295);}
//Octal (Altform)s with field width
int		octl_width_pos_fits_af(void){return test("%#7o", 33);}
int		octl_width_zero_fits_af(void){return test("%#3o", 0);}
int		octl_width_pos_exactfit_af(void){return test("%#6o", 52625);}
int		octl_width_pos_nofit_af(void){return test("%#2o", 94827);}
int		octl_width_pos_fits_lj_af(void){return test("%#-7o", 33);}
int		octl_width_zero_fits_lj_af(void){return test("%#-3o", 0);}
int		octl_width_pos_exactfit_lj_af(void){return test("%#-6o", 52625);}
int		octl_width_pos_nofit_lj_af(void){return test("%#-4o", 9648627);}
//Octal (Altform)s with precision
int		octl_prec_fits_pos_af(void){return test("%#.5o", 21);}
int		octl_prec_fits_zero_af(void){return test("%#.3o", 0);}
int		octl_prec_exactfit_pos_af(void){return test("%#.5o", 5263);}
int		octl_prec_nofit_pos_af(void){return test("%#.3o", 938862);}
//Octal (Altform)s with zero field width padding
int		octl_zpad_pos_fits_af(void){return test("%#05o", 43);}
int		octl_zpad_zero_fits_af(void){return test("%#03o", 0);}
int		octl_zpad_pos_exactfit_af(void){return test("%#07o", 698334);}
//Octal (Altform)s with field width and precision
int		octl_prec_width_fit_fit_pos_af(void){return test("%#8.5o", 34);}
int		octl_prec_width_fit_fit_zero_af(void){return test("%#8.5o", 0);}
int		octl_prec_width_nofit_fit_pos_af(void){return test("%#8.3o", 8375);}
int		octl_prec_width_fit_nofit_pos_af(void){return test("%#2.7o", 3267);}
int		octl_prec_width_nofit_nofit_pos_af(void){return test("%#3.3o", 6983);}
//Octal (Altform)s with field width and precision, left-justified
int		octl_prec_width_fit_fit_pos_lj_af(void){return test("%#-8.5o", 34);}
int		octl_prec_width_fit_fit_zero_lj_af(void){return test("%#-8.5o", 0);}
int		octl_prec_width_nofit_fit_pos_lj_af(void){return test("%#-8.3o", 8375);}
int		octl_prec_width_fit_nofit_pos_lj_af(void){return test("%#-2.7o", 3267);}
int		octl_prec_width_nofit_nofit_pos_lj_af(void){return test("%#-3.3o", 6983);}
//Octal (Altform)s with field width and precision with zeropadding
int		octl_prec_width_ff_pos_zpad_af(void){return test("%#08.5o", 34);}
int		octl_prec_width_ff_zero_zpad_af(void){return test("%#08.5o", 0);}
int		octl_prec_width_nf_pos_zpad_af(void){return test("%#08.3o", 8375);}
int		octl_prec_width_fn_pos_zpad_af(void){return test("%#02.7o", 3267);}
int		octl_prec_width_nn_pos_zpad_af(void){return test("%#03.3o", 6983);}
//Octal (Altform)s with field width and precision, left-justified with zeropadding
int		octl_prec_width_ff_pos_lj_zpad_af(void){return test("%#0-8.5o", 34);}
int		octl_prec_width_ff_zero_lj_zpad_af(void){return test("%#0-8.5o", 0);}
int		octl_prec_width_nf_pos_lj_zpad_af(void){return test("%#0-8.3o", 8375);}
int		octl_prec_width_fn_pos_lj_zpad_af(void){return test("%#0-2.7o", 3267);}
int		octl_prec_width_nn_pos_lj_zpad_af(void){return test("%#0-3.3o", 6983);}
//Octal (Altform)s of varying size modifiers
int		octl_size_hh_pos_casted_af(void){return test("%#hho", (unsigned char)45);}
int		octl_size_h_pos_casted_af(void){return test("%#ho", (unsigned short)385);}
int		octl_size_l_pos_casted_af(void){return test("%#lo", (unsigned long)32);}
int		octl_size_ll_pos_casted_af(void){return test("%#llo", (long long)43);}
int		octl_size_hh_pos_ref_af(void){return test("%#hho", uch_pos_1);}
int		octl_size_h_pos_ref_af(void){return test("%#ho", ush_pos_1);}
int		octl_size_l_pos_ref_af(void){return test("%#lo", ul_pos_1);}
int		octl_size_ll_pos_ref_af(void){return test("%#llo", ull_pos_1);}
int		octl_size_l_pos_big_af(void){return test("%#lo", 22337203685477);}
int		octl_size_ll_pos_big_af(void){return test("%#llo", 522337203685470);}
int		octl_ullmax_af(void){return test("%#llo", ullmax);}
int		octl_ulmax_af(void){return test("%#lo", ulmax);}
int		octl_uhmax_af(void){return test("%#ho", 65535);}
int		octl_uhhmax_af(void){return test("%#hho", 255);}
//Octal (Altform)s of varying size modifiers with some other modifiers
int		octl_size_l_pos_big_zpad_af(void){return test("%#037lo", 22337203685477);}
int		octl_size_ll_pos_big_width_af(void){return test("%#37llo", 522337203685470);}
//Multiple Octal (Altform)s in a row of varying sizes
int		octl_size_ll_hh_ll_af(void){return test("%#llu%hhu%llo", ull_pos_1, uch_pos_1, ull_pos_1);}
int		octl_size_h_l_hh_af(void){return test("%#hu%lu%hho", ush_pos_1, ul_pos_1, uch_pos_1);}
int		octl_size_l_hh_h_af(void){return test("%#lu%hhu%ho", ul_pos_1, uch_pos_1, ush_pos_1);}
int		octl_size_n_ll_hh_af(void){return test("%#u%llu%hho", ui_pos_1, ull_pos_1, uch_pos_1);}
int		octl_size_ll_n_l_af(void){return test("%#llu%u%lo", ull_pos_1, ui_pos_1, ul_pos_1);}

//Pointers - Basic
char	a01;
unsigned char a02;
short a03;
unsigned short a04;
int a05;
unsigned int a06;
long a07;
unsigned long a08;
long long a09;
unsigned long long a10;
char *a11;
void *a12;
t_ftpf_expandler a13;

int		ptr_null(void){return test("%p", NULL);}

int		ptr_basic(void){return test("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_fit(void){return test("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_nofit(void){return test("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_16(void){return test("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_8(void){return test("%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_32(void){return test("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_fit_zpad(void){return test("%070p%070p%070p%070p%070p%070p%070p%070p%070p%070p%070p%070p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_nofit_zpad(void){return test("%05p%05p%05p%05p%05p%05p%05p%05p%05p%05p%05p%05p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_16_zpad(void){return test("%016p%016p%016p%016p%016p%016p%016p%016p%016p%016p%016p%016p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_8_zpad(void){return test("%08p%08p%08p%08p%08p%08p%08p%08p%08p%08p%08p%08p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_32_zpad(void){return test("%032p%032p%032p%032p%032p%032p%032p%032p%032p%032p%032p%032p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_fit_lj(void){return test("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_nofit_lj(void){return test("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_16_lj(void){return test("%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_8_lj(void){return test("%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_32_lj(void){return test("%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_fit_zpad_lj(void){return test("%-070p%-070p%-070p%-070p%-070p%-070p%-070p%-070p%-070p%-070p%-070p%-070p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_nofit_zpad_lj(void){return test("%-05p%-05p%-05p%-05p%-05p%-05p%-05p%-05p%-05p%-05p%-05p%-05p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_16_zpad_lj(void){return test("%-016p%-016p%-016p%-016p%-016p%-016p%-016p%-016p%-016p%-016p%-016p%-016p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_8_zpad_lj(void){return test("%-08p%-08p%-08p%-08p%-08p%-08p%-08p%-08p%-08p%-08p%-08p%-08p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}


int		ptr_width_32_zpad_lj(void){return test("%-032p%-032p%-032p%-032p%-032p%-032p%-032p%-032p%-032p%-032p%-032p%-032p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);}

//Chars - Basic
int		char_allprintable_combined(void){return test("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int		char_1_31_combined(void){return test("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int		char_128_255_combined(void){return test("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}

int		char_allprintable_width(void){return test("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int		char_1_31_width(void){return test("%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int		char_128_255_width(void){return test("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}

int		char_allprintable_width_zpad(void){return test("%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int		char_1_31_width_zpad(void){return test("%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int		char_128_255_width_zpad(void){return test("%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c%01c%02c%03c%04c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}

int		char_allprintable_width_lj(void){return test("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int		char_1_31_width_lj(void){return test("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int		char_128_255_width_lj(void){return test("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}

int		char_allprintable_width_zpad_lj(void){return test("%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');}

int		char_1_31_width_zpad_lj(void){return test("%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);}

int		char_128_255_width_zpad_lj(void){return test("%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c%-01c%-02c%-03c%-04c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);}















//Floats - Basic
int		flt_basic_1(void){return test("this %f float", 1.5);}
int		flt_basic_fltonly(void){return test("%f", 7.5);}
int		flt_basic_whole(void){return test("%f", 1.0);}
int		flt_basic_negative(void){return test("%f", -3.85);}
int		flt_basic_positive_3_3(void){return test("%f", 573.924);}
int		flt_basic_negative_3_3(void){return test("%f", -958.125);}
int		flt_basic_positive_smallfpart(void){return test("%f", 23.00041);}
int		flt_basic_positive_allsmall(void){return test("%f", 0.000039);}
int		flt_basic_negative_smallfpart(void){return test("%f", -7.00036);}
int		flt_basic_negative_allsmall(void){return test("%f", -0.00032);}
int		flt_dfprec_limits_allsmall_pos(void){return test("%f", 0.000001);}
int		flt_dfprec_limits_allsmall_neg(void){return test("%f", -0.000001);}
int		flt_dfprec_limits_smallfpart_pos(void){return test("%f", 9873.000001);}
int		flt_dfprec_limits_smallfpart_neg(void){return test("%f", -875.000001);}
int		flt_dfprec_limits_allbig_pos(void){return test("%f", 999.999999);}
int		flt_dfprec_limits_allbig_neg(void){return test("%f", -99.999999);}
int		flt_dfprec_limits_bigfpart_pos(void){return test("%f", 0.999999);}
int		flt_dfprec_limits_bigfpart_neg(void){return test("%f", -0.999999);}
//Floats - Rounding with default precision
int		flt_rndd_pos(void){return test("%f", 23.375094499);}
int		flt_rndd_neg(void){return test("%f", -985.765426499);}
int		flt_rndu_pos(void){return test("%f", 0.0894255);}
int		flt_rndu_neg(void){return test("%f", -56.2012685);}
int		flt_rndu_multidigit_pos(void){return test("%f", 43.4399999);}
int		flt_rndu_multidigit_neg(void){return test("%f", -5.0299999);}
int		flt_rndd_multidigit_pos(void){return test("%f", 43.43999949);}
int		flt_rndd_multidigit_neg(void){return test("%f", -5.02999949);}
int		flt_rndd_wholnobump_pos(void){return test("%f", 1.99999949);}
int		flt_rndd_wholnobump_neg(void){return test("%f", -0.99999949);}
int		flt_rndu_bumpwhole_pos(void){return test("%f", 3.9999999);}
int		flt_rndu_bumpwhole_neg(void){return test("%f", -5.9999999);}
//Floats Prec 0
int		flt_prec0_1(void){return test("this %.0f float", 1.6);}
int		flt_prec0_fltonly(void){return test("%.0f", 7.4);}
int		flt_prec0_whole(void){return test("%.0f", 1.0);}
int		flt_prec0_negative(void){return test("%.0f", -3.85);}
int		flt_prec0_positive_3_3(void){return test("%.0f", 573.924);}
int		flt_prec0_negative_3_3(void){return test("%.0f", -958.125);}
int		flt_prec0_positive_smallfpart(void){return test("%.0f", 23.00041);}
int		flt_prec0_positive_allsmall(void){return test("%.0f", 0.000039);}
int		flt_prec0_negative_smallfpart(void){return test("%.0f", -7.00036);}
int		flt_prec0_negative_allsmall(void){return test("%.0f", -0.00032);}
//Floats Prec 1
int		flt_prec1_1(void){return test("this %.1f float", 1.5);}
int		flt_prec1_fltonly(void){return test("%.1f", 7.5);}
int		flt_prec1_whole(void){return test("%.1f", 1.0);}
int		flt_prec1_negative(void){return test("%.1f", -3.85);}
int		flt_prec1_positive_3_3(void){return test("%.1f", 573.924);}
int		flt_prec1_negative_3_3(void){return test("%.1f", -958.125);}
int		flt_prec1_positive_smallfpart(void){return test("%.1f", 23.00041);}
int		flt_prec1_positive_allsmall(void){return test("%.1f", 0.000039);}
int		flt_prec1_negative_smallfpart(void){return test("%.1f", -7.00036);}
int		flt_prec1_negative_allsmall(void){return test("%.1f", -0.00032);}
//Floats Prec 3
int		flt_prec3_1(void){return test("this %.3f float", 1.5);}
int		flt_prec3_fltonly(void){return test("%.3f", 7.5);}
int		flt_prec3_whole(void){return test("%.3f", 1.0);}
int		flt_prec3_negative(void){return test("%.3f", -3.85);}
int		flt_prec3_positive_3_3(void){return test("%.3f", 573.924);}
int		flt_prec3_negative_3_3(void){return test("%.3f", -958.125);}
int		flt_prec3_positive_smallfpart(void){return test("%.3f", 23.00041);}
int		flt_prec3_positive_allsmall(void){return test("%.3f", 0.000039);}
int		flt_prec3_negative_smallfpart(void){return test("%.3f", -7.00036);}
int		flt_prec3_negative_allsmall(void){return test("%.3f", -0.00032);}
//Floats - Prec 7
int		flt_prec7_1(void){return test("this %.7f float", 1.5);}
int		flt_prec7_fltonly(void){return test("%.7f", 7.5);}
int		flt_prec7_whole(void){return test("%.7f", 1.0);}
int		flt_prec7_negative(void){return test("%.7f", -3.85);}
int		flt_prec7_positive_3_3(void){return test("%.7f", 573.924);}
int		flt_prec7_negative_3_3(void){return test("%.7f", -958.125);}
int		flt_prec7_positive_smallfpart(void){return test("%.7f", 23.00041);}
int		flt_prec7_positive_allsmall(void){return test("%.7f", 0.0000039);}
int		flt_prec7_negative_smallfpart(void){return test("%.7f", -7.00036);}
int		flt_prec7_negative_allsmall(void){return test("%.7f", -0.000032);}
int		flt_prec7_limits_allsmall_pos(void){return test("%.7f", 0.0000001);}
int		flt_prec7_limits_allsmall_neg(void){return test("%.7f", -0.0000001);}
int		flt_prec7_limits_smallfpart_pos(void){return test("%.7f", 9873.000001);}
int		flt_prec7_limits_smallfpart_neg(void){return test("%.7f", -875.000001);}
int		flt_prec7_limits_allbig_pos(void){return test("%.7f", 999.9999999);}
int		flt_prec7_limits_allbig_neg(void){return test("%.7f", -99.9999999);}
int		flt_prec7_limits_bigfpart_pos(void){return test("%.7f", 0.999999);}
int		flt_prec7_limits_bigfpart_neg(void){return test("%.7f", -0.999999);}
//Floats - Prec 7 Rounding
int		flt_prec7_rndd_pos(void){return test("%.7f", 23.375094499);}
int		flt_prec7_rndd_neg(void){return test("%.7f", -985.765426499);}
int		flt_prec7_rndu_pos(void){return test("%.7f", 0.0894255);}
int		flt_prec7_rndu_neg(void){return test("%.7f", -56.2012685);}
int		flt_prec7_rndu_multidigit_pos(void){return test("%.7f", 43.4399999);}
int		flt_prec7_rndu_multidigit_neg(void){return test("%.7f", -5.0299999);}
int		flt_prec7_rndd_multidigit_pos(void){return test("%.7f", 43.43999949);}
int		flt_prec7_rndd_multidigit_neg(void){return test("%.7f", -5.02999949);}
int		flt_prec7_rndd_wholnobump_pos(void){return test("%.7f", 1.99999949);}
int		flt_prec7_rndd_wholnobump_neg(void){return test("%.7f", -0.99999949);}
int		flt_prec7_rndu_bumpwhole_pos(void){return test("%.7f", 3.9999999);}
//Floats - Prec 8
int		flt_prec8_1(void){return test("this %.8f float", 1.5);}
int		flt_prec8_fltonly(void){return test("%.8f", 7.5);}
int		flt_prec8_whole(void){return test("%.8f", 1.0);}
int		flt_prec8_negative(void){return test("%.8f", -3.85);}
int		flt_prec8_positive_3_3(void){return test("%.8f", 573.924);}
int		flt_prec8_negative_3_3(void){return test("%.8f", -958.125);}
int		flt_prec8_positive_smallfpart(void){return test("%.8f", 23.00041);}
int		flt_prec8_positive_allsmall(void){return test("%.8f", 0.00000039);}
int		flt_prec8_negative_smallfpart(void){return test("%.8f", -7.00036);}
int		flt_prec8_negative_allsmall(void){return test("%.8f", -0.0000032);}
int		flt_prec8_limits_allsmall_pos(void){return test("%.8f", 0.00000001);}
int		flt_prec8_limits_allsmall_neg(void){return test("%.8f", -0.00000001);}
int		flt_prec8_limits_smallfpart_pos(void){return test("%.8f", 9873.000001);}
int		flt_prec8_limits_smallfpart_neg(void){return test("%.8f", -875.000001);}
int		flt_prec8_limits_allbig_pos(void){return test("%.8f", 999.9999999);}
int		flt_prec8_limits_allbig_neg(void){return test("%.8f", -99.99999999);}
int		flt_prec8_limits_bigfpart_pos(void){return test("%.8f", 0.999999);}
int		flt_prec8_limits_bigfpart_neg(void){return test("%.8f", -0.999999);}
//Floats - Prec 8 Rounding
int		flt_prec8_rndd_pos(void){return test("%.8f", 23.375094499);}
int		flt_prec8_rndd_neg(void){return test("%.8f", -985.765426499);}
int		flt_prec8_rndu_pos(void){return test("%.8f", 0.0894255);}
int		flt_prec8_rndu_neg(void){return test("%.8f", -56.2012685);}
int		flt_prec8_rndu_multidigit_pos(void){return test("%.8f", 43.4399999);}
int		flt_prec8_rndu_multidigit_neg(void){return test("%.8f", -5.0299999);}
int		flt_prec8_rndd_multidigit_pos(void){return test("%.8f", 43.43999949);}
int		flt_prec8_rndd_multidigit_neg(void){return test("%.8f", -5.02999949);}
int		flt_prec8_rndd_wholnobump_pos(void){return test("%.8f", 1.99999949);}
int		flt_prec8_rndd_wholnobump_neg(void){return test("%.8f", -0.99999949);}
int		flt_prec8_rndu_bumpwhole_pos(void){return test("%.8f", 3.9999999);}
//Floats - Prec 9
int		flt_prec9_1(void){return test("this %.9f float", 1.5);}
int		flt_prec9_fltonly(void){return test("%.9f", 7.5);}
int		flt_prec9_whole(void){return test("%.9f", 1.0);}
int		flt_prec9_negative(void){return test("%.9f", -3.85);}
int		flt_prec9_positive_3_3(void){return test("%.9f", 573.924);}
int		flt_prec9_negative_3_3(void){return test("%.9f", -958.125);}
int		flt_prec9_positive_smallfpart(void){return test("%.9f", 23.00041);}
int		flt_prec9_positive_allsmall(void){return test("%.9f", 0.00000039);}
int		flt_prec9_negative_smallfpart(void){return test("%.9f", -7.00036);}
int		flt_prec9_negative_allsmall(void){return test("%.9f", -0.0000032);}
int		flt_prec9_limits_allsmall_pos(void){return test("%.9f", 0.00000001);}
int		flt_prec9_limits_allsmall_neg(void){return test("%.9f", -0.00000001);}
int		flt_prec9_limits_smallfpart_pos(void){return test("%.9f", 9873.000001);}
int		flt_prec9_limits_smallfpart_neg(void){return test("%.9f", -875.000001);}
int		flt_prec9_limits_allbig_pos(void){return test("%.9f", 999.99999999);}
int		flt_prec9_limits_allbig_neg(void){return test("%.9f", -99.99999999);}
int		flt_prec9_limits_bigfpart_pos(void){return test("%.9f", 0.999999);}
int		flt_prec9_limits_bigfpart_neg(void){return test("%.9f", -0.999999);}
//Floats - Prec 9 Rounding
int		flt_prec9_rndd_pos(void){return test("%.9f", 23.375094499);}
int		flt_prec9_rndd_neg(void){return test("%.9f", -985.765426499);}
int		flt_prec9_rndu_pos(void){return test("%.9f", 0.0894255);}
int		flt_prec9_rndu_neg(void){return test("%.9f", -56.2012685);}
int		flt_prec9_rndu_multidigit_pos(void){return test("%.9f", 43.4399999);}
int		flt_prec9_rndu_multidigit_neg(void){return test("%.9f", -5.0299999);}
int		flt_prec9_rndd_multidigit_pos(void){return test("%.9f", 43.43999949);}
int		flt_prec9_rndd_multidigit_neg(void){return test("%.9f", -5.02999949);}
int		flt_prec9_rndd_wholnobump_pos(void){return test("%.9f", 1.99999949);}
int		flt_prec9_rndd_wholnobump_neg(void){return test("%.9f", -0.99999949);}
int		flt_prec9_rndu_bumpwhole_pos(void){return test("%.9f", 3.9999999);}
//Floats - Prec 10
int		flt_prec10_1(void){return test("this %.10f float", 1.5);}
int		flt_prec10_fltonly(void){return test("%.10f", 7.5);}
int		flt_prec10_whole(void){return test("%.10f", 1.0);}
int		flt_prec10_negative(void){return test("%.10f", -3.85);}
int		flt_prec10_positive_3_10(void){return test("%.10f", 573.924);}
int		flt_prec10_negative_3_10(void){return test("%.10f", -958.125);}
int		flt_prec10_pos(void){return test("%.10f", 23.8341375094);}
int		flt_prec10_neg(void){return test("%.10f", -985.2459765426);}
int		flt_prec10_rndd_pos(void){return test("%.10f", 23.8341375094499);}
int		flt_prec10_rndd_neg(void){return test("%.10f", -985.2459765426499);}
int		flt_prec10_rndu_pos(void){return test("%.10f", 0.87650894255);}
int		flt_prec10_rndu_neg(void){return test("%.10f", -56.47852012685);}
int		flt_prec10_positive_smallfpart(void){return test("%.10f", 23.000000041);}
int		flt_prec10_positive_allsmall(void){return test("%.10f", 0.0000000039);}
int		flt_prec10_negative_smallfpart(void){return test("%.10f", -7.000000036);}
int		flt_prec10_negative_allsmall(void){return test("%.10f", -0.000000032);}
int		flt_prec10_limits_allsmall_pos(void){return test("%.10f", 0.0000000001);}
int		flt_prec10_limits_allsmall_neg(void){return test("%.10f", -0.0000000001);}
int		flt_prec10_limits_smallfpart_pos(void){return test("%.10f", 9873.0000000001);}
int		flt_prec10_limits_smallfpart_neg(void){return test("%.10f", -875.0000000001);}
int		flt_prec10_limits_allbig_pos(void){return test("%.10f", 999.9999999999);}
int		flt_prec10_limits_allbig_neg(void){return test("%.10f", -99.9999999999);}
int		flt_prec10_limits_bigfpart_pos(void){return test("%.10f", 0.9999999999);}
int		flt_prec10_limits_bigfpart_neg(void){return test("%.10f", -0.9999999999);}
//Floats - Prec 11
int		flt_prec11_rndu(void){return test("%.11f",        1.025978541236587568);}
int		flt_prec11_rndd(void){return test("%.11f",        1.025978548534310421);}
int		flt_prec11_limits_tiny(void){return test("%.11f", 0.000000000010000000);}
int		flt_prec11_limits_big(void){return test("%.11f", 99.999999999990000000);}
//Floats - Prec 12
int		flt_prec12_rndu(void){return test("%.12f",        1.025978541236587568);}
int		flt_prec12_rndd(void){return test("%.12f",        1.025978548534310421);}
int		flt_prec12_limits_tiny(void){return test("%.12f", 0.000000000001000000);}
int		flt_prec12_limits_big(void){return test("%.12f", 99.999999999999000000);}
//Floats - Prec 13
int		flt_prec13_rndu(void){return test("%.13f",        1.025978541136587568);}
int		flt_prec13_rndd(void){return test("%.13f",        1.025978548534310421);}
int		flt_prec13_limits_tiny(void){return test("%.13f", 0.000000000000100000);}
int		flt_prec13_limits_big(void){return test("%.13f", 99.999999999999900000);}
//Floats - Prec 14
int		flt_prec14_rndu(void){return test("%.14f",        1.025978541436587568);}
int		flt_prec14_rndd(void){return test("%.14f",        1.025978548534310421);}
int		flt_prec14_limits_tiny(void){return test("%.14f", 0.000000000000010000);}
int		flt_prec14_limits_big(void){return test("%.14f",  9.999999999999990000);}
//Floats - Prec 15
int		flt_prec15_rndu(void){return test("%.15f",        1.025978542436587568);}
int		flt_prec15_rndd(void){return test("%.15f",        1.025978548534310421);}
int		flt_prec15_limits_tiny(void){return test("%.15f", 0.000000000000001000);}
int		flt_prec15_limits_big(void){return test("%.15f",  0.999999999999999000);}
//Floats - Prec 16
int		flt_prec16_rndu(void){return test("%.16f",        1.025978542436587568);}
int		flt_prec16_rndd(void){return test("%.16f",        1.025978548534310421);}
int		flt_prec16_limits_tiny(void){return test("%.16f", 0.000000000000000100);}
int		flt_prec16_limits_big(void){return test("%.16f",  0.999999999999999900);}
//Floats - Prec 17
int		flt_prec17_rndu(void){return test("%.17f",        1.025978542436587568);}
int		flt_prec17_rndd(void){return test("%.17f",        1.025978548534310421);}
int		flt_prec17_limits_tiny(void){return test("%.17f", 0.000000000000000010);}
int		flt_prec17_limits_big(void){return test("%.17f",  0.999999999999999990);}
//Floats - Prec 18
int		flt_prec18_rndu(void){return test("%.18f",        0.125978542436587568);}
int		flt_prec18_rndd(void){return test("%.18f",        0.125978548534310421);}
//Floats with altform,~
int		flt_prec0p_af(void){return test("%#.0f", 7.4);}
int		flt_prec1p_af(void){return test("%#.1f", 7.3);}
int		flt_prec0n_af(void){return test("%#.0f", -7.4);}
int		flt_prec1n_af(void){return test("%#.1f", -7.3);}
//Floats with allsign,~
int		flt_prec0p_as(void){return test("%+.0f", 7.4);}
int		flt_prec3p_as(void){return test("%+.3f", 7.3);}
int		flt_prec0n_as(void){return test("%+.0f", -7.4);}
int		flt_prec3n_as(void){return test("%+.3f", -7.3);}
//Floats with field width,~
int		flt_prec0p_5w(void){return test("%5.0f", 7.3);}
int		flt_prec1p_5w(void){return test("%5.1f", 7.3);}
int		flt_prec3p_5w(void){return test("%5.3f", 7.3);}
int		flt_prec6p_5w(void){return test("%5.6f", 7.3);}
int		flt_prec0n_5w(void){return test("%5.0f", -7.3);}
int		flt_prec1n_5w(void){return test("%5.1f", -7.3);}
int		flt_prec3n_5w(void){return test("%5.3f", -7.3);}
int		flt_prec6n_5w(void){return test("%5.6f", -7.3);}
//Floats with field width and zero padding,~
int		flt_prec0p_5w_zp(void){return test("%05.0f", 7.3);}
int		flt_prec1p_5w_zp(void){return test("%05.1f", 7.3);}
int		flt_prec3p_5w_zp(void){return test("%05.3f", 7.3);}
int		flt_prec6p_5w_zp(void){return test("%05.6f", 7.3);}
int		flt_prec0n_5w_zp(void){return test("%05.0f", -7.3);}
int		flt_prec1n_5w_zp(void){return test("%05.1f", -7.3);}
int		flt_prec3n_5w_zp(void){return test("%05.3f", -7.3);}
int		flt_prec6n_5w_zp(void){return test("%05.6f", -7.3);}
//Floats with field width and left justify,~
int		flt_prec0p_5w_lj(void){return test("%-5.0f", 7.3);}
int		flt_prec1p_5w_lj(void){return test("%-5.1f", 7.3);}
int		flt_prec3p_5w_lj(void){return test("%-5.3f", 7.3);}
int		flt_prec6p_5w_lj(void){return test("%-5.6f", 7.3);}
int		flt_prec0n_5w_lj(void){return test("%-5.0f", -7.3);}
int		flt_prec1n_5w_lj(void){return test("%-5.1f", -7.3);}
int		flt_prec3n_5w_lj(void){return test("%-5.3f", -7.3);}
int		flt_prec6n_5w_lj(void){return test("%-5.6f", -7.3);}
//Floats with field width and zero padding and left justify,~
int		flt_prec0p_5w_zplj(void){return test("%-05.0f", 7.3);}
int		flt_prec1p_5w_zplj(void){return test("%-05.1f", 7.3);}
int		flt_prec3p_5w_zplj(void){return test("%-05.3f", 7.3);}
int		flt_prec6p_5w_zplj(void){return test("%-05.6f", 7.3);}
int		flt_prec0n_5w_zplj(void){return test("%-05.0f", -7.3);}
int		flt_prec1n_5w_zplj(void){return test("%-05.1f", -7.3);}
int		flt_prec3n_5w_zplj(void){return test("%-05.3f", -7.3);}
int		flt_prec6n_5w_zplj(void){return test("%-05.6f", -7.3);}
//Floats with field width and zero padding and left justify, rev f order,~
int		flt_prec0p_5w_zpljr(void){return test("%0-5.0f", 7.3);}
int		flt_prec1p_5w_zpljr(void){return test("%0-5.1f", 7.3);}
int		flt_prec3p_5w_zpljr(void){return test("%0-5.3f", 7.3);}
int		flt_prec6p_5w_zpljr(void){return test("%0-5.6f", 7.3);}
int		flt_prec0n_5w_zpljr(void){return test("%0-5.0f", -7.3);}
int		flt_prec1n_5w_zpljr(void){return test("%0-5.1f", -7.3);}
int		flt_prec3n_5w_zpljr(void){return test("%0-5.3f", -7.3);}
int		flt_prec6n_5w_zpljr(void){return test("%0-5.6f", -7.3);}
//Floats with field width and left justify and altform,~
int		flt_prec0p_5w_zpljaf(void){return test("%#-5.0f", 7.3);}
int		flt_prec1p_5w_zpljaf(void){return test("%#-5.1f", 7.3);}
int		flt_prec3p_5w_zpljaf(void){return test("%#-5.3f", 7.3);}
int		flt_prec6p_5w_zpljaf(void){return test("%#-5.6f", 7.3);}
int		flt_prec0n_5w_zpljaf(void){return test("%#-5.0f", -7.3);}
int		flt_prec1n_5w_zpljaf(void){return test("%#-5.1f", -7.3);}
int		flt_prec3n_5w_zpljaf(void){return test("%#-5.3f", -7.3);}
int		flt_prec6n_5w_zpljaf(void){return test("%#-5.6f", -7.3);}
//Floats with field width and allsign,~
int		flt_prec0p_5was(void){return test("%+5.0f", 7.3);}
int		flt_prec1p_5was(void){return test("%+5.1f", 7.3);}
int		flt_prec3p_5was(void){return test("%+5.3f", 7.3);}
int		flt_prec6p_5was(void){return test("%+5.6f", 7.3);}
int		flt_prec0n_5was(void){return test("%+5.0f", -7.3);}
int		flt_prec1n_5was(void){return test("%+5.1f", -7.3);}
int		flt_prec3n_5was(void){return test("%+5.3f", -7.3);}
int		flt_prec6n_5was(void){return test("%+5.6f", -7.3);}
//Floats with field width and zero padding and allsign,~
int		flt_prec0p_5w_zpas(void){return test("%+05.0f", 7.3);}
int		flt_prec1p_5w_zpas(void){return test("%+05.1f", 7.3);}
int		flt_prec3p_5w_zpas(void){return test("%+05.3f", 7.3);}
int		flt_prec6p_5w_zpas(void){return test("%+05.6f", 7.3);}
int		flt_prec0n_5w_zpas(void){return test("%+05.0f", -7.3);}
int		flt_prec1n_5w_zpas(void){return test("%+05.1f", -7.3);}
int		flt_prec3n_5w_zpas(void){return test("%+05.3f", -7.3);}
int		flt_prec6n_5w_zpas(void){return test("%+05.6f", -7.3);}
//Floats with field width and left justify and allsign,~
int		flt_prec0p_5w_ljas(void){return test("%+-5.0f", 7.3);}
int		flt_prec1p_5w_ljas(void){return test("%+-5.1f", 7.3);}
int		flt_prec3p_5w_ljas(void){return test("%+-5.3f", 7.3);}
int		flt_prec6p_5w_ljas(void){return test("%+-5.6f", 7.3);}
int		flt_prec0n_5w_ljas(void){return test("%+-5.0f", -7.3);}
int		flt_prec1n_5w_ljas(void){return test("%+-5.1f", -7.3);}
int		flt_prec3n_5w_ljas(void){return test("%+-5.3f", -7.3);}
int		flt_prec6n_5w_ljas(void){return test("%+-5.6f", -7.3);}
//Floats with field width and zero padding and left justify and allsign,~
int		flt_prec0p_5w_zpljas(void){return test("%+-05.0f", 7.3);}
int		flt_prec1p_5w_zpljas(void){return test("%+-05.1f", 7.3);}
int		flt_prec3p_5w_zpljas(void){return test("%+-05.3f", 7.3);}
int		flt_prec6p_5w_zpljas(void){return test("%+-05.6f", 7.3);}
int		flt_prec0n_5w_zpljas(void){return test("%+-05.0f", -7.3);}
int		flt_prec1n_5w_zpljas(void){return test("%+-05.1f", -7.3);}
int		flt_prec3n_5w_zpljas(void){return test("%+-05.3f", -7.3);}
int		flt_prec6n_5w_zpljas(void){return test("%+-05.6f", -7.3);}
//Floats with field width left justify, rev f order and allsign,~
int		flt_prec0p_5w_zpljras(void){return test("%-+5.0f", 7.3);}
int		flt_prec1p_5w_zpljras(void){return test("%-+5.1f", 7.3);}
int		flt_prec3p_5w_zpljras(void){return test("%-+5.3f", 7.3);}
int		flt_prec6p_5w_zpljras(void){return test("%-+5.6f", 7.3);}
int		flt_prec0n_5w_zpljras(void){return test("%-+5.0f", -7.3);}
int		flt_prec1n_5w_zpljras(void){return test("%-+5.1f", -7.3);}
int		flt_prec3n_5w_zpljras(void){return test("%-+5.3f", -7.3);}
int		flt_prec6n_5w_zpljras(void){return test("%-+5.6f", -7.3);}
//Floats with field width and left justify and altform and allsign,~
int		flt_prec0p_5w_zpljafas(void){return test("%+#-5.0f", 7.3);}
int		flt_prec1p_5w_zpljafas(void){return test("%+#-5.1f", 7.3);}
int		flt_prec3p_5w_zpljafas(void){return test("%+#-5.3f", 7.3);}
int		flt_prec6p_5w_zpljafas(void){return test("%+#-5.6f", 7.3);}
int		flt_prec0n_5w_zpljafas(void){return test("%+#-5.0f", -7.3);}
int		flt_prec1n_5w_zpljafas(void){return test("%+#-5.1f", -7.3);}
int		flt_prec3n_5w_zpljafas(void){return test("%+#-5.3f", -7.3);}
int		flt_prec6n_5w_zpljafas(void){return test("%+#-5.6f", -7.3);}
//Floats with field width and spacepad,~
int		flt_prec0p_5wsp(void){return test("% 5.0f", 7.3);}
int		flt_prec1p_5wsp(void){return test("% 5.1f", 7.3);}
int		flt_prec3p_5wsp(void){return test("% 5.3f", 7.3);}
int		flt_prec6p_5wsp(void){return test("% 5.6f", 7.3);}
int		flt_prec0n_5wsp(void){return test("% 5.0f", -7.3);}
int		flt_prec1n_5wsp(void){return test("% 5.1f", -7.3);}
int		flt_prec3n_5wsp(void){return test("% 5.3f", -7.3);}
int		flt_prec6n_5wsp(void){return test("% 5.6f", -7.3);}
//Floats with field width and zero padding and spacepad,~
int		flt_prec0p_5w_zpsp(void){return test("% 05.0f", 7.3);}
int		flt_prec1p_5w_zpsp(void){return test("% 05.1f", 7.3);}
int		flt_prec3p_5w_zpsp(void){return test("% 05.3f", 7.3);}
int		flt_prec6p_5w_zpsp(void){return test("% 05.6f", 7.3);}
int		flt_prec0n_5w_zpsp(void){return test("% 05.0f", -7.3);}
int		flt_prec1n_5w_zpsp(void){return test("% 05.1f", -7.3);}
int		flt_prec3n_5w_zpsp(void){return test("% 05.3f", -7.3);}
int		flt_prec6n_5w_zpsp(void){return test("% 05.6f", -7.3);}
//Floats with field width and left justify and spacepad,~
int		flt_prec0p_5w_ljsp(void){return test("% -5.0f", 7.3);}
int		flt_prec1p_5w_ljsp(void){return test("% -5.1f", 7.3);}
int		flt_prec3p_5w_ljsp(void){return test("% -5.3f", 7.3);}
int		flt_prec6p_5w_ljsp(void){return test("% -5.6f", 7.3);}
int		flt_prec0n_5w_ljsp(void){return test("% -5.0f", -7.3);}
int		flt_prec1n_5w_ljsp(void){return test("% -5.1f", -7.3);}
int		flt_prec3n_5w_ljsp(void){return test("% -5.3f", -7.3);}
int		flt_prec6n_5w_ljsp(void){return test("% -5.6f", -7.3);}
//Floats with field width and zero padding and left justify and spacepad,~
int		flt_prec0p_5w_zpljsp(void){return test("% -05.0f", 7.3);}
int		flt_prec1p_5w_zpljsp(void){return test("% -05.1f", 7.3);}
int		flt_prec3p_5w_zpljsp(void){return test("% -05.3f", 7.3);}
int		flt_prec6p_5w_zpljsp(void){return test("% -05.6f", 7.3);}
int		flt_prec0n_5w_zpljsp(void){return test("% -05.0f", -7.3);}
int		flt_prec1n_5w_zpljsp(void){return test("% -05.1f", -7.3);}
int		flt_prec3n_5w_zpljsp(void){return test("% -05.3f", -7.3);}
int		flt_prec6n_5w_zpljsp(void){return test("% -05.6f", -7.3);}
//Floats with field width left justify, rev f order and spacepad,~
int		flt_prec0p_5w_zpljrsp(void){return test("%- 5.0f", 7.3);}
int		flt_prec1p_5w_zpljrsp(void){return test("%- 5.1f", 7.3);}
int		flt_prec3p_5w_zpljrsp(void){return test("%- 5.3f", 7.3);}
int		flt_prec6p_5w_zpljrsp(void){return test("%- 5.6f", 7.3);}
int		flt_prec0n_5w_zpljrsp(void){return test("%- 5.0f", -7.3);}
int		flt_prec1n_5w_zpljrsp(void){return test("%- 5.1f", -7.3);}
int		flt_prec3n_5w_zpljrsp(void){return test("%- 5.3f", -7.3);}
int		flt_prec6n_5w_zpljrsp(void){return test("%- 5.6f", -7.3);}
//Floats with field width and left justify and altform and spacepad,~
int		flt_prec0p_5w_zpljafsp(void){return test("% #-5.0f", 7.3);}
int		flt_prec1p_5w_zpljafsp(void){return test("% #-5.1f", 7.3);}
int		flt_prec3p_5w_zpljafsp(void){return test("% #-5.3f", 7.3);}
int		flt_prec6p_5w_zpljafsp(void){return test("% #-5.6f", 7.3);}
int		flt_prec0n_5w_zpljafsp(void){return test("% #-5.0f", -7.3);}
int		flt_prec1n_5w_zpljafsp(void){return test("% #-5.1f", -7.3);}
int		flt_prec3n_5w_zpljafsp(void){return test("% #-5.3f", -7.3);}
int		flt_prec6n_5w_zpljafsp(void){return test("% #-5.6f", -7.3);}
//Floats with allsign and spacepad,~
int		flt_prec0p_assp(void){return test("%+ .0f", 7.3);}
int		flt_prec1p_assp(void){return test("%+ .1f", 7.3);}
int		flt_prec3p_assp(void){return test("%+ .3f", 7.3);}
int		flt_prec6p_assp(void){return test("%+ .6f", 7.3);}
int		flt_prec0n_assp(void){return test("%+ .0f", -7.3);}
int		flt_prec1n_assp(void){return test("%+ .1f", -7.3);}
int		flt_prec3n_assp(void){return test("%+ .3f", -7.3);}
int		flt_prec6n_assp(void){return test("%+ .6f", -7.3);}
//Floats with allsign and spacepad and rev flag order,~
int		flt_prec0p_asspr(void){return test("% +.0f", 7.3);}
int		flt_prec1p_asspr(void){return test("% +.1f", 7.3);}
int		flt_prec3p_asspr(void){return test("% +.3f", 7.3);}
int		flt_prec6p_asspr(void){return test("% +.6f", 7.3);}
int		flt_prec0n_asspr(void){return test("% +.0f", -7.3);}
int		flt_prec1n_asspr(void){return test("% +.1f", -7.3);}
int		flt_prec3n_asspr(void){return test("% +.3f", -7.3);}
int		flt_prec6n_asspr(void){return test("% +.6f", -7.3);}
//Floats of special values
int		flt_inf(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%f", special);}
int		flt_ninf(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%f", special);}
int		flt_nan(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%f", special);}
int		flt_pzero(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%f", special);}
int		flt_nzero(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%f", special);}
int		flt_inf_6w(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%6f", special);}
int		flt_ninf_6w(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%6f", special);}
int		flt_nan_6w(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%6f", special);}
int		flt_pzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%6f", special);}
int		flt_nzero_6w(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%6f", special);}
int		flt_inf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%-6f", special);}
int		flt_ninf_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%-6f", special);}
int		flt_nan_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%-6f", special);}
int		flt_pzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%-6f", special);}
int		flt_nzero_6wlj(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%-6f", special);}
int		flt_inf_6was(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%+6f", special);}
int		flt_ninf_6was(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%+6f", special);}
int		flt_nan_6was(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%+6f", special);}
int		flt_pzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%+6f", special);}
int		flt_nzero_6was(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%+6f", special);}
int		flt_inf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%10.7f", special);}
int		flt_ninf_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%10.7f", special);}
int		flt_nan_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%10.7f", special);}
int		flt_pzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%10.7f", special);}
int		flt_nzero_10w_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%10.7f", special);}
int		flt_inf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("% .7f", special);}
int		flt_ninf_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("% .7f", special);}
int		flt_nan_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("% .7f", special);}
int		flt_pzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("% .7f", special);}
int		flt_nzero_sp_prec7(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("% .7f", special);}
int		flt_inf_sp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("% f", special);}
int		flt_ninf_sp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("% f", special);}
int		flt_nan_sp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("% f", special);}
int		flt_pzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("% f", special);}
int		flt_nzero_sp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("% f", special);}
int		flt_inf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_INF;
	return test("%06f", special);}
int		flt_ninf_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NINF;
	return test("%06f", special);}
int		flt_nan_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NAN;
	return test("%06f", special);}
int		flt_pzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_PZERO;
	return test("%06f", special);}
int		flt_nzero_6wzp(void){double special; *((unsigned long *)(&special)) = DBL_NZERO;
	return test("%06f", special);}

//Long Doubles - Basic
int		flt_ld_basic_1(void){return test("this %Lf float", 1.5l);}
int		flt_ld_basic_fltonly(void){return test("%Lf", 7.5l);}
int		flt_ld_basic_whole(void){return test("%Lf", 1.0l);}
int		flt_ld_basic_negative(void){return test("%Lf", -3.85l);}
int		flt_ld_basic_positive_3_3(void){return test("%Lf", 573.924l);}
int		flt_ld_basic_negative_3_3(void){return test("%Lf", -958.125l);}
int		flt_ld_basic_positive_smallfpart(void){return test("%Lf", 23.00041l);}
int		flt_ld_basic_positive_allsmall(void){return test("%Lf", 0.000039l);}
int		flt_ld_basic_negative_smallfpart(void){return test("%Lf", -7.00036l);}
int		flt_ld_basic_negative_allsmall(void){return test("%Lf", -0.00032l);}
int		flt_ld_dfprec_limits_allsmall_pos(void){return test("%Lf", 0.000001l);}
int		flt_ld_dfprec_limits_allsmall_neg(void){return test("%Lf", -0.000001l);}
int		flt_ld_dfprec_limits_smallfpart_pos(void){return test("%Lf", 9873.000001l);}
int		flt_ld_dfprec_limits_smallfpart_neg(void){return test("%Lf", -875.000001l);}
int		flt_ld_dfprec_limits_allbig_pos(void){return test("%Lf", 999.999999l);}
int		flt_ld_dfprec_limits_allbig_neg(void){return test("%Lf", -99.999999l);}
int		flt_ld_dfprec_limits_bigfpart_pos(void){return test("%Lf", 0.999999l);}
int		flt_ld_dfprec_limits_bigfpart_neg(void){return test("%Lf", -0.999999l);}
//Long Doubles - Rounding with default precision
int		flt_ld_rndd_pos(void){return test("%Lf", 23.375094499l);}
int		flt_ld_rndd_neg(void){return test("%Lf", -985.765426499l);}
int		flt_ld_rndu_pos(void){return test("%Lf", 0.08942555l);}
int		flt_ld_rndu_neg(void){return test("%Lf", -56.2012685l);}
int		flt_ld_rndu_multidigit_pos(void){return test("%Lf", 43.4399999l);}
int		flt_ld_rndu_multidigit_neg(void){return test("%Lf", -5.0299999l);}
int		flt_ld_rndd_multidigit_pos(void){return test("%Lf", 43.43999949l);}
int		flt_ld_rndd_multidigit_neg(void){return test("%Lf", -5.02999949l);}
int		flt_ld_rndd_wholnobump_pos(void){return test("%Lf", 1.99999949l);}
int		flt_ld_rndd_wholnobump_neg(void){return test("%Lf", -0.99999949l);}
int		flt_ld_rndu_bumpwhole_pos(void){return test("%Lf", 3.9999999l);}
int		flt_ld_rndu_bumpwhole_neg(void){return test("%Lf", -5.9999999l);}
//Long Doubles - Prec 7
int		flt_ld_prec7_1(void){return test("this %.7Lf float", 1.5l);}
int		flt_ld_prec7_fltonly(void){return test("%.7Lf", 7.5l);}
int		flt_ld_prec7_whole(void){return test("%.7Lf", 1.0l);}
int		flt_ld_prec7_negative(void){return test("%.7Lf", -3.85l);}
int		flt_ld_prec7_positive_3_3(void){return test("%.7Lf", 573.924l);}
int		flt_ld_prec7_negative_3_3(void){return test("%.7Lf", -958.125l);}
int		flt_ld_prec7_positive_smallfpart(void){return test("%.7Lf", 23.00041l);}
int		flt_ld_prec7_positive_allsmall(void){return test("%.7Lf", 0.0000039l);}
int		flt_ld_prec7_negative_smallfpart(void){return test("%.7Lf", -7.00036l);}
int		flt_ld_prec7_negative_allsmall(void){return test("%.7Lf", -0.000032l);}
int		flt_ld_prec7_limits_allsmall_pos(void){return test("%.7Lf", 0.0000001l);}
int		flt_ld_prec7_limits_allsmall_neg(void){return test("%.7Lf", -0.0000001l);}
int		flt_ld_prec7_limits_smallfpart_pos(void){return test("%.7Lf", 9873.000001l);}
int		flt_ld_prec7_limits_smallfpart_neg(void){return test("%.7Lf", -875.000001l);}
int		flt_ld_prec7_limits_allbig_pos(void){return test("%.7Lf", 999.9999999l);}
int		flt_ld_prec7_limits_allbig_neg(void){return test("%.7Lf", -99.9999999l);}
int		flt_ld_prec7_limits_bigfpart_pos(void){return test("%.7Lf", 0.999999l);}
int		flt_ld_prec7_limits_bigfpart_neg(void){return test("%.7Lf", -0.999999l);}
//Long Doubles - Prec 7 Rounding
int		flt_ld_prec7_rndd_pos(void){return test("%.7Lf", 23.375094499l);}
int		flt_ld_prec7_rndd_neg(void){return test("%.7Lf", -985.765426499l);}
int		flt_ld_prec7_rndu_pos(void){return test("%.7Lf", 0.0894255l);}
int		flt_ld_prec7_rndu_neg(void){return test("%.7Lf", -56.2012685l);}
int		flt_ld_prec7_rndu_multidigit_pos(void){return test("%.7Lf", 43.4399999l);}
int		flt_ld_prec7_rndu_multidigit_neg(void){return test("%.7Lf", -5.0299999l);}
int		flt_ld_prec7_rndd_multidigit_pos(void){return test("%.7Lf", 43.43999949l);}
int		flt_ld_prec7_rndd_multidigit_neg(void){return test("%.7Lf", -5.02999949l);}
int		flt_ld_prec7_rndd_wholnobump_pos(void){return test("%.7Lf", 1.99999949l);}
int		flt_ld_prec7_rndd_wholnobump_neg(void){return test("%.7Lf", -0.99999949l);}
int		flt_ld_prec7_rndu_bumpwhole_pos(void){return test("%.7Lf", 3.9999999l);}
//Long Doubles - Prec 8
int		flt_ld_prec8_1(void){return test("this %.8Lf float", 1.5l);}
int		flt_ld_prec8_fltonly(void){return test("%.8Lf", 7.5l);}
int		flt_ld_prec8_whole(void){return test("%.8Lf", 1.0l);}
int		flt_ld_prec8_negative(void){return test("%.8Lf", -3.85l);}
int		flt_ld_prec8_positive_3_3(void){return test("%.8Lf", 573.924l);}
int		flt_ld_prec8_negative_3_3(void){return test("%.8Lf", -958.125l);}
int		flt_ld_prec8_positive_smallfpart(void){return test("%.8Lf", 23.00041l);}
int		flt_ld_prec8_positive_allsmall(void){return test("%.8Lf", 0.00000039l);}
int		flt_ld_prec8_negative_smallfpart(void){return test("%.8Lf", -7.00036l);}
int		flt_ld_prec8_negative_allsmall(void){return test("%.8Lf", -0.0000032l);}
int		flt_ld_prec8_limits_allsmall_pos(void){return test("%.8Lf", 0.00000001l);}
int		flt_ld_prec8_limits_allsmall_neg(void){return test("%.8Lf", -0.00000001l);}
int		flt_ld_prec8_limits_smallfpart_pos(void){return test("%.8Lf", 9873.000001l);}
int		flt_ld_prec8_limits_smallfpart_neg(void){return test("%.8Lf", -875.000001l);}
int		flt_ld_prec8_limits_allbig_pos(void){return test("%.8Lf", 999.9999999l);}
int		flt_ld_prec8_limits_allbig_neg(void){return test("%.8Lf", -99.99999999l);}
int		flt_ld_prec8_limits_bigfpart_pos(void){return test("%.8Lf", 0.999999l);}
int		flt_ld_prec8_limits_bigfpart_neg(void){return test("%.8Lf", -0.999999l);}
//Long Doubles - Prec 8 Rounding
int		flt_ld_prec8_rndd_pos(void){return test("%.8Lf", 23.375094499l);}
int		flt_ld_prec8_rndd_neg(void){return test("%.8Lf", -985.765426499l);}
int		flt_ld_prec8_rndu_pos(void){return test("%.8Lf", 0.0894255l);}
int		flt_ld_prec8_rndu_neg(void){return test("%.8Lf", -56.2012685l);}
int		flt_ld_prec8_rndu_multidigit_pos(void){return test("%.8Lf", 43.4399999l);}
int		flt_ld_prec8_rndu_multidigit_neg(void){return test("%.8Lf", -5.0299999l);}
int		flt_ld_prec8_rndd_multidigit_pos(void){return test("%.8Lf", 43.43999949l);}
int		flt_ld_prec8_rndd_multidigit_neg(void){return test("%.8Lf", -5.02999949l);}
int		flt_ld_prec8_rndd_wholnobump_pos(void){return test("%.8Lf", 1.99999949l);}
int		flt_ld_prec8_rndd_wholnobump_neg(void){return test("%.8Lf", -0.99999949l);}
int		flt_ld_prec8_rndu_bumpwhole_pos(void){return test("%.8Lf", 3.9999999l);}
//Long Doubles - Prec 9
int		flt_ld_prec9_1(void){return test("this %.9Lf float", 1.5l);}
int		flt_ld_prec9_fltonly(void){return test("%.9Lf", 7.5l);}
int		flt_ld_prec9_whole(void){return test("%.9Lf", 1.0l);}
int		flt_ld_prec9_negative(void){return test("%.9Lf", -3.85l);}
int		flt_ld_prec9_positive_3_3(void){return test("%.9Lf", 573.924l);}
int		flt_ld_prec9_negative_3_3(void){return test("%.9Lf", -958.125l);}
int		flt_ld_prec9_positive_smallfpart(void){return test("%.9Lf", 23.00041l);}
int		flt_ld_prec9_positive_allsmall(void){return test("%.9Lf", 0.00000039l);}
int		flt_ld_prec9_negative_smallfpart(void){return test("%.9Lf", -7.00036l);}
int		flt_ld_prec9_negative_allsmall(void){return test("%.9Lf", -0.0000032l);}
int		flt_ld_prec9_limits_allsmall_pos(void){return test("%.9Lf", 0.00000001l);}
int		flt_ld_prec9_limits_allsmall_neg(void){return test("%.9Lf", -0.00000001l);}
int		flt_ld_prec9_limits_smallfpart_pos(void){return test("%.9Lf", 9873.000001l);}
int		flt_ld_prec9_limits_smallfpart_neg(void){return test("%.9Lf", -875.000001l);}
int		flt_ld_prec9_limits_allbig_pos(void){return test("%.9Lf", 999.99999999l);}
int		flt_ld_prec9_limits_allbig_neg(void){return test("%.9Lf", -99.99999999l);}
int		flt_ld_prec9_limits_bigfpart_pos(void){return test("%.9Lf", 0.999999l);}
int		flt_ld_prec9_limits_bigfpart_neg(void){return test("%.9Lf", -0.999999l);}
//Long Doubles - Prec 9 Rounding
int		flt_ld_prec9_rndd_pos(void){return test("%.9Lf", 23.375094499l);}
int		flt_ld_prec9_rndd_neg(void){return test("%.9Lf", -985.765426499l);}
int		flt_ld_prec9_rndu_pos(void){return test("%.9Lf", 0.0894255l);}
int		flt_ld_prec9_rndu_neg(void){return test("%.9Lf", -56.2012685l);}
int		flt_ld_prec9_rndu_multidigit_pos(void){return test("%.9Lf", 43.4399999l);}
int		flt_ld_prec9_rndu_multidigit_neg(void){return test("%.9Lf", -5.0299999l);}
int		flt_ld_prec9_rndd_multidigit_pos(void){return test("%.9Lf", 43.43999949l);}
int		flt_ld_prec9_rndd_multidigit_neg(void){return test("%.9Lf", -5.02999949l);}
int		flt_ld_prec9_rndd_wholnobump_pos(void){return test("%.9Lf", 1.99999949l);}
int		flt_ld_prec9_rndd_wholnobump_neg(void){return test("%.9Lf", -0.99999949l);}
int		flt_ld_prec9_rndu_bumpwhole_pos(void){return test("%.9Lf", 3.9999999l);}
//Long Doubles - Prec 10
int		flt_ld_prec10_1(void){return test("this %.10Lf float", 1.5l);}
int		flt_ld_prec10_fltonly(void){return test("%.10Lf", 7.5l);}
int		flt_ld_prec10_whole(void){return test("%.10Lf", 1.0l);}
int		flt_ld_prec10_negative(void){return test("%.10Lf", -3.85l);}
int		flt_ld_prec10_positive_3_10(void){return test("%.10Lf", 573.924l);}
int		flt_ld_prec10_negative_3_10(void){return test("%.10Lf", -958.125l);}
int		flt_ld_prec10_pos(void){return test("%.10Lf", 23.8341375094l);}
int		flt_ld_prec10_neg(void){return test("%.10Lf", -985.2459765426l);}
int		flt_ld_prec10_rndd_pos(void){return test("%.10Lf", 23.8341375094499l);}
int		flt_ld_prec10_rndd_neg(void){return test("%.10Lf", -985.2459765426499l);}
int		flt_ld_prec10_rndu_pos(void){return test("%.10Lf", 0.87650894255l);}
int		flt_ld_prec10_rndu_neg(void){return test("%.10Lf", -56.47852012685l);}
int		flt_ld_prec10_positive_smallfpart(void){return test("%.10Lf", 23.000000041l);}
int		flt_ld_prec10_positive_allsmall(void){return test("%.10Lf", 0.0000000039l);}
int		flt_ld_prec10_negative_smallfpart(void){return test("%.10Lf", -7.000000036l);}
int		flt_ld_prec10_negative_allsmall(void){return test("%.10Lf", -0.000000032l);}
int		flt_ld_prec10_limits_allsmall_pos(void){return test("%.10Lf", 0.0000000001l);}
int		flt_ld_prec10_limits_allsmall_neg(void){return test("%.10Lf", -0.0000000001l);}
int		flt_ld_prec10_limits_smallfpart_pos(void){return test("%.10Lf", 9873.0000000001l);}
int		flt_ld_prec10_limits_smallfpart_neg(void){return test("%.10Lf", -875.0000000001l);}
int		flt_ld_prec10_limits_allbig_pos(void){return test("%.10Lf", 999.9999999999l);}
int		flt_ld_prec10_limits_allbig_neg(void){return test("%.10Lf", -99.9999999999l);}
int		flt_ld_prec10_limits_bigfpart_pos(void){return test("%.10Lf", 0.9999999999l);}
int		flt_ld_prec10_limits_bigfpart_neg(void){return test("%.10Lf", -0.9999999999l);}
//Long Doubles - Prec 12
int		flt_ld_prec12_rndu(void){return test("%.12f",        1.025978542436587568678);}
int		flt_ld_prec12_rndd(void){return test("%.12f",        1.025978548534310421434);}
int		flt_ld_prec12_limits_tiny(void){return test("%.12f", 0.000000000001000000000);}
int		flt_ld_prec12_limits_big(void){return test("%.12f",  0.999999999999000000000);}
//Long Doubles - Prec 14
int		flt_ld_prec14_rndu(void){return test("%.14f",        1.025978542436587568678);}
int		flt_ld_prec14_rndd(void){return test("%.14f",        1.025978548534310421434);}
int		flt_ld_prec14_limits_tiny(void){return test("%.14f", 0.000000000000010000000);}
int		flt_ld_prec14_limits_big(void){return test("%.14f",  0.999999999999990000000);}
//Long Doubles - Prec 16
int		flt_ld_prec16_rndu(void){return test("%.16f",        1.025978542436587568678);}
int		flt_ld_prec16_rndd(void){return test("%.16f",        1.025978548534310421634);}
int		flt_ld_prec16_limits_tiny(void){return test("%.16f", 0.000000000000000100000);}
int		flt_ld_prec16_limits_big(void){return test("%.16f",  0.999999999999999900000);}
//Long Doubles - Prec 17
int		flt_ld_prec17_rndu(void){return test("%.17f",        1.025978542436587568678);}
int		flt_ld_prec17_rndd(void){return test("%.17f",        1.025978548534310421734);}
int		flt_ld_prec17_limits_tiny(void){return test("%.17f", 0.000000000000000010000);}
int		flt_ld_prec17_limits_big(void){return test("%.17f",  0.999999999999999990000);}
//Long Doubles - Prec 18
int		flt_ld_prec18_rndu(void){return test("%.18f",        1.025978542436587568678);}
int		flt_ld_prec18_rndd(void){return test("%.18f",        1.025978548534310421834);}
int		flt_ld_prec18_limits_tiny(void){return test("%.18f", 0.000000000000000001000);}
int		flt_ld_prec18_limits_big(void){return test("%.18f",  0.999999999999999999000);}
//Long Doubles - Prec 19
int		flt_ld_prec19_rndu(void){return test("%.19f",        1.025978542436587568678);}
int		flt_ld_prec19_rndd(void){return test("%.19f",        1.025978548534310421934);}
int		flt_ld_prec19_limits_tiny(void){return test("%.19f", 0.000000000000000000100);}
int		flt_ld_prec19_limits_big(void){return test("%.19f",  0.999999999999999999900);}
//Long Doubles - Prec 20
int		flt_ld_prec20_rndu(void){return test("%.20f",        1.025978542436587568678);}
int		flt_ld_prec20_rndd(void){return test("%.20f",        1.025978548534310422034);}
int		flt_ld_prec20_limits_tiny(void){return test("%.20f", 0.000000000000000000010);}
int		flt_ld_prec20_limits_big(void){return test("%.20f",  0.999999999999999999990);}
//Long Doubles of special values
int		fltl_inf(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%Lf", special);}
int		fltl_ninf(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%Lf", special);}
int		fltl_nan(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%Lf", special);}
int		fltl_pzero(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%Lf", special);}
int		fltl_nzero(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%Lf", special);}
int		fltl_inf_6w(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%6Lf", special);}
int		fltl_ninf_6w(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%6Lf", special);}
int		fltl_nan_6w(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%6Lf", special);}
int		fltl_pzero_6w(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%6Lf", special);}
int		fltl_nzero_6w(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%6Lf", special);}
int		fltl_inf_6wlj(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%-6Lf", special);}
int		fltl_ninf_6wlj(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%-6Lf", special);}
int		fltl_nan_6wlj(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%-6Lf", special);}
int		fltl_pzero_6wlj(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%-6Lf", special);}
int		fltl_nzero_6wlj(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%-6Lf", special);}
int		fltl_inf_6was(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%+6Lf", special);}
int		fltl_ninf_6was(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%+6Lf", special);}
int		fltl_nan_6was(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%+6Lf", special);}
int		fltl_pzero_6was(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%+6Lf", special);}
int		fltl_nzero_6was(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%+6Lf", special);}
int		fltl_inf_10w_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%10.7Lf", special);}
int		fltl_ninf_10w_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%10.7Lf", special);}
int		fltl_nan_10w_prec7(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%10.7Lf", special);}
int		fltl_pzero_10w_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%10.7Lf", special);}
int		fltl_nzero_10w_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%10.7Lf", special);}
int		fltl_inf_sp_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;  FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("% .7Lf", special);}
int		fltl_ninf_sp_prec7(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("% .7Lf", special);}
int		fltl_nan_sp_prec7(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("% .7Lf", special);}
int		fltl_pzero_sp_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("% .7Lf", special);}
int		fltl_nzero_sp_prec7(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("% .7Lf", special);}
int		fltl_inf_sp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("% Lf", special);}
int		fltl_ninf_sp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("% Lf", special);}
int		fltl_nan_sp(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("% Lf", special);}
int		fltl_pzero_sp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("% Lf", special);}
int		fltl_nzero_sp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("% Lf", special);}
int		fltl_inf_6wzp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF; FTPF_LDBL_BYTE5(special) = 0x7FFF;
	return test("%06Lf", special);}
int		fltl_ninf_6wzp(void){long double special; *((unsigned long *)(&special)) = FTPF_LDBL_INF;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%06Lf", special);}
int		fltl_nan_6wzp(void){long double special; *((unsigned long *)(&special)) = 8ull;FTPF_LDBL_BYTE5(special) = 0xFFFF;
	return test("%06Lf", special);}
int		fltl_pzero_6wzp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%06Lf", special);}
int		fltl_nzero_6wzp(void){long double special; *((unsigned long *)(&special)) = 0ull;FTPF_LDBL_BYTE5(special) = 0;
	return test("%06Lf", special);}
//Memory Expansion

int		mem_4bytes_basic(void){
	unsigned int num = 0x12345678;
	char *str; ft_asprintf(&str, "%m", &num);
	int ret = assert_str(str, "78563412");
	free(str); return (ret);}

int		mem_4bytes_prec3_10w(void){
	unsigned int num = 0x12345678;
	char *str; ft_asprintf(&str, "%10.3m", &num);
	int ret = assert_str(str, "    785634");
	free(str); return (ret);}

int		mem_8bytes_l_sp(void){
	unsigned long num = 0x123456789abcde67;
	char *str; ft_asprintf(&str, "% lm", &num);
	int ret = assert_str(str, "67de bc9a 7856 3412");
	free(str); return (ret);}

int		mem_str_basic(void){
	char *s1 = "Hello, World!";
	char *str; ft_asprintf(&str, "Crazy %.13m Train", s1);
	int ret = assert_str(str, "Crazy 48656c6c6f2c20576f726c6421 Train");
	free(str); return (ret);}

int		mem_str_altform_15w_lj(void){
	char *s1 = "Hello, World!";
	char *str; ft_asprintf(&str, "%#-15.13mI am groot.", s1);
	int ret = assert_str(str, "Hello, World!  I am groot.");
	free(str); return (ret);}

int		mem_str_altform_15w_lj_np(void){
	char *s1 = "Hello,\nWorld!";
	char *str; ft_asprintf(&str, "%#-15.13mI am groot.", s1);
	int ret = assert_str(str, "Hello,.World!  I am groot.");
	free(str); return (ret);}

//Binary Expansion

int		bin_4bytes_basic(void){
	unsigned int num = 0x12345678;
	char *str; ft_asprintf(&str, "%b", &num);
	int ret = assert_str(str, "00010010001101000101011001111000");
	free(str); return (ret);}

int		bin_4bytes_prec3_27w(void){
	unsigned int num = 0x12345678;
	char *str; ft_asprintf(&str, "%27.3b", &num);
	int ret = assert_str(str, "   001101000101011001111000");
	free(str); return (ret);}

int		bin_4bytes_prec3_27w_lj(void){
	unsigned int num = 0x12345678;
	char *str; ft_asprintf(&str, "%-27.3b", &num);
	int ret = assert_str(str, "001101000101011001111000   ");
	free(str); return (ret);}

int		bin_8bytes_l_af(void){
	unsigned long num = 0x1234567891234567;
	char *str; ft_asprintf(&str, "%#lb", &num);
	int ret = assert_str(str, "0001.0010.0011.0100.0101.0110.0111.1000.1001.0001.0010.0011.0100.0101.0110.0111");
	free(str); return (ret);}

/*
//ftbi big integers

 int	ftbi_basic_pos(void) {
	t_ftbi *bi = ftbi_new_str("463748564628465637395847");
	char *str; ft_asprintf(&str, "hello %Bi world", bi);
	int ret = assert_str(str, "hello 463748564628465637395847 world");
	ftbi_del(&bi); free(str); return (ret);}

 int	ftbi_zero_pos(void) {
	t_ftbi *bi = ftbi_new_llong(0);
	char *str; ft_asprintf(&str, "hello %Bi world", bi);
	int ret = assert_str(str, "hello 0 world");
	ftbi_del(&bi); free(str); return (ret);}

 int	ftbi_basic_neg(void) {
	t_ftbi *bi = ftbi_new_str("-463748564628465637395847");
	char *str; ft_asprintf(&str, "hello %Bi world", bi);
	int ret = assert_str(str, "hello -463748564628465637395847 world");
	ftbi_del(&bi); free(str); return (ret);}

 int	ftbi_width(void) {
	t_ftbi *bi = ftbi_new_str("-463748564628465637395847");
	char *str; ft_asprintf(&str, "hello %30Bi world", bi);
	int ret = assert_str(str, "hello      -463748564628465637395847 world");
	ftbi_del(&bi); free(str); return (ret);}

 int	ftbi_width_lj(void) {
	t_ftbi *bi = ftbi_new_str("-463748564628465637395847");
	char *str; ft_asprintf(&str, "hello %-30Bi world", bi);
	int ret = assert_str(str, "hello -463748564628465637395847      world");
	ftbi_del(&bi); free(str); return (ret);}

 int	ftbi_width_zpad(void) {
	t_ftbi *bi = ftbi_new_str("-463748564628465637395847");
	char *str; ft_asprintf(&str, "hello %30Bi world", bi);
	int ret = assert_str(str, "hello -00000463748564628465637395847 world");
	ftbi_del(&bi); free(str); return (ret);}

 int	ftbi_allsign(void) {
	t_ftbi *bi = ftbi_new_str("463748564628465637395847");
	char *str; ft_asprintf(&str, "hello %+Bi world", bi);
	int ret = assert_str(str, "hello +463748564628465637395847 world");
	ftbi_del(&bi); free(str); return (ret);}

 int	ftbi_space(void) {
	t_ftbi *bi = ftbi_new_str("463748564628465637395847");
	char *str; ft_asprintf(&str, "hello % Bi world", bi);
	int ret = assert_str(str, "hello  463748564628465637395847 world");
	ftbi_del(&bi); free(str); return (ret);}

 int	ftbi_width_prec(void) {
	t_ftbi *bi = ftbi_new_str("463748564628465637395847");
	char *str; ft_asprintf(&str, "hello %32.27Bi world", bi);
	int ret = assert_str(str, "hello      00463748564628465637395847 world");
	ftbi_del(&bi); free(str); return (ret);}

/ *
** -----------------------------------------------------------------------------
**                     ftbf : general construction and tostr
** -----------------------------------------------------------------------------
* /

 int ftbf_general_simple(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_str("15");
	f->val->neg = 0;
	f->special = FTBF_NORMAL;
	f->exp = -1;
	char *str; ft_asprintf(&str, "hello [%Bf] world");
	int ret = assert_str(str, "hello [1.5] world");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_general_negexp(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_str("15");
	f->val->neg = 0;
	f->special = FTBF_NORMAL;
	f->exp = -2;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "0.15");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_general_negexp_negative(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_str("15");
	f->val->neg = 1;
	f->special = FTBF_NORMAL;
	f->exp = -2;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "-0.15");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_general_big(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_str("726387");
	f->val->neg = 0;
	f->special = FTBF_NORMAL;
	f->exp = -3;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "726.387");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_general_small(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_str("72");
	f->val->neg = 0;
	f->special = FTBF_NORMAL;
	f->exp = -5;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "0.00072");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_general_exp_gt_len(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_str("72");
	f->val->neg = 0;
	f->special = FTBF_NORMAL;
	f->exp = 5;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "7200000");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_ultimate_1(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_str("72816506716406411350341341354035174746516506816746516516816841674313503540351651032035403581");
	f->val->neg = 0;
	f->special = FTBF_NORMAL;
	f->exp = -70;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "7281650671640641135034.1341354035174746516506816746516516816841674313503540351651032035403581");
	ftbf_del(&f); free(str); return (ret);}

/ *
** -----------------------------------------------------------------------------
**                        ftbf : special values to string
** -----------------------------------------------------------------------------
* /

 int ftbf_posinf_tostr(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_llong(0);
	f->val->neg = 0;
	f->special = FTBF_POSINF;
	f->exp = 0;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "inf");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_neginf_tostr(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_llong(0);
	f->val->neg = 0;
	f->special = FTBF_NEGINF;
	f->exp = 0;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "-inf");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_nan_tostr(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_llong(0);
	f->val->neg = 0;
	f->special = FTBF_NAN;
	f->exp = 0;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "nan");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_poszero_tostr(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_llong(0);
	f->val->neg = 0;
	f->special = FTBF_POSZERO;
	f->exp = 0;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "0");
	ftbf_del(&f); free(str); return (ret);}

 int ftbf_negzero_tostr(void)
{
	t_ftbf *f = (t_ftbf *)malloc(sizeof(t_ftbf));
	f->val = ftbi_new_llong(0);
	f->val->neg = 1;
	f->special = FTBF_NEGZERO;
	f->exp = 0;
	char *str; ft_asprintf(&str, "%Bf", f);
	int ret = assert_str(str, "-0");
	ftbf_del(&f); free(str); return (ret);}
*/
//Arbitrary argument numbers

int		argnum_simple_swap(void){return test("%2$s, %1$s!", "world", "hello");}
int		argnum_swap_strfloat(void){return test("%2$f, %1$s!", "world", 5.75);}
int		argnum_swap_floatstr(void){return test("%2$s, %1$f!", 5.75, "abc");}
int		argnum_loopback(void){return test("%i %i %1$i %i %i", 1, 2, 3);}
int		argnum_onlyone(void){return test("%1$s %1$s %1$s %1$s %1$s %1$s %1$s %1$s.", "buffalo");}
int		argnum_start2thentofloatthen1(void){return test("%2$s %f %1$i", 5, "abc", 5.75f);}
int		argnum_ultimate_1(void){return test("%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s", 5, "abc", 5.75);}
int		argnum_ultimate_2(void){return test("%4$.5s %.4i %lli %1$Lf %c %7$20.6s %5$i %2$c %1$.2Lf %c %i",
			5.75l, 'c', -17, "Atlanta, GA", 54, 9879879879879ll, "baby shark");}

//Mix tests
unsigned int		mx_u = 235;
long double			mx_Lf = 0.375l;
double				mx_f = 0.625;
long				mx_li =  4223372036854775800;
long long			mx_lli = 3223372036654775200;
char				mx_c = 'G';
short				mx_hi = -3244;
char				mx_hhi = 'F';
char			   *mx_s = "Hello, World!";
int					mx_i = 42;

int		mix_test_0(void){return test(
			"  %hi    %u    %lli    %f    %li    %X  ",
			mx_hi, mx_u, mx_lli, mx_f, mx_li, mx_u);}
int		mix_test_1(void){return test(
			"  %hhi    %c    %f    %Lf    %lli    %i  ",
			mx_c, mx_c, mx_f, mx_Lf, mx_lli, mx_i);}
int		mix_test_2(void){return test(
			"  %Lf    %c    %hi    %i    %lli    %x  ",
			mx_Lf, mx_c, mx_hi, mx_i, mx_lli, mx_u);}
int		mix_test_3(void){return test(
			"  %x    %li    %p    %lli    %s    %u  ",
			mx_u, mx_li, &mx_i, mx_lli, mx_s, mx_u);}
int		mix_test_4(void){return test(
			"  %Lf    %X    %lli    %c    %x    %o  ",
			mx_Lf, mx_u, mx_lli, mx_c, mx_u, mx_u);}
int		mix_test_5(void){return test(
			"  %o    %i    %s    %hhi    %lli    %p  ",
			mx_u, mx_i, mx_s, mx_c, mx_lli, &mx_i);}
int		mix_test_6(void){return test(
			"  %i    %f    %p    %o    %s    %Lf  ",
			mx_i, mx_f, &mx_i, mx_u, mx_s, mx_Lf);}
int		mix_test_7(void){return test(
			"  %X    %f    %lli    %u    %x    %c  ",
			mx_u, mx_f, mx_lli, mx_u, mx_u, mx_c);}
int		mix_test_8(void){return test(
			"  %s    %p    %x    %hi    %f    %X  ",
			mx_s, &mx_i, mx_u, mx_hi, mx_f, mx_u);}
int		mix_test_9(void){return test(
			"  %li    %p    %lli    %f    %X    %i  ",
			mx_li, &mx_i, mx_lli, mx_f, mx_u, mx_i);}
int		mix_test_10(void){return test(
			"  %i    %p    %Lf    %f    %X    %o  ",
			mx_i, &mx_i, mx_Lf, mx_f, mx_u, mx_u);}
int		mix_test_11(void){return test(
			"  %o    %p    %s    %hi    %u    %x  ",
			mx_u, &mx_i, mx_s, mx_hi, mx_u, mx_u);}
int		mix_test_12(void){return test(
			"  %X    %hi    %f    %x    %s    %o  ",
			mx_u, mx_hi, mx_f, mx_u, mx_s, mx_u);}
int		mix_test_13(void){return test(
			"  %hi    %li    %Lf    %s    %i    %x  ",
			mx_hi, mx_li, mx_Lf, mx_s, mx_i, mx_u);}
int		mix_test_14(void){return test(
			"  %lli    %i    %hi    %Lf    %f    %hhi  ",
			mx_lli, mx_i, mx_hi, mx_Lf, mx_f, mx_c);}
int		mix_test_15(void){return test(
			"  %o    %li    %x    %f    %Lf    %hhi  ",
			mx_u, mx_li, mx_u, mx_f, mx_Lf, mx_c);}
int		mix_test_16(void){return test(
			"  %X    %Lf    %li    %x    %c    %u  ",
			mx_u, mx_Lf, mx_li, mx_u, mx_c, mx_u);}
int		mix_test_17(void){return test(
			"  %u    %c    %f    %i    %Lf    %li  ",
			mx_u, mx_c, mx_f, mx_i, mx_Lf, mx_li);}
int		mix_test_18(void){return test(
			"  %p    %f    %hhi    %hi    %s    %lli  ",
			&mx_i, mx_f, mx_c, mx_hi, mx_s, mx_lli);}
int		mix_test_19(void){return test(
			"  %hi    %lli    %i    %o    %u    %X  ",
			mx_hi, mx_lli, mx_i, mx_u, mx_u, mx_u);}
int		mix_test_20(void){return test(
			"  %c    %lli    %i    %hi    %u    %o  ",
			mx_c, mx_lli, mx_i, mx_hi, mx_u, mx_u);}
int		mix_test_21(void){return test(
			"  %hhi    %u    %Lf    %o    %s    %X  ",
			mx_c, mx_u, mx_Lf, mx_u, mx_s, mx_u);}
int		mix_test_22(void){return test(
			"  %Lf    %c    %i    %hi    %x    %hhi  ",
			mx_Lf, mx_c, mx_i, mx_hi, mx_u, mx_c);}
int		mix_test_23(void){return test(
			"  %o    %i    %li    %u    %c    %s  ",
			mx_u, mx_i, mx_li, mx_u, mx_c, mx_s);}
int		mix_test_24(void){return test(
			"  %s    %c    %u    %lli    %i    %o  ",
			mx_s, mx_c, mx_u, mx_lli, mx_i, mx_u);}
int		mix_test_25(void){return test(
			"  %c    %hi    %Lf    %f    %s    %p  ",
			mx_c, mx_hi, mx_Lf, mx_f, mx_s, &mx_i);}
int		mix_test_26(void){return test(
			"  %x    %X    %lli    %c    %f    %hi  ",
			mx_u, mx_u, mx_lli, mx_c, mx_f, mx_hi);}
int		mix_test_27(void){return test(
			"  %li    %o    %hi    %X    %Lf    %hhi  ",
			mx_li, mx_u, mx_hi, mx_u, mx_Lf, mx_c);}
int		mix_test_28(void){return test(
			"  %lli    %s    %x    %o    %u    %i  ",
			mx_lli, mx_s, mx_u, mx_u, mx_u, mx_i);}
int		mix_test_29(void){return test(
			"  %i    %c    %o    %X    %u    %Lf  ",
			mx_i, mx_c, mx_u, mx_u, mx_u, mx_Lf);}
int		mix_test_30(void){return test(
			"  %c    %s    %x    %p    %X    %o  ",
			mx_c, mx_s, mx_u, &mx_i, mx_u, mx_u);}
int		mix_test_31(void){return test(
			"  %hhi    %Lf    %f    %x    %p    %c  ",
			mx_c, mx_Lf, mx_f, mx_u, &mx_i, mx_c);}
int		mix_test_32(void){return test(
			"  %i    %hi    %li    %f    %o    %hhi  ",
			mx_i, mx_hi, mx_li, mx_f, mx_u, mx_c);}
int		mix_test_33(void){return test(
			"  %c    %s    %hi    %lli    %li    %hhi  ",
			mx_c, mx_s, mx_hi, mx_lli, mx_li, mx_c);}
int		mix_test_34(void){return test(
			"  %u    %li    %o    %x    %hhi    %f  ",
			mx_u, mx_li, mx_u, mx_u, mx_c, mx_f);}
int		mix_test_35(void){return test(
			"  %s    %li    %o    %x    %X    %p  ",
			mx_s, mx_li, mx_u, mx_u, mx_u, &mx_i);}
int		mix_test_36(void){return test(
			"  %li    %o    %x    %lli    %i    %X  ",
			mx_li, mx_u, mx_u, mx_lli, mx_i, mx_u);}
int		mix_test_37(void){return test(
			"  %x    %c    %i    %f    %lli    %li  ",
			mx_u, mx_c, mx_i, mx_f, mx_lli, mx_li);}
int		mix_test_38(void){return test(
			"  %hi    %c    %x    %X    %i    %li  ",
			mx_hi, mx_c, mx_u, mx_u, mx_i, mx_li);}
int		mix_test_39(void){return test(
			"  %u    %o    %X    %Lf    %hhi    %i  ",
			mx_u, mx_u, mx_u, mx_Lf, mx_c, mx_i);}
int		mix_test_40(void){return test(
			"  %f    %p    %hi    %i    %hhi    %u  ",
			mx_f, &mx_i, mx_hi, mx_i, mx_c, mx_u);}
int		mix_test_41(void){return test(
			"  %u    %f    %c    %X    %lli    %o  ",
			mx_u, mx_f, mx_c, mx_u, mx_lli, mx_u);}
int		mix_test_42(void){return test(
			"  %hi    %X    %p    %f    %u    %i  ",
			mx_hi, mx_u, &mx_i, mx_f, mx_u, mx_i);}
int		mix_test_43(void){return test(
			"  %lli    %hi    %o    %hhi    %f    %x  ",
			mx_lli, mx_hi, mx_u, mx_c, mx_f, mx_u);}
int		mix_test_44(void){return test(
			"  %hhi    %i    %Lf    %li    %p    %c  ",
			mx_c, mx_i, mx_Lf, mx_li, &mx_i, mx_c);}
int		mix_test_45(void){return test(
			"  %s    %p    %hi    %i    %hhi    %X  ",
			mx_s, &mx_i, mx_hi, mx_i, mx_c, mx_u);}
int		mix_test_46(void){return test(
			"  %X    %u    %o    %p    %lli    %li  ",
			mx_u, mx_u, mx_u, &mx_i, mx_lli, mx_li);}
int		mix_test_47(void){return test(
			"  %c    %X    %p    %s    %li    %f  ",
			mx_c, mx_u, &mx_i, mx_s, mx_li, mx_f);}
int		mix_test_48(void){return test(
			"  %x    %Lf    %hhi    %li    %lli    %X  ",
			mx_u, mx_Lf, mx_c, mx_li, mx_lli, mx_u);}
int		mix_test_49(void){return test(
			"  %i    %lli    %u    %Lf    %li    %hi  ",
			mx_i, mx_lli, mx_u, mx_Lf, mx_li, mx_hi);}
int		mix_test_50(void){return test(
			"  %lli    %li    %f    %X    %p    %hi  ",
			mx_lli, mx_li, mx_f, mx_u, &mx_i, mx_hi);}
int		mix_test_51(void){return test(
			"  %o    %p    %i    %x    %f    %li  ",
			mx_u, &mx_i, mx_i, mx_u, mx_f, mx_li);}
int		mix_test_52(void){return test(
			"  %X    %Lf    %p    %f    %i    %o  ",
			mx_u, mx_Lf, &mx_i, mx_f, mx_i, mx_u);}
int		mix_test_53(void){return test(
			"  %X    %u    %o    %hi    %p    %f  ",
			mx_u, mx_u, mx_u, mx_hi, &mx_i, mx_f);}
int		mix_test_54(void){return test(
			"  %li    %X    %lli    %i    %c    %s  ",
			mx_li, mx_u, mx_lli, mx_i, mx_c, mx_s);}
int		mix_test_55(void){return test(
			"  %o    %u    %p    %hi    %c    %f  ",
			mx_u, mx_u, &mx_i, mx_hi, mx_c, mx_f);}
int		mix_test_56(void){return test(
			"  %o    %u    %c    %p    %li    %hhi  ",
			mx_u, mx_u, mx_c, &mx_i, mx_li, mx_c);}
int		mix_test_57(void){return test(
			"  %i    %X    %p    %c    %Lf    %x  ",
			mx_i, mx_u, &mx_i, mx_c, mx_Lf, mx_u);}
int		mix_test_58(void){return test(
			"  %u    %p    %X    %lli    %f    %Lf  ",
			mx_u, &mx_i, mx_u, mx_lli, mx_f, mx_Lf);}
int		mix_test_59(void){return test(
			"  %c    %Lf    %lli    %f    %hi    %i  ",
			mx_c, mx_Lf, mx_lli, mx_f, mx_hi, mx_i);}
int		mix_test_60(void){return test(
			"  %f    %hhi    %x    %li    %hi    %Lf  ",
			mx_f, mx_c, mx_u, mx_li, mx_hi, mx_Lf);}
int		mix_test_61(void){return test(
			"  %s    %u    %o    %X    %li    %Lf  ",
			mx_s, mx_u, mx_u, mx_u, mx_li, mx_Lf);}
int		mix_test_62(void){return test(
			"  %f    %Lf    %c    %hhi    %i    %li  ",
			mx_f, mx_Lf, mx_c, mx_c, mx_i, mx_li);}
int		mix_test_63(void){return test(
			"  %x    %s    %Lf    %hi    %li    %p  ",
			mx_u, mx_s, mx_Lf, mx_hi, mx_li, &mx_i);}
int		mix_test_64(void){return test(
			"  %u    %hi    %p    %s    %hhi    %Lf  ",
			mx_u, mx_hi, &mx_i, mx_s, mx_c, mx_Lf);}
int		mix_test_65(void){return test(
			"  %hi    %Lf    %c    %x    %li    %p  ",
			mx_hi, mx_Lf, mx_c, mx_u, mx_li, &mx_i);}
int		mix_test_66(void){return test(
			"  %hi    %s    %o    %p    %lli    %X  ",
			mx_hi, mx_s, mx_u, &mx_i, mx_lli, mx_u);}
int		mix_test_67(void){return test(
			"  %s    %lli    %li    %f    %Lf    %c  ",
			mx_s, mx_lli, mx_li, mx_f, mx_Lf, mx_c);}
int		mix_test_68(void){return test(
			"  %i    %c    %f    %hhi    %X    %lli  ",
			mx_i, mx_c, mx_f, mx_c, mx_u, mx_lli);}
int		mix_test_69(void){return test(
			"  %i    %li    %x    %f    %hi    %Lf  ",
			mx_i, mx_li, mx_u, mx_f, mx_hi, mx_Lf);}
int		mix_test_70(void){return test(
			"  %lli    %o    %x    %c    %hhi    %i  ",
			mx_lli, mx_u, mx_u, mx_c, mx_c, mx_i);}
int		mix_test_71(void){return test(
			"  %o    %li    %hhi    %lli    %s    %c  ",
			mx_u, mx_li, mx_c, mx_lli, mx_s, mx_c);}
int		mix_test_72(void){return test(
			"  %Lf    %hhi    %c    %s    %i    %x  ",
			mx_Lf, mx_c, mx_c, mx_s, mx_i, mx_u);}
int		mix_test_73(void){return test(
			"  %o    %Lf    %li    %i    %x    %hi  ",
			mx_u, mx_Lf, mx_li, mx_i, mx_u, mx_hi);}
int		mix_test_74(void){return test(
			"  %li    %X    %o    %i    %Lf    %lli  ",
			mx_li, mx_u, mx_u, mx_i, mx_Lf, mx_lli);}
int		mix_test_75(void){return test(
			"  %hi    %p    %X    %li    %hhi    %lli  ",
			mx_hi, &mx_i, mx_u, mx_li, mx_c, mx_lli);}
int		mix_test_76(void){return test(
			"  %i    %s    %p    %X    %c    %lli  ",
			mx_i, mx_s, &mx_i, mx_u, mx_c, mx_lli);}
int		mix_test_77(void){return test(
			"  %i    %o    %hhi    %c    %li    %Lf  ",
			mx_i, mx_u, mx_c, mx_c, mx_li, mx_Lf);}
int		mix_test_78(void){return test(
			"  %hhi    %hi    %li    %lli    %Lf    %p  ",
			mx_c, mx_hi, mx_li, mx_lli, mx_Lf, &mx_i);}
int		mix_test_79(void){return test(
			"  %X    %o    %f    %li    %hi    %i  ",
			mx_u, mx_u, mx_f, mx_li, mx_hi, mx_i);}
int		mix_test_80(void){return test(
			"  %c    %f    %o    %x    %Lf    %lli  ",
			mx_c, mx_f, mx_u, mx_u, mx_Lf, mx_lli);}
int		mix_test_81(void){return test(
			"  %li    %o    %hi    %p    %u    %Lf  ",
			mx_li, mx_u, mx_hi, &mx_i, mx_u, mx_Lf);}
int		mix_test_82(void){return test(
			"  %p    %hhi    %hi    %u    %x    %f  ",
			&mx_i, mx_c, mx_hi, mx_u, mx_u, mx_f);}
int		mix_test_83(void){return test(
			"  %hhi    %li    %Lf    %c    %u    %i  ",
			mx_c, mx_li, mx_Lf, mx_c, mx_u, mx_i);}
int		mix_test_84(void){return test(
			"  %X    %hhi    %i    %c    %Lf    %p  ",
			mx_u, mx_c, mx_i, mx_c, mx_Lf, &mx_i);}
int		mix_test_85(void){return test(
			"  %hi    %p    %i    %c    %f    %o  ",
			mx_hi, &mx_i, mx_i, mx_c, mx_f, mx_u);}
int		mix_test_86(void){return test(
			"  %u    %f    %hi    %o    %i    %lli  ",
			mx_u, mx_f, mx_hi, mx_u, mx_i, mx_lli);}
int		mix_test_87(void){return test(
			"  %li    %f    %hhi    %u    %x    %p  ",
			mx_li, mx_f, mx_c, mx_u, mx_u, &mx_i);}
int		mix_test_88(void){return test(
			"  %Lf    %u    %hi    %p    %hhi    %s  ",
			mx_Lf, mx_u, mx_hi, &mx_i, mx_c, mx_s);}
int		mix_test_89(void){return test(
			"  %X    %i    %s    %p    %f    %Lf  ",
			mx_u, mx_i, mx_s, &mx_i, mx_f, mx_Lf);}
int		mix_test_90(void){return test(
			"  %hhi    %c    %s    %X    %x    %p  ",
			mx_c, mx_c, mx_s, mx_u, mx_u, &mx_i);}
int		mix_test_91(void){return test(
			"  %o    %hi    %p    %c    %i    %u  ",
			mx_u, mx_hi, &mx_i, mx_c, mx_i, mx_u);}
int		mix_test_92(void){return test(
			"  %s    %lli    %p    %hi    %X    %hhi  ",
			mx_s, mx_lli, &mx_i, mx_hi, mx_u, mx_c);}
int		mix_test_93(void){return test(
			"  %lli    %Lf    %x    %i    %c    %u  ",
			mx_lli, mx_Lf, mx_u, mx_i, mx_c, mx_u);}
int		mix_test_94(void){return test(
			"  %X    %c    %i    %x    %o    %li  ",
			mx_u, mx_c, mx_i, mx_u, mx_u, mx_li);}
int		mix_test_95(void){return test(
			"  %hhi    %p    %x    %f    %i    %c  ",
			mx_c, &mx_i, mx_u, mx_f, mx_i, mx_c);}
int		mix_test_96(void){return test(
			"  %x    %hi    %s    %u    %li    %o  ",
			mx_u, mx_hi, mx_s, mx_u, mx_li, mx_u);}
int		mix_test_97(void){return test(
			"  %o    %u    %s    %lli    %Lf    %hi  ",
			mx_u, mx_u, mx_s, mx_lli, mx_Lf, mx_hi);}
int		mix_test_98(void){return test(
			"  %x    %hi    %f    %li    %u    %lli  ",
			mx_u, mx_hi, mx_f, mx_li, mx_u, mx_lli);}
int		mix_test_99(void){return test(
			"  %lli    %f    %c    %hi    %li    %p  ",
			mx_lli, mx_f, mx_c, mx_hi, mx_li, &mx_i);}
int		mix_test_100(void){return test(
			"  %x    %c    %lli    %hi    %p    %i  ",
			mx_u, mx_c, mx_lli, mx_hi, &mx_i, mx_i);}
int		mix_test_101(void){return test(
			"  %p    %hhi    %s    %lli    %i    %li  ",
			&mx_i, mx_c, mx_s, mx_lli, mx_i, mx_li);}
int		mix_test_102(void){return test(
			"  %hhi    %i    %f    %o    %Lf    %s  ",
			mx_c, mx_i, mx_f, mx_u, mx_Lf, mx_s);}
int		mix_test_103(void){return test(
			"  %Lf    %c    %hhi    %hi    %i    %lli  ",
			mx_Lf, mx_c, mx_c, mx_hi, mx_i, mx_lli);}
int		mix_test_104(void){return test(
			"  %li    %hi    %c    %f    %u    %o  ",
			mx_li, mx_hi, mx_c, mx_f, mx_u, mx_u);}
int		mix_test_105(void){return test(
			"  %Lf    %i    %p    %x    %lli    %o  ",
			mx_Lf, mx_i, &mx_i, mx_u, mx_lli, mx_u);}
int		mix_test_106(void){return test(
			"  %lli    %x    %hhi    %i    %Lf    %X  ",
			mx_lli, mx_u, mx_c, mx_i, mx_Lf, mx_u);}
int		mix_test_107(void){return test(
			"  %hi    %p    %li    %hhi    %c    %x  ",
			mx_hi, &mx_i, mx_li, mx_c, mx_c, mx_u);}
int		mix_test_108(void){return test(
			"  %hhi    %x    %u    %li    %o    %hi  ",
			mx_c, mx_u, mx_u, mx_li, mx_u, mx_hi);}
int		mix_test_109(void){return test(
			"  %o    %li    %p    %u    %lli    %Lf  ",
			mx_u, mx_li, &mx_i, mx_u, mx_lli, mx_Lf);}
int		mix_test_110(void){return test(
			"  %X    %Lf    %hhi    %lli    %c    %p  ",
			mx_u, mx_Lf, mx_c, mx_lli, mx_c, &mx_i);}
int		mix_test_111(void){return test(
			"  %lli    %c    %o    %f    %i    %x  ",
			mx_lli, mx_c, mx_u, mx_f, mx_i, mx_u);}
int		mix_test_112(void){return test(
			"  %s    %p    %u    %f    %X    %Lf  ",
			mx_s, &mx_i, mx_u, mx_f, mx_u, mx_Lf);}
int		mix_test_113(void){return test(
			"  %lli    %hhi    %hi    %u    %li    %s  ",
			mx_lli, mx_c, mx_hi, mx_u, mx_li, mx_s);}
int		mix_test_114(void){return test(
			"  %hhi    %Lf    %o    %i    %X    %f  ",
			mx_c, mx_Lf, mx_u, mx_i, mx_u, mx_f);}
int		mix_test_115(void){return test(
			"  %hhi    %c    %f    %u    %x    %p  ",
			mx_c, mx_c, mx_f, mx_u, mx_u, &mx_i);}
int		mix_test_116(void){return test(
			"  %i    %hi    %hhi    %s    %X    %f  ",
			mx_i, mx_hi, mx_c, mx_s, mx_u, mx_f);}
int		mix_test_117(void){return test(
			"  %u    %hi    %X    %x    %o    %i  ",
			mx_u, mx_hi, mx_u, mx_u, mx_u, mx_i);}
int		mix_test_118(void){return test(
			"  %lli    %o    %i    %x    %hhi    %Lf  ",
			mx_lli, mx_u, mx_i, mx_u, mx_c, mx_Lf);}
int		mix_test_119(void){return test(
			"  %p    %i    %c    %x    %hhi    %f  ",
			&mx_i, mx_i, mx_c, mx_u, mx_c, mx_f);}
int		mix_test_120(void){return test(
			"  %p    %s    %hi    %f    %c    %i  ",
			&mx_i, mx_s, mx_hi, mx_f, mx_c, mx_i);}
int		mix_test_121(void){return test(
			"  %c    %li    %i    %hi    %p    %X  ",
			mx_c, mx_li, mx_i, mx_hi, &mx_i, mx_u);}
int		mix_test_122(void){return test(
			"  %lli    %X    %li    %x    %p    %f  ",
			mx_lli, mx_u, mx_li, mx_u, &mx_i, mx_f);}
int		mix_test_123(void){return test(
			"  %hhi    %f    %u    %hi    %i    %o  ",
			mx_c, mx_f, mx_u, mx_hi, mx_i, mx_u);}
int		mix_test_124(void){return test(
			"  %p    %s    %li    %Lf    %u    %i  ",
			&mx_i, mx_s, mx_li, mx_Lf, mx_u, mx_i);}
int		mix_test_125(void){return test(
			"  %li    %hhi    %x    %s    %u    %p  ",
			mx_li, mx_c, mx_u, mx_s, mx_u, &mx_i);}
int		mix_test_126(void){return test(
			"  %hi    %u    %X    %i    %o    %hhi  ",
			mx_hi, mx_u, mx_u, mx_i, mx_u, mx_c);}
int		mix_test_127(void){return test(
			"  %x    %f    %o    %i    %hhi    %c  ",
			mx_u, mx_f, mx_u, mx_i, mx_c, mx_c);}
int		mix_test_128(void){return test(
			"  %u    %lli    %Lf    %li    %c    %p  ",
			mx_u, mx_lli, mx_Lf, mx_li, mx_c, &mx_i);}
int		mix_test_129(void){return test(
			"  %f    %s    %hhi    %li    %p    %lli  ",
			mx_f, mx_s, mx_c, mx_li, &mx_i, mx_lli);}
int		mix_test_130(void){return test(
			"  %x    %o    %hhi    %p    %i    %hi  ",
			mx_u, mx_u, mx_c, &mx_i, mx_i, mx_hi);}
int		mix_test_131(void){return test(
			"  %f    %li    %lli    %o    %hi    %u  ",
			mx_f, mx_li, mx_lli, mx_u, mx_hi, mx_u);}
int		mix_test_132(void){return test(
			"  %i    %hi    %c    %hhi    %x    %f  ",
			mx_i, mx_hi, mx_c, mx_c, mx_u, mx_f);}
int		mix_test_133(void){return test(
			"  %f    %lli    %li    %o    %p    %u  ",
			mx_f, mx_lli, mx_li, mx_u, &mx_i, mx_u);}
int		mix_test_134(void){return test(
			"  %f    %i    %li    %s    %p    %c  ",
			mx_f, mx_i, mx_li, mx_s, &mx_i, mx_c);}
int		mix_test_135(void){return test(
			"  %lli    %c    %Lf    %p    %li    %u  ",
			mx_lli, mx_c, mx_Lf, &mx_i, mx_li, mx_u);}
int		mix_test_136(void){return test(
			"  %s    %lli    %hi    %u    %li    %i  ",
			mx_s, mx_lli, mx_hi, mx_u, mx_li, mx_i);}
int		mix_test_137(void){return test(
			"  %f    %s    %lli    %u    %hhi    %x  ",
			mx_f, mx_s, mx_lli, mx_u, mx_c, mx_u);}
int		mix_test_138(void){return test(
			"  %li    %s    %Lf    %hi    %o    %x  ",
			mx_li, mx_s, mx_Lf, mx_hi, mx_u, mx_u);}
int		mix_test_139(void){return test(
			"  %li    %hi    %f    %hhi    %p    %X  ",
			mx_li, mx_hi, mx_f, mx_c, &mx_i, mx_u);}
int		mix_test_140(void){return test(
			"  %o    %c    %x    %u    %hhi    %i  ",
			mx_u, mx_c, mx_u, mx_u, mx_c, mx_i);}
int		mix_test_141(void){return test(
			"  %hhi    %u    %x    %li    %f    %p  ",
			mx_c, mx_u, mx_u, mx_li, mx_f, &mx_i);}
int		mix_test_142(void){return test(
			"  %f    %X    %p    %x    %s    %li  ",
			mx_f, mx_u, &mx_i, mx_u, mx_s, mx_li);}
int		mix_test_143(void){return test(
			"  %i    %Lf    %s    %lli    %hhi    %li  ",
			mx_i, mx_Lf, mx_s, mx_lli, mx_c, mx_li);}
int		mix_test_144(void){return test(
			"  %x    %X    %lli    %c    %o    %hi  ",
			mx_u, mx_u, mx_lli, mx_c, mx_u, mx_hi);}
int		mix_test_145(void){return test(
			"  %Lf    %li    %i    %o    %c    %p  ",
			mx_Lf, mx_li, mx_i, mx_u, mx_c, &mx_i);}
int		mix_test_146(void){return test(
			"  %p    %X    %o    %hhi    %c    %hi  ",
			&mx_i, mx_u, mx_u, mx_c, mx_c, mx_hi);}
int		mix_test_147(void){return test(
			"  %lli    %f    %o    %u    %p    %X  ",
			mx_lli, mx_f, mx_u, mx_u, &mx_i, mx_u);}
int		mix_test_148(void){return test(
			"  %p    %u    %x    %o    %i    %f  ",
			&mx_i, mx_u, mx_u, mx_u, mx_i, mx_f);}
int		mix_test_149(void){return test(
			"  %o    %u    %hhi    %c    %p    %li  ",
			mx_u, mx_u, mx_c, mx_c, &mx_i, mx_li);}
int		mix_test_150(void){return test(
			"  %x    %p    %hhi    %hi    %s    %Lf  ",
			mx_u, &mx_i, mx_c, mx_hi, mx_s, mx_Lf);}
int		mix_test_151(void){return test(
			"  %hi    %s    %o    %x    %i    %lli  ",
			mx_hi, mx_s, mx_u, mx_u, mx_i, mx_lli);}
int		mix_test_152(void){return test(
			"  %c    %X    %i    %u    %Lf    %o  ",
			mx_c, mx_u, mx_i, mx_u, mx_Lf, mx_u);}
int		mix_test_153(void){return test(
			"  %c    %hhi    %i    %u    %hi    %x  ",
			mx_c, mx_c, mx_i, mx_u, mx_hi, mx_u);}
int		mix_test_154(void){return test(
			"  %o    %Lf    %li    %f    %i    %X  ",
			mx_u, mx_Lf, mx_li, mx_f, mx_i, mx_u);}
int		mix_test_155(void){return test(
			"  %hhi    %X    %o    %s    %p    %hi  ",
			mx_c, mx_u, mx_u, mx_s, &mx_i, mx_hi);}
int		mix_test_156(void){return test(
			"  %s    %x    %f    %Lf    %hi    %X  ",
			mx_s, mx_u, mx_f, mx_Lf, mx_hi, mx_u);}
int		mix_test_157(void){return test(
			"  %X    %hhi    %hi    %c    %i    %o  ",
			mx_u, mx_c, mx_hi, mx_c, mx_i, mx_u);}
int		mix_test_158(void){return test(
			"  %hi    %hhi    %li    %o    %i    %p  ",
			mx_hi, mx_c, mx_li, mx_u, mx_i, &mx_i);}
int		mix_test_159(void){return test(
			"  %c    %u    %p    %i    %f    %s  ",
			mx_c, mx_u, &mx_i, mx_i, mx_f, mx_s);}
int		mix_test_160(void){return test(
			"  %i    %s    %c    %o    %lli    %Lf  ",
			mx_i, mx_s, mx_c, mx_u, mx_lli, mx_Lf);}
int		mix_test_161(void){return test(
			"  %i    %o    %x    %hi    %c    %f  ",
			mx_i, mx_u, mx_u, mx_hi, mx_c, mx_f);}
int		mix_test_162(void){return test(
			"  %p    %i    %Lf    %X    %f    %c  ",
			&mx_i, mx_i, mx_Lf, mx_u, mx_f, mx_c);}
int		mix_test_163(void){return test(
			"  %li    %o    %s    %f    %hi    %X  ",
			mx_li, mx_u, mx_s, mx_f, mx_hi, mx_u);}
int		mix_test_164(void){return test(
			"  %Lf    %o    %hhi    %i    %X    %c  ",
			mx_Lf, mx_u, mx_c, mx_i, mx_u, mx_c);}
int		mix_test_165(void){return test(
			"  %hhi    %f    %i    %o    %hi    %lli  ",
			mx_c, mx_f, mx_i, mx_u, mx_hi, mx_lli);}
int		mix_test_166(void){return test(
			"  %X    %c    %i    %lli    %hhi    %hi  ",
			mx_u, mx_c, mx_i, mx_lli, mx_c, mx_hi);}
int		mix_test_167(void){return test(
			"  %p    %x    %f    %X    %o    %c  ",
			&mx_i, mx_u, mx_f, mx_u, mx_u, mx_c);}
int		mix_test_168(void){return test(
			"  %x    %o    %hhi    %i    %f    %c  ",
			mx_u, mx_u, mx_c, mx_i, mx_f, mx_c);}
int		mix_test_169(void){return test(
			"  %o    %u    %i    %c    %hhi    %lli  ",
			mx_u, mx_u, mx_i, mx_c, mx_c, mx_lli);}
int		mix_test_170(void){return test(
			"  %s    %li    %f    %X    %o    %c  ",
			mx_s, mx_li, mx_f, mx_u, mx_u, mx_c);}
int		mix_test_171(void){return test(
			"  %li    %Lf    %u    %i    %f    %s  ",
			mx_li, mx_Lf, mx_u, mx_i, mx_f, mx_s);}
int		mix_test_172(void){return test(
			"  %c    %X    %o    %i    %li    %u  ",
			mx_c, mx_u, mx_u, mx_i, mx_li, mx_u);}
int		mix_test_173(void){return test(
			"  %x    %s    %i    %hhi    %o    %Lf  ",
			mx_u, mx_s, mx_i, mx_c, mx_u, mx_Lf);}
int		mix_test_174(void){return test(
			"  %f    %hi    %p    %lli    %o    %u  ",
			mx_f, mx_hi, &mx_i, mx_lli, mx_u, mx_u);}
int		mix_test_175(void){return test(
			"  %i    %s    %x    %Lf    %c    %u  ",
			mx_i, mx_s, mx_u, mx_Lf, mx_c, mx_u);}
int		mix_test_176(void){return test(
			"  %p    %u    %o    %hhi    %li    %X  ",
			&mx_i, mx_u, mx_u, mx_c, mx_li, mx_u);}
int		mix_test_177(void){return test(
			"  %li    %hhi    %hi    %x    %c    %Lf  ",
			mx_li, mx_c, mx_hi, mx_u, mx_c, mx_Lf);}
int		mix_test_178(void){return test(
			"  %hi    %o    %X    %i    %c    %Lf  ",
			mx_hi, mx_u, mx_u, mx_i, mx_c, mx_Lf);}
int		mix_test_179(void){return test(
			"  %x    %c    %s    %p    %hhi    %i  ",
			mx_u, mx_c, mx_s, &mx_i, mx_c, mx_i);}
int		mix_test_180(void){return test(
			"  %i    %u    %li    %X    %s    %hi  ",
			mx_i, mx_u, mx_li, mx_u, mx_s, mx_hi);}
int		mix_test_181(void){return test(
			"  %hi    %s    %li    %c    %u    %hhi  ",
			mx_hi, mx_s, mx_li, mx_c, mx_u, mx_c);}
int		mix_test_182(void){return test(
			"  %li    %c    %p    %hhi    %s    %Lf  ",
			mx_li, mx_c, &mx_i, mx_c, mx_s, mx_Lf);}
int		mix_test_183(void){return test(
			"  %X    %s    %lli    %hi    %c    %p  ",
			mx_u, mx_s, mx_lli, mx_hi, mx_c, &mx_i);}
int		mix_test_184(void){return test(
			"  %c    %hhi    %p    %x    %hi    %i  ",
			mx_c, mx_c, &mx_i, mx_u, mx_hi, mx_i);}
int		mix_test_185(void){return test(
			"  %c    %u    %hhi    %li    %hi    %x  ",
			mx_c, mx_u, mx_c, mx_li, mx_hi, mx_u);}
int		mix_test_186(void){return test(
			"  %p    %i    %s    %o    %x    %c  ",
			&mx_i, mx_i, mx_s, mx_u, mx_u, mx_c);}
int		mix_test_187(void){return test(
			"  %X    %hi    %o    %i    %c    %li  ",
			mx_u, mx_hi, mx_u, mx_i, mx_c, mx_li);}
int		mix_test_188(void){return test(
			"  %X    %u    %o    %hhi    %x    %li  ",
			mx_u, mx_u, mx_u, mx_c, mx_u, mx_li);}
int		mix_test_189(void){return test(
			"  %X    %i    %hi    %hhi    %lli    %c  ",
			mx_u, mx_i, mx_hi, mx_c, mx_lli, mx_c);}
int		mix_test_190(void){return test(
			"  %li    %u    %X    %lli    %x    %p  ",
			mx_li, mx_u, mx_u, mx_lli, mx_u, &mx_i);}
int		mix_test_191(void){return test(
			"  %hi    %Lf    %o    %hhi    %p    %X  ",
			mx_hi, mx_Lf, mx_u, mx_c, &mx_i, mx_u);}
int		mix_test_192(void){return test(
			"  %Lf    %f    %i    %lli    %p    %li  ",
			mx_Lf, mx_f, mx_i, mx_lli, &mx_i, mx_li);}
int		mix_test_193(void){return test(
			"  %li    %Lf    %f    %i    %lli    %c  ",
			mx_li, mx_Lf, mx_f, mx_i, mx_lli, mx_c);}
int		mix_test_194(void){return test(
			"  %li    %i    %f    %lli    %hi    %o  ",
			mx_li, mx_i, mx_f, mx_lli, mx_hi, mx_u);}
int		mix_test_195(void){return test(
			"  %hi    %li    %x    %X    %o    %u  ",
			mx_hi, mx_li, mx_u, mx_u, mx_u, mx_u);}
int		mix_test_196(void){return test(
			"  %i    %u    %x    %f    %li    %hi  ",
			mx_i, mx_u, mx_u, mx_f, mx_li, mx_hi);}
int		mix_test_197(void){return test(
			"  %f    %u    %Lf    %o    %lli    %p  ",
			mx_f, mx_u, mx_Lf, mx_u, mx_lli, &mx_i);}
int		mix_test_198(void){return test(
			"  %Lf    %x    %X    %hhi    %i    %f  ",
			mx_Lf, mx_u, mx_u, mx_c, mx_i, mx_f);}
int		mix_test_199(void){return test(
			"  %o    %f    %i    %x    %hhi    %Lf  ",
			mx_u, mx_f, mx_i, mx_u, mx_c, mx_Lf);}







//No-crash-no-segfault test
int		nocrash_noarg_1(void){char *str; ft_asprintf(&str, "%1$"); free(str); return (0);}
int		nocrash_noarg_2(void){char *str; ft_asprintf(&str, "%0"); free(str); return (0);}
int		nocrash_noarg_3(void){char *str; ft_asprintf(&str, "% "); free(str); return (0);}
int		nocrash_noarg_4(void){char *str; ft_asprintf(&str, "%#"); free(str); return (0);}
int		nocrash_noarg_5(void){char *str; ft_asprintf(&str, "%-"); free(str); return (0);}
int		nocrash_noarg_6(void){char *str; ft_asprintf(&str, "%+"); free(str); return (0);}
int		nocrash_noarg_9(void){char *str; ft_asprintf(&str, "%23"); free(str); return (0);}
int		nocrash_noarg_10(void){char *str; ft_asprintf(&str, "%."); free(str); return (0);}
int		nocrash_noarg_11(void){char *str; ft_asprintf(&str, "%hh"); free(str); return (0);}
int		nocrash_noarg_12(void){char *str; ft_asprintf(&str, "%h"); free(str); return (0);}
int		nocrash_noarg_13(void){char *str; ft_asprintf(&str, "%ll"); free(str); return (0);}
int		nocrash_noarg_14(void){char *str; ft_asprintf(&str, "%l"); free(str); return (0);}
int		nocrash_noarg_15(void){char *str; ft_asprintf(&str, "%L"); free(str); return (0);}
int		nocrash_noarg_16(void){char *str; ft_asprintf(&str, "%p"); free(str); return (0);}
int		nocrash_noarg_17(void){char *str; ft_asprintf(&str, "%d"); free(str); return (0);}
int		nocrash_noarg_19(void){char *str; ft_asprintf(&str, "%u"); free(str); return (0);}
int		nocrash_noarg_20(void){char *str; ft_asprintf(&str, "%x"); free(str); return (0);}
int		nocrash_noarg_21(void){char *str; ft_asprintf(&str, "%X"); free(str); return (0);}
int		nocrash_noarg_22(void){char *str; ft_asprintf(&str, "%f"); free(str); return (0);}
int		nocrash_noarg_24(void){char *str; ft_asprintf(&str, "%c"); free(str); return (0);}
int		nocrash_noarg_25(void){char *str; ft_asprintf(&str, "%o"); free(str); return (0);}
int		nocrash_noarg_27(void){char *str; ft_asprintf(&str, "%{}"); free(str); return (0);}

int		nocrash_nullarg_1(void){char *str; ft_asprintf(&str, "%1$s", NULL); free(str); return (0);}
int		nocrash_nullarg_2(void){char *str; ft_asprintf(&str, "%0s", NULL); free(str); return (0);}
int		nocrash_nullarg_3(void){char *str; ft_asprintf(&str, "% s", NULL); free(str); return (0);}
int		nocrash_nullarg_4(void){char *str; ft_asprintf(&str, "%#s", NULL); free(str); return (0);}
int		nocrash_nullarg_5(void){char *str; ft_asprintf(&str, "%-s", NULL); free(str); return (0);}
int		nocrash_nullarg_6(void){char *str; ft_asprintf(&str, "%+s", NULL); free(str); return (0);}
int		nocrash_nullarg_9(void){char *str; ft_asprintf(&str, "%23s", NULL); free(str); return (0);}
int		nocrash_nullarg_10(void){char *str; ft_asprintf(&str, "%.s", NULL); free(str); return (0);}
int		nocrash_nullarg_11(void){char *str; ft_asprintf(&str, "%hhs", NULL); free(str); return (0);}
int		nocrash_nullarg_12(void){char *str; ft_asprintf(&str, "%hs", NULL); free(str); return (0);}
int		nocrash_nullarg_13(void){char *str; ft_asprintf(&str, "%lls", NULL); free(str); return (0);}
int		nocrash_nullarg_14(void){char *str; ft_asprintf(&str, "%ls", NULL); free(str); return (0);}
int		nocrash_nullarg_15(void){char *str; ft_asprintf(&str, "%Ls", NULL); free(str); return (0);}
int		nocrash_nullarg_16(void){char *str; ft_asprintf(&str, "%p", NULL); free(str); return (0);}
int		nocrash_nullarg_17(void){char *str; ft_asprintf(&str, "%d", NULL); free(str); return (0);}
int		nocrash_nullarg_18(void){char *str; ft_asprintf(&str, "%b", NULL); free(str); return (0);}
int		nocrash_nullarg_19(void){char *str; ft_asprintf(&str, "%u", NULL); free(str); return (0);}
int		nocrash_nullarg_20(void){char *str; ft_asprintf(&str, "%x", NULL); free(str); return (0);}
int		nocrash_nullarg_21(void){char *str; ft_asprintf(&str, "%X", NULL); free(str); return (0);}
int		nocrash_nullarg_22(void){char *str; ft_asprintf(&str, "%f", NULL); free(str); return (0);}
int		nocrash_nullarg_23(void){char *str; ft_asprintf(&str, "%s", NULL); free(str); return (0);}
int		nocrash_nullarg_24(void){char *str; ft_asprintf(&str, "%c", NULL); free(str); return (0);}
int		nocrash_nullarg_25(void){char *str; ft_asprintf(&str, "%o", NULL); free(str); return (0);}
int		nocrash_nullarg_26(void){char *str; ft_asprintf(&str, "%m", NULL); free(str); return (0);}
int		nocrash_nullarg_27(void){char *str; ft_asprintf(&str, "%{}", NULL); free(str); return (0);}

//Alternate API tests
int		snprintf_buffwrite_simple(void)
{
	char	*str = ft_strdup("0123456789");
	ft_snprintf(str + 2, 4, "abcd");
	int ret = assert_str(str, "01abcd6789");
	free(str); return (ret);
}

int		snprintf_buffwrite_trunc(void)
{
	char	*str = ft_strdup("0123456789");
	ft_snprintf(str + 2, 2, "abcd");
	int ret = assert_str(str, "01ab456789");
	free(str); return (ret);
}

int		snprintf_buffwrite_trunc_expansion_s(void)
{
	char	*str = ft_strdup("0123456789");
	ft_snprintf(str + 2, 2, "%s", "abcd");
	int ret = assert_str(str, "01ab456789");
	free(str); return (ret);
}

int		snprintf_buffwrite_trunc_expansion_f(void)
{
	char	*str = ft_strdup("0123456789");
	ft_snprintf(str + 2, 3, "%f", 5.375);
	int ret = assert_str(str, "015.356789");
	free(str); return (ret);
}

int		sprintf_buffwrite_simple(void)
{
	char	*str = ft_strdup("0123456789");
	ft_sprintf(str + 2, "abcd");
	int ret = assert_str(str, "01abcd6789");
	free(str); return (ret);
}

int		sprintf_buffwrite_expansion_s(void)
{
	char	*str = ft_strdup("0123456789");
	ft_sprintf(str + 2, "%s", "abcd");
	int ret = assert_str(str, "01abcd6789");
	free(str); return (ret);
}

int		sprintf_buffwrite_expansion_f(void)
{
	char	*str = ft_strdup("0123456789");
	ft_sprintf(str + 2, "%f", 5.375);
	int ret = assert_str(str, "015.375000");
	free(str); return (ret);
}

