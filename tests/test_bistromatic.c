/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** TODO: add description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"
#include  <unistd.h>

Test (get_expr, syntax_error_invalid_len, .init = redirect_all_stdout)
{
    int const read_size = -10;
    get_expr(read_size);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG);
}
