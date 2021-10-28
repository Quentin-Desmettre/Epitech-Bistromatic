/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** evaluation functions
*/

#include "include/strmanip.h"
#include "include/iomanip.h"
#include <stdlib.h>
#include "include/evalexpr.h"

static char *compute_raw(char *expr, int start, int *len, int *len_1)
{
    char *first = get_prev_number(expr, start);
    char *second = get_next_number(expr, start);
    char *tmp = do_op(first, expr[start], second);

    *len = my_strlen(first) + my_strlen(second) + 1;
    *len_1 = my_strlen(first);
    free(first);
    free(second);
    return tmp;
}

static char *evaluate_with(char *expr, char *op)
{
    char *tmp;
    int nb_rm;
    char *tmp2;
    int len_first;

    for (int i = 0; contain_any_of(expr + 1, op); i++) {
        if (contain(op, expr[i])) {
            tmp = compute_raw(expr, i, &nb_rm, &len_first);
            tmp2 = replace(expr, i - len_first, nb_rm, tmp);
            free(expr);
            expr = tmp2;
            free(tmp);
            i = 0;
        }
    }
    return expr;
}

char *evaluate(char *expr)
{
    expr = my_strdup(expr);
    expr = evaluate_with(expr, "*/%");
    expr = evaluate_with(expr, "+-");
    return expr;
}
