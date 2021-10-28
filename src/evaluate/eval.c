/*
** EPITECH PROJECT, 2021
** eval.c
** File description:
** eval.c
*/
#include "include/strmanip.h"
#include "include/iomanip.h"
#include "include/evalexpr.h"
#include <stdlib.h>

int is_end(char *str)
{
    if ((str[0] >= '9' || str[0] <= '0') && (str[0] != '+' && str[0] != '-'))
        return 84;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] >= '9' || str[i] <= '0')
            return 84;
    }
    return 0;
}

int eval_expr(char *str)
{
    int val;
    char *tmp;
    int fr = 0;

    while (contain_any_of(str + 1, "()+-*/%")) {
        tmp = str;
        str = prio(str);
        if (fr)
            free(tmp);
        fr = 1;
    }
    val = my_getnbr(str);
    if (fr)
        free(str);
    return val;
}
