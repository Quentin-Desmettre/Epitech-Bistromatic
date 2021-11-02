/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include "stdlib.h"
#include "unistd.h"
#include "bistromatic.h"

void search_who_is_upper_n(char **ten_n, char **ten_n_b, char *r)
{
    char *tmp;
    char *tmp_n;

    while (my_strcmp(*ten_n_b, r) <= 0) {
        tmp = *ten_n_b;
        tmp_n = *ten_n;
        *ten_n = infin_mul(*ten_n, "10");
        *ten_n_b = infin_mul(*ten_n_b, "10");
        free(tmp_n);
        free(tmp);
    }
}

void search_who_is_upper_c(char **ten_n_bc, char *r, int *c)
{
    char *c_char;

    while (my_strcmp(*ten_n_bc, r) <= 0) {
        int_to_str(*c, *c_char);
        *ten_n_bc = infin_mul(*ten_n_bc, c_char);
        *c += 1;
    }
}

void replace_add(char **q, char *ten_n, int c)
{
    char *c_char;

    int_to_str(c, *c_char);
    ten_n = infin_mul(ten_n, c_char);
    *q = infin_add(*q, ten_n);
}

void replace_sub(char **r, char *ten_n_bc)
{
    *r = infin_sub(*r, ten_n_bc);
}

char *infin_div(char *a, char *b)
{
    char *q = "0";
    char *r = a;
    char *ten_n_b = b;
    char *ten_n = "1";
    char *ten_n_bc = "1";
    int c = 1;

    if (my_strcmp(sec, "0") == 0) {
        write(2, "error", 5);
        exit;
    }
    while (my_strcmp(r, b) >= 0) {
        search_who_is_upper_n(&ten_n, &ten_n_b, r);
        search_who_is_upper_c(&ten_n_bc, r, &c);
        replace_add(&q, ten_n, c);
        replace_sub(&r, ten_n_bc);
    }
    my_putstr(q);
    my_putchar('\n');
    my_putstr(r);
    my_putchar('\n');
    return (q);
}

