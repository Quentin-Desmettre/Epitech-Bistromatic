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
    char *tmp = my_strdup(*ten_n);
    char *tmp_n = my_strdup(*ten_n_b);
    int len = my_strlen(*ten_n_b);

    while (my_nbr_cmp(tmp_n, r, par->base) <= 0) {
        append_char(&tmp, '0', 1);
        append_char(&tmp_n, '0', 1);
    }
    len = my_strlen(tmp_n);
    if (len > 1)
        tmp_n[len - 1] = '\0';
    len = my_strlen(tmp);
    if (len > 1)
        tmp[len - 1] = '\0';
    *ten_n = tmp;
    *ten_n_b = tmp_n;
}

char *search_who_is_upper_c(char *ten_n_b, char *r, int *c, expr_params_t *par)
{
    char *c_char;
    char *ten_n_bc = ten_n_b;

    for (int i = 2; my_nbr_cmp(ten_n_bc, r, par->base) <= 0; i++) {
        int_to_str(i, &c_char);
        ten_n_bc = infin_mul(ten_n_b, c_char, par->base, par->ops);
        int_to_str(i - 1, &c_char);
    }
    *c = my_getnbr(c_char);
    ten_n_bc = infin_mul(ten_n_b, c_char, par->base, par->ops);
    return (ten_n_bc);
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
    char *q = my_strdup("0");
    char *r = my_strdup(a);
    char *ten_n_b = my_strdup(b);
    char *ten_n = my_strdup("1");
    char *ten_n_bc = my_strdup("1");
    int c = 1;
    expr_params_t par = {0, base, ops};

    if (my_strcmp(b, "0") == 0) {
        write(2, "error", 5);
        exit(84);
    }
    while ((my_nbr_cmp(r, b, base) >= 0) && r[0] != '-') {
        ten_n_b = my_strdup(b);
        ten_n = my_strdup("1");
        ten_n_bc = my_strdup("1");
        search_who_is_upper_n(&ten_n, &ten_n_b, r, &par);
        ten_n_bc = search_who_is_upper_c(ten_n_b, r, &c, &par);
        replace_add(&q, ten_n, c, &par);
        replace_sub(&r, ten_n_bc, &par);
    }
    return (q);
}

