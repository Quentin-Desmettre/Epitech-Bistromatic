/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** Do operations
*/

#include "include/evalexpr.h"
#include "include/iomanip.h"
#include <stdlib.h>

static int compute(int n1, int operation, int n2)
{
    int (*fonc[5])(int, int);

    fonc[0] = &add;
    fonc[1] = &substract;
    fonc[2] = &multiply;
    fonc[3] = &divide;
    fonc[4] = &modulo;
    return fonc[operation](n1, n2);
}

char *do_op(char *first, char my_op, char *second)
{
    int number_1 = my_getnbr(first);
    int number_2 = my_getnbr(second);
    int op = (my_op == '+') * 0 + (my_op == '-') + (my_op == '*') * 2;
    char *string;

    op += (my_op == '/') * 3 + (my_op == '%') * 4;
    int_to_str(compute(number_1, op, number_2), &string);
    return string;
}
