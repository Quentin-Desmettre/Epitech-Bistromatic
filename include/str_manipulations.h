/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** prototypes for string manips
*/

#ifndef STR_MANIPULATIONS_H
    #define STR_MANIPULATIONS_H

void init_with(char *str, char c, int nb);
void insert_at_beg(char **str, char what, int nb);
int my_nbr_cmp(char *first, char *second, char *base);
char *clean_str(char *str, char *base, char *ops);
int index_of(char, char *);

#endif
