/*
** EPITECH PROJECT, 2021
** div_test
** File description:
** div2_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"
#include "../include/div.h"

Test (my_div, do_div)
{
    char *a = "5697";
    char *b = "12";
    char *result;
    expr_params_t par = {0, "0123456789", "()+-*/%"};

    result = my_div(a, b, &par);
    cr_assert_str_eq(result, "474");
    a = "-5697";
    result = my_div(a, b, &par);
    cr_assert_str_eq(result, "0");
}
