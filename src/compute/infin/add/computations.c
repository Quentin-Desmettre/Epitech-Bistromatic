/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** Computations
*/

#include "../../../../include/bistromatic.h"
#include <stdlib.h>
#include "../../../../include/strmanip.h"

static void put_same_length(char **first, char **second, char *base, char *ops)
{
    int len_f;
    int len_s;

    if (**first == ops[3])
        (*first)++;
    if (**second == ops[3])
        (*second)++;
    len_f = my_strlen(*first);
    len_s = my_strlen(*second);
    if (len_f < len_s) {
        insert_at_beg(first, base[0], len_s - len_f);
    }
    if (len_s < len_f) {
        insert_at_beg(second, base[0], len_f - len_s);
    }
}

static char *compute_sub(char *first, char *second, char *base)
{
    int len = my_strlen(first);
    char *result = malloc(sizeof(char) * (len + 3));

    init_with(result, '\0', len + 3);
    for (int i = len - 1; i >= 0; i--) {
        result[i + 2] += index_of(first[i], base) - index_of(second[i], base);
        if (result[i + 2] < 0) {
            first[i - 1]--;
            result[i + 2] += 10;
        }
    }
    for (int i = 0; i < len + 2; i++)
        result[i] = base[result[i]];
    return result;
}

char *my_sub(char *first, char *second, int is_rec, char *base, char *ops)
{
    char *result;
    int len_f = my_strlen(clean_str(first, base, ops));
    int len_s = my_strlen(clean_str(second, base, ops));

    if (len_f < len_s) {
        result = my_sub(second, first, 1, base, ops);
        if (!is_rec)
            insert_at_beg(&result, ops[3], 1);
        return result;
    }
    put_same_length(&first, &second, base, ops);
    if (my_nbr_cmp(first, second, base) < 0) {
        result = my_sub(second, first, 1, base, ops);
        if (!is_rec)
            insert_at_beg(&result, ops[3], 1);
        return result;
    }
    return compute_sub(first, second, base);
}

int index_of(char c, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

char *my_add(char *first, char *second, char *base, char *ops)
{
    int len;
    char *result;
    int len_base = my_strlen(base);

    put_same_length(&first, &second, base, ops);
    len = my_strlen(first);
    result = malloc(sizeof(char) * (len + 2));
    init_with(result, '\0', len + 2);
    for (int i = len - 1; i >= 0; i--) {
        result[i + 1] += index_of(first[i], base) + index_of(second[i], base);
        result[i] = result[i + 1] / len_base;
        result[i + 1] -= result[i] * len_base;
    }
    for (int i = 0; i < len + 1; i++)
        result[i] = base[result[i]];
    return result;
}
