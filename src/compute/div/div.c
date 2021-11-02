/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include "stdlib.h"
#include "unistd.h"
#include "bistromatic.h"

void append_char(char **str, char c, int is_free)
{
    char *tmp = *str;
    int len = my_strlen(tmp) + 1;
    char *new = malloc(sizeof(char) * (len + 1));

    my_strcpy(new, tmp);
    new[len - 1] = c;
    new[len] = '\0';
    if (is_free)
        free(tmp);
    *str = new;
}

void search_who_is_upper_n(char **ten_n, char **ten_n_b, char *r,
                           expr_params_t *par)
{
    char *tmp;
    int len = my_strlen(*ten_n_b);

    while (my_nbr_cmp(*ten_n_b, r, par->base) <= 0) {
        append_char(ten_n, '0', 1);
        append_char(ten_n_b, '0', 1);
    }
    len = my_strlen(*ten_n_b);
    if (len > 1)  {
        *ten_n_b[len - 1] = '\0';
    }
}

void search_who_is_upper_c(char **ten_n_bc, char *r, int *c, expr_params_t *par)
{
    char *c_char;
    int len = my_strlen(*ten_n_bc);

    while (my_nbr_cmp(*ten_n_bc, r, par->base) <= 0) {
        int_to_str(*c, &c_char);
        *ten_n_bc = infin_mul(*ten_n_bc, c_char, par->base, par->ops);
        *c += 1;
    }
    len = my_strlen(*ten_n_bc);
    if (len > 1)  {
        *ten_n_bc[len - 1] = '\0';
    }
}

void replace_add(char **q, char *ten_n, int c, expr_params_t *par)
{
    char *c_char;

    int_to_str(c, &c_char);
    ten_n = infin_mul(ten_n, c_char, par->base, par->ops);
    *q = infin_add(*q, ten_n, par->base, par->ops);
}

void replace_sub(char **r, char *ten_n_bc, expr_params_t *par)
{
    *r = infin_sub(*r, ten_n_bc, par->base, par->ops);
}

char *infin_div(char *a, char *b, char *base, char *ops)
{
    char *q = "0";
    char *r = a;
    char *ten_n_b = b;
    char *ten_n = "1";
    char *ten_n_bc = "1";
    int c = 1;
    expr_params_t par = {0, base, ops};

    if (my_strcmp(b, "0") == 0) {
        write(2, "error", 5);
        exit(84);
    }
    while (my_strcmp(r, b) >= 0) {
        search_who_is_upper_n(&ten_n, &ten_n_b, r, &par);
        search_who_is_upper_c(&ten_n_bc, r, &c, &par);
        replace_add(&q, ten_n, c, &par);
        replace_sub(&r, ten_n_bc, &par);
    }
    printf("\n%s\n", q);
    return (q);
}

