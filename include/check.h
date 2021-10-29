/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** prototypes for checkers
*/

#ifndef CHECK_H
    #define CHECK_H

typedef struct int_pair {
    int a;
    int b;
} int_pair_t;

void check_all(int ac, char **av);
void check_expr(char const *str, char const *base, char const *ops);
void cleanex(char **expr, char *base, char *ops);
void check_base_ops(char const *base, char const *ops);
void check_ops_place(char const *str, char const *ops);
void check_basic(char const *str, char const *base, char const *ops);

#endif
