/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** prototypes for infin computations
*/

#ifndef INFIN_H
    #define INFIN_H

char *infin_add(char *fir, char *sec, char *base, char *ops);
char *infin_sub(char *fir, char *sec, char *base, char *ops);
char *my_add(char *first, char *second, char *base, char *ops);
char *my_sub(char *first, char *second, int rec, expr_params_t *par);

#endif