/*
** EPITECH PROJECT, 2021
** eval.c
** File description:
** eval.c
*/

#include "bistromatic.h"
#include <stdlib.h>

static char *val_tempo(char *calcul, int *i, int *j, char *ops)
{
    char *tempo;
    int h = 0;

    for (; calcul[(*j)] && calcul[(*j)] != ops[1]; (*j)++)
        if (calcul[(*j)] == ops[0])
            (*i) = (*j);
    tempo = malloc(sizeof(char) * ((*j) - (*i)));
    for (; h != (*j) - (*i) - 1; h++)
        tempo[h] = calcul[(*i) + h + 1];
    tempo[h] = '\0';
    return tempo;
}

static char *prio(char *calcul, char *base, char *ops)
{
    int i = 0;
    int j = 0;
    char *tempo = val_tempo(calcul, &i, &j, ops);
    char *to_rt;
    char *tempo2;

    if (calcul[i] != ops[0]) {
        free(tempo);
        to_rt = my_strdup(calcul);
        tempo2 = evaluate(to_rt, base, ops);
        to_rt = replace(calcul, 0, j, tempo2);
        free(tempo2);
        return to_rt;
    }
    tempo2 = evaluate(tempo, base, ops);
    to_rt = replace(calcul, i, j - i + 1, tempo2);
    return to_rt;
}

char *eval_expr(char *str, char *base, char *ops)
{
    char *tmp;

    while (contain_any_of(str + 1, ops)) {
        cleanex(&str, base, ops);
        tmp = str;
        str = prio(str, base, ops);
        free(tmp);
    }
    return str;
}
