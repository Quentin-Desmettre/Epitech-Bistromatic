/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** Bistro
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test(compute_raw, do_good_call)
{
    int start = 5;
    int len = 0;
    int len_first = 0;
    char *calc = my_strdup("5-8+5*5");

    expr_params_t par = {calc, "0123456789", "()+-*/%"};
    cr_assert_str_eq(compute_raw(start, &len, &len_first, &par), "25");
}