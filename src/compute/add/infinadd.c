/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** main file
*/

#include "bistromatic.h"

char *infin_add(char *fir, char *sec, char *base, char *ops)
{
    char *result;
    expr_params_t par = {0, base, ops};

    if (fir[0] == ops[3] && sec[0] == ops[3]) {
        result = my_add(fir, sec, base, ops);
        insert_at_beg(&result, ops[3], 1, 0);
    }
    if (fir[0] == ops[3] && sec[0] != ops[3])
        result = my_sub(sec, fir + 1, 0, &par);
    if (fir[0] != ops[3] && sec[0] == ops[3])
        result = my_sub(fir, sec + 1, 0, &par);
    if (fir[0] != ops[3] && sec[0] != ops[3]) {
        result = my_add(fir, sec, base, ops);
    }
    return clean_str(result, base, ops);
}