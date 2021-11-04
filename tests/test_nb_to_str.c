/*
** EPITECH PROJECT, 2021
** Bistro
** File description:
** Bistro
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test(nb_to_str, put_negative_overflow)
{
    char *jambon = malloc(30);
    show_extrem_min(&jambon);
    cr_assert_str_eq(jambon, "-2147483648");
}