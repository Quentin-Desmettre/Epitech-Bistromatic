/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** main file
*/

#include "bistromatic.h"
#include <stdlib.h>

char *infin_add(char *fir, char *sec, char *base, char *ops)
{
    char *result;
    expr_params_t par = {0, base, ops};
    int first_decim = index_of(ops[8], sec);
    int sec_decim = index_of(ops[8], sec);
    adapt_decimals(&fir, &sec, base, ops);
    int index = 0;

(first_decim > sec_decim) ? (index = first_decim) : (index = sec_decim);

    if (fir[0] == ops[3] && sec[0] == ops[3]) {
        result = my_add(fir, sec, base, ops);
        insert_at_beg(&result, ops[3], 1, 1);
    }
    if (fir[0] == ops[3] && sec[0] != ops[3])
        result = my_sub(sec, fir + 1, 0, &par);
    if (fir[0] != ops[3] && sec[0] == ops[3])
        result = my_sub(fir, sec + 1, 0, &par);
    if (fir[0] != ops[3] && sec[0] != ops[3]) {
        result = my_add(fir, sec, base, ops);
    }
    if (index > 0)
        re_alloc(&result, (replace(result, index + 1, 0, &ops[8])), 1);
    cleanex(&result, base, ops);
    return result;
}
