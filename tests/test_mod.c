/*
** EPITECH PROJECT, 2021
** Bistro test
** File description:
** Modulo Test (1)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (check_null, check_if_null)
{
    char *result = my_strdup("");
    char *base = "0123456789";

    cr_assert_str_eq(check_null(&result, base), "0");
    result = "56";
    cr_assert_str_neq(check_null(&result, base), "0");
}
