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

    if (neg)
        power++;
    while (power[0] != base[0] && power[0] != 0) {
        re_alloc(&result, infin_mul(result, nb, base, ops), 1);
        re_alloc(&power, infin_sub(power, fir_char, base, ops), 1);
    }
    if (neg) {
        re_alloc(&result, infin_div(fir_char, result, base, ops), 1);
    }
    free(fir_char);
    my_putstr(result);
    return result;
}

char *my_exp(char *nb, char *base, char *ops)
{
    nb = base;
    base = ops;
    base[0] = nb[0];
    return base;    
}