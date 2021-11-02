/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** toto: Description
*/

#include <stdlib.h>
#include <stdio.h>
#include "bistromatic.h"

void re_alloc(char **str, char *new, int is_free)
{
    char *tmp = *str;

    *str = new;
    if (is_free)
        free(tmp);
}

void init_with_int(unsigned long long *array, int what, int len)
{
    for (int i = 0; i < len; i++) {
        array[i] = what;
    }
}

ull *replace_digit(char *fir, char *sec, char *base) {
    int len = my_strlen(fir) + my_strlen(sec) + 2;
    ull *tmp = malloc(sizeof(ull) * (len + 1));
    int len_i = my_strlen (fir);
    int len_j = my_strlen (sec);
    int len_base = my_strlen (base);

    for (int i = 0; fir[i]; i++)
        for (int j = 0; sec[j]; j++) {
            tmp[len - i - j - 1] += index_of (fir[len_i - i - 1], base) *
            index_of (sec[len_j - j - 1], base);
            tmp[len - i - j - 2] += tmp[len - i - j - 1] / len_base;
            tmp[len - i - j - 1] %= len_base;
        }
    return (tmp);
}

char *my_mul(char *fir, char *sec, char *base, char *ops)
{
    int len = my_strlen(fir) + my_strlen(sec) + 2;
    ull *tmp = malloc(sizeof(ull) * (len + 1));
    char *result = malloc(len + 1);

    init_with_int(tmp, 0, len + 1);
    my_memset(result, 0, len + 1);
    tmp = replace_digit(fir, sec, base);
    for (int i = 0; i < len; i++)
        result[i] = base[tmp[i]];
    re_alloc(&result, clean_str(result, base, ops), 1);
    free(tmp);
    return (result);
}

char *infin_mul(char *fir, char *sec, char *base, char *ops)
{
    int len = my_strlen(fir) + my_strlen(sec) + 2;
    char *result = malloc(len + 1);

    if (fir[0] == '-' && sec[0] == '-')
        result = my_mul(fir + 1, sec + 1, base, ops);
    if (fir[0] != '-' && sec[0] != '-')
        result = my_mul(fir, sec, base, ops);
    if (fir[0] == '-' && sec[0] != '-') {
        result = my_mul(fir + 1, sec, base, ops);
        insert_at_beg(&result, '-', 1, 1);
    }
    if (fir[0] != '-' && sec[0] == '-') {
        result = my_mul(fir, sec + 1, base, ops);
        insert_at_beg(&result, '-', 1, 1);
    }
    return (result);
}
