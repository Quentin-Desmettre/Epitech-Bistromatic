/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** prototypes for the eval_expr part
*/

#ifndef EVALEXPR_H
    #define EVALEXPR_H

char *evaluate(char *expr, char *base, char *ops);
char *get_next_number(char *str, int start, char *base, char *ops);
char *get_prev_number(char *str, int start, char *base, char *ops);
char *do_op(char *first, int op, char *second, expr_params_t *par);

#endif
