/*
** EPITECH PROJECT, 2021
** prio
** File description:
** prio
*/
#include "include/math.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/evalexpr.h"

char *val_tempo(char *calcul, int *i, int *j)
{
    char *tempo;
    int h = 0;

    for (; calcul[(*j)] && calcul[(*j)] != ')'; (*j)++)
        if (calcul[(*j)] == '(')
            (*i) = (*j);
    tempo = malloc(sizeof(char) * ((*j) - (*i)));
    for (; h != (*j) - (*i) - 1; h++)
        tempo[h] = calcul[(*i) + h + 1];
    tempo[h] = '\0';
    return tempo;
}

char *prio(char *calcul)
{
    int i = 0;
    int j = 0;
    char *tempo = val_tempo(calcul, &i, &j);
    char *to_rt;
    char *tempo2;

    if (calcul[i] != '(') {
        free(tempo);
        tempo2 = evaluate(calcul);
        to_rt = replace(calcul, 0, j, tempo2);
        free(tempo2);
        return to_rt;
    }
    tempo2 = evaluate(tempo);
    to_rt = replace(calcul, i, j - i + 1, tempo2);
    free(tempo);
    free(tempo2);
    return to_rt;
}
