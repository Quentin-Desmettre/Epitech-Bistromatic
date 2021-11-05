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

char *my_pow(char *nb, char *pwr, char *base, char *ops)
{
    int power = my_getnbr(pwr);
    char *result = char_to_str(base[1]);
    char *fir_char = char_to_str(base[1]);
    int neg = (power < 0) ? (1) : (0);

    if (neg)
        power *= -1;
    while (power != 0) {
        if (result[0] == base[0] && my_strlen(result) == 1)
            break;
        re_alloc(&result, infin_mul(result, nb, base, ops), 1);
        power--;
    }
    if (neg) {
        re_alloc(&result, infin_div(fir_char, result, base, ops), 1);
    }
    free(fir_char);
    return result;
}

char *my_exp(char *x, char *base, char *ops)
{
    x=  my_strdup("90");
    char *n = my_strdup("1000000");
    char *one = char_to_str(base[1]);
    char *x_over_n = infin_div(my_strdup(x), my_strdup(n), base, ops);
    char *one_plus_x_over_n = infin_add(x_over_n, one, base, ops);
    printf("1 + %s = %s\n", x_over_n, one_plus_x_over_n);
    char *result = my_pow(one_plus_x_over_n, n, base, ops);
    printf("e^%s = %s\n", x, result);

    return "";
}