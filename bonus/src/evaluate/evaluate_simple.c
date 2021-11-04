/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** evaluation functions
*/

#include <stdlib.h>
#include "bistromatic.h"

static char *compute_raw(int start, int *len, int *len_1, expr_params_t *par)
{
    char *first = get_prev_number(par->expr, start, par->base, par->ops);
    char *second = get_next_number(par->expr, start, par->base, par->ops);
    char *tmp = do_op(first, index_of(par->expr[start], par->ops) - 2,
    second, par);

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
    expr_params_t par = {expr, base, ops};

    for (int i = 0; contain_any_of(expr + 1, op_valid); i++) {
        if (contain(op_valid, expr[i])) {
            par.expr = expr;
            tmp = compute_raw(i, &nb_rm, &len_first, &par);
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
