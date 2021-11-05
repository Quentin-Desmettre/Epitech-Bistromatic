/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** exponential
*/

#include "bistromatic.h"
#include <stdlib.h>

char *factorial(char *nb, char *base, char *ops)
{
    char *result = char_to_str(base[1]);
    char *first_nb = char_to_str(base[1]);

    while (nb[0] != first_nb[1]) {
        re_alloc(&result, infin_mul(result, nb, base, ops), 1);
        re_alloc(&nb, infin_sub(nb, first_nb, base, ops), 1);
    }
    free(first_nb);
    return result;
}

char *my_pow(char *nb, char *power, char *base, char *ops)
{
    char *result = char_to_str(base[1]);
    char *fir_char = char_to_str(base[1]);
    int neg = (power[0] == ops[3]) ? (1) : (0);
    power = my_strdup(power);

    if (neg)
        re_alloc(&power, my_strdup(power + 1), 1);
    while (power[0] != base[0] && power[0] != 0) {
        re_alloc(&result, infin_mul(result, nb, base, ops), 1);
        re_alloc(&power, infin_sub(power, fir_char, base, ops), 1);
    }
    if (neg) {
        re_alloc(&result, infin_div(fir_char, result, base, ops), 1);
    }
    free(fir_char);
    return result;
}

// e^x = lim (n -> inf) : (1 + x/n)^n

char *my_exp(char *x, char *base, char *ops)
{
    char *n = my_strdup("100000");
    char *one = my_strdup("1");
    char *x_over_n = infin_div(x, n, base, ops);
    char *one_plus_x_over_n = infin_add(x_over_n, one, base, ops);
    char *result = my_pow(one_plus_x_over_n, n, base, ops);

    return result;
}