/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"
#include "../include/div.h"

Test (search_who_is_upper_n, grep_ten_nb)
{
    expr_params_t par = {0, "0123456789", "()+-*/%"};
    char *ten_n = char_to_str(par.base[1]);
    char *ten_n_b = my_strdup("12");
    char *r = my_strdup("5697");

    search_who_is_upper_n(&ten_n, &ten_n_b, r, &par);
    cr_assert_str_eq(ten_n, "100");
    cr_assert_str_eq(ten_n_b, "1200");
}

