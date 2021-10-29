/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** evaluation functions
*/

#include "../../include/lib/strmanip.h"
#include "../../include/lib/iomanip.h"
#include <stdlib.h>
#include "../../include/bistromatic.h"
#include "../../include/evalexpr.h"

static char *compute_raw(char *expr, int start, int *len, int *len_1, char *base, char *ops)
{
    char *first = get_prev_number(expr, start, base, ops);
    char *second = get_next_number(expr, start, base, ops);
    char *tmp = do_op(first, expr[start], second, base, ops);

    *len = my_strlen(first) + my_strlen(second) + 1;
    *len_1 = my_strlen(first);
    free(first);
    free(second);
    return tmp;
}

static char *evaluate_with(char *expr, char *base, char *ops, char *op_valid)
{
    char *tmp;
    int nb_rm;
    char *tmp2;
    int len_first;

    for (int i = 0; contain_any_of(expr + 1, op_valid); i++) {
        if (contain(op_valid, expr[i])) {
            tmp = compute_raw(expr, i, &nb_rm, &len_first, base, ops);
            tmp2 = replace(expr, i - len_first, nb_rm, tmp);
            free(expr);
            expr = tmp2;
            free(tmp);
            i = 0;
        }
    }
    return expr;
}

char *evaluate(char *expr, char *base, char *ops)
{
    expr = evaluate_with(expr, base, ops, ops + 4);
    expr = evaluate_with(expr, base, ops, ops + 2);
    return expr;
}
