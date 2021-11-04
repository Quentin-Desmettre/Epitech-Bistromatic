/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** Multiplication Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (infin_mul, basic_mul, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("t", "t", "pouet", "()+-*/%"), "eo");
}

Test (infin_mul, basic_mul_both_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("-t", "-t", "pouet", "()+-*/%"), "eo");
}

Test (infin_mul, basic_mul_left_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("-t", "t", "pouet", "()+-*/%"), "-eo");
}

Test (infin_mul, mul_carry_test, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("opop", "op", "pouet", "()+-*/%"),
    "opopp");
}

Test (infin_mul, mul_big, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("eputotpeutpeuote", "poetouetpoetpoteoutpoteou",
    "pouet", "()+-*/%"), "opuepputttoouootupteouutpeupooueuutouuuo");
}
