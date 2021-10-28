/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** check validity of expr
*/

#include "../../include/bistromatic.h"
#include <stdlib.h>
#include "../../include/iomanip.h"
#include "../../include/strmanip.h"

static int check_paren(char const *str, char const *ops)
{
    int stack = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ops[0])
            stack++;
        if (str[i] == ops[1])
            stack--;
        if (stack < 0)
            return 0;
    }
    return stack == 0;
}

static void check_double_ops(char const *str, char const *ops, int i)
{
    if (contain(ops + 2, str[i]) && contain(ops + 2, str[i + 1])) {
        if (str[i + 1] != ops[2] && str[i + 1] != ops[3]) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_SYNTAX_ERROR);
        }
    }
}

static void check_ops_paren(char const *str, char const *base, char const *ops, int i)
{
    if (contain(base, str[i]) &&
        (str[i + 1] == ops[0] || str[i - 1] == ops[1])) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SYNTAX_ERROR);
    }
    if (contain(ops + 2, str[i])) {
        if (str[i + 1] == ops[1]) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_SYNTAX_ERROR);
        }
        if (str[i - 1] == ops[0] &&
            ((str[i] != ops[2] && str[i] != ops[3]) || !contain(base, str[i + 1]))) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_SYNTAX_ERROR);
        }
    }
}

void check_expr(char const *str, char const *base, char const *ops)
{
    char base_ops[my_strlen(base) + my_strlen(ops) + 1];

    my_strcpy(base_ops, base);
    my_strcat(base_ops, ops);
    if (my_strlen(str) == 0 || !contain_only(str, base_ops) ||
        !check_paren(str, ops)) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SYNTAX_ERROR);
    }
    if ((contain(ops + 2, str[0]) && (str[0] != ops[2] && str[0] != ops[3])) ||
        contain(ops + 2, str[my_strlen(str) - 1])) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SYNTAX_ERROR);
    }
    for (int i = 0; str[i]; i++) {
        check_ops_paren(str, base, ops, i);
        check_double_ops(str, ops, i);
    }
}
