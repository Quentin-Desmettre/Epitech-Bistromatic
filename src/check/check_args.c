/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** check if arguments are valid
*/

#include "../../include/iomanip.h"
#include "../../include/strmanip.h"
#include <stdlib.h>
#include "../../include/bistromatic.h"

static void check_nb_args(int ac)
{
    if (ac != 4) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
}

static void check_base(char const *base)
{
    if (my_strlen(base) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage();
        exit(EXIT_USAGE);
    }
}

void check_all(int ac, char **av)
{
    check_help(ac, av);
    check_nb_args(ac);
    check_base(av[1]);
    check_ops(av[2]);
}
