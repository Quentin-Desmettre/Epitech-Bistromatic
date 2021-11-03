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
    cr_assert_str_eq(infin_mul("5", "5", "0123456789", "()+-*/%"), "25");
}

Test (infin_mul, basic_mul_both_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("-5", "-5", "0123456789", "()+-*/%"), "25");
}

Test (infin_mul, basic_mul_left_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("-5", "5", "0123456789", "()+-*/%"), "-25");
}

Test (infin_mul, basic_mul_right_neg, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("5", "-5", "0123456789", "()+-*/%"), "-25");
}

Test (infin_mul, basic_mul_two, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("20", "100", "0123456789", "()+-*/%"), "2000");
}

Test (infin_mul, mul_carry_test, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("777", "7777", "0123456789", "()+-*/%"),
    "6042729");
}

Test (infin_mul, mul_zero_test, .init = redirect_all_stdout)
{
    cr_assert_str_eq(infin_mul("0", "0", "0123456789", "()+-*/%"), "0");
}

Test (infin_mul, mul_big, .init = redirect_all_stdout)
{
cr_assert_str_eq(infin_mul("123456789987654321", "9876543211234567890123456789",
"0123456789", "()+-*/%"), "1219326321033379056636183509998475842112635269");
}

//Test (infin_mul, mul_very_big, .init = redirect_all_stdout)
//{
//cr_assert_str_eq(infin_mul("1234564567890987654567897644567876543456785423456789",
//"234567899076567890765312345634567853456787896356457679678564623879",
//"0123456789", "()+-*/%"), "289589216964559840143931683349626802154371256763081668629591209678907616066183086601432237268843363091096771794064531");
//}
