/*
** EPITECH PROJECT, 2021
** bistro_matic
** File description:
** main file
*/

#include "../include/iomanip.h"
#include "../include/strmanip.h"
#include <stdlib.h>
#include "../include/bistromatic.h"
#include <fcntl.h>
#include <unistd.h>

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./calc base operators size_read\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the parentheses");
    my_putstr(" and the 5 operators\n");
    my_putstr("- size_read: numbers of characters to be read\n");
}

static char *get_expr(int const read_size)
{
    char *expr;

    if (read_size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(sizeof(char) * (read_size + 1));
    if (expr == NULL) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, read_size) != read_size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[read_size] = '\0';
    return expr;
}

int main(int ac, char **av)
{
    int size = 0;
    char *expr;

    ac = 4;
    av[2] = "0123456789ABCDEF";
    av[3] = "()+-*/%";
    check_all(ac, av + 1);
    size = my_getnbr(av[4]);
    expr = my_strdup(av[1]);//get_expr(size);
    check_expr(av[1], av[2], av[3]);
    cleanex(&expr, av[2], av[3]);
    my_putstr(expr);
    my_putchar('\n');
    //my_putstr(eval_expr(expr, av[1], av[2], size));
    free(expr);
    return EXIT_SUCCESS;
}
