/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Multiplication Func Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

/*
Test (infin_mul, re_alloc_test, .init = redirect_all_stdout)
{
    char *result = malloc(5);
    result = "Saussure";
    char *new = "soooz";
    re_alloc(&result, new, 1);
    cr_assert_str_eq(result, "soooz");
}*/

/*
Test (infin_mul, init_with_int_test, .init = redirect_all_stdout)
{
    unsigned long long *array = malloc(sizeof(unsigned long long) * 5);
    init_with_int(array, 0, 6);
    cr_assert_str_eq(array, "");
}*/

Test (infin_mul, replace_digit_test, .init = redirect_all_stdout)
{
    unsigned long long *result;
    char *fir = "35";
    char *sec = "100";
    char *base = "0123456789";
    replace_digit(fir, sec, base);
    cr_assert_str_eq(result, 3500);
}

Test (infin_mul, my_mul_test, .init = redirect_all_stdout)
{
    char *result = malloc(5);
    char *fir = "35";
    char *sec = "100";
    char *base = "0123456789";
    char *ops = "()+-*/%";
    my_mul(fir, sec, base, ops);
    cr_assert_str_eq(result, "3500");
}
