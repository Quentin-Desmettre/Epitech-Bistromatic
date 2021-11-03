/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** header for checks
*/

#ifndef CHECK_H
    #define CHECK_H

typedef struct int_pair {
    int a;
    int b;
} int_pair_t;

int check_nb_args(int ac);
int check_base(char const *base);
int check_ops(char const *ops);
int check_help(int ac, char **av);
int check_all(int ac, char **av);
int check_expr(char const *str, char const *base, char const *ops);
int check_base_ops(char const *base, char const *ops);
int check_ops_place(char const *str, char const *ops);
int check_basic(char const *str, char const *base, char const *ops);
int cleanex(char **expr, char *base, char *ops);

#endif
