/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include "stdlib.h"
#include "unistd.h"
#include "bistromatic.h"
#include "div.h"
#define PRECISION 15

void search_who_is_upper_n(char **ten_n, char **ten_n_b, char *r,
    expr_params_t *par)
{
    char *tmp = my_strdup(*ten_n);
    char *tmp_n = my_strdup(*ten_n_b);
    int len = my_strlen(*ten_n_b);

    while (my_nbr_cmp(tmp_n, r, par->base) <= 0) {
        append_char(&tmp, par->base[0], 1);
        append_char(&tmp_n, par->base[0], 1);
    }
    len = my_strlen(tmp_n);
    if (len > 1)
        tmp_n[len - 1] = '\0';
    len = my_strlen(tmp);
    if (len > 1)
        tmp[len - 1] = '\0';
    free(*ten_n_b);
    free(*ten_n);
    *ten_n = tmp;
    *ten_n_b = tmp_n;
}

char *search_who_is_upper_c(char *ten_n_b, char *r, int *c, expr_params_t *par)
{
    char *c_char = my_strdup("For free");
    char *ten_n_bc = NULL;

    ten_n_bc = my_strdup(ten_n_b);
    for (int i = 2; my_nbr_cmp(ten_n_bc, r, par->base) <= 0; i++) {
        free(ten_n_bc);
        free(c_char);
        int_to_str(i, &c_char);
        ten_n_bc = infin_mul(ten_n_b, c_char, par->base, par->ops);
        free(c_char);
        int_to_str(i - 1, &c_char);
    }
    *c = my_getnbr(c_char);
    free(ten_n_bc);
    ten_n_bc = infin_mul(ten_n_b, c_char, par->base, par->ops);
    free(c_char);
    return (ten_n_bc);
}

void replace_add(char **q, char *ten_n, int c, expr_params_t *par)
{
    char *c_char;
    char *ten_n_c;

    int_to_str(c, &c_char);
    ten_n_c = infin_mul(ten_n, c_char, par->base, par->ops);
    free(c_char);
    re_alloc(q, infin_add(*q, ten_n_c, par->base, par->ops), 1);
    free(ten_n_c);
}

char *my_div(char *a, char *b, char *base, char *ops, int decimal)
{
    char *q = char_to_str(base[0]);
    char *r = my_strdup(a);
    char *ten_n_b = NULL;
    char *ten_n = NULL;
    char *ten_n_bc = NULL;
    int c = 1;
    expr_params_t par = {0, base, ops};

    error_inf_div(b, base);
    while ((my_nbr_cmp(r, b, base) >= 0) && r[0] != ops[3]) {
        ten_n_b = my_strdup(b);
        ten_n = char_to_str(base[1]);
        search_who_is_upper_n(&ten_n, &ten_n_b, r, &par);
        ten_n_bc = search_who_is_upper_c(ten_n_b, r, &c, &par);
        replace_add(&q, ten_n, c, &par);
        replace_sub(&r, ten_n_bc, &par);
        free_all(ten_n_b, ten_n, ten_n_bc);
    }
    if (decimal)
        //compute_decimal_part(&q, r, b, PRECISION, base, ops);
        free(r);
    return (q);
}

char *infin_div(char *a, char *b, char *base, char *ops)
{
    char *result;

    if (a[0] == ops[3] && b[0] == ops[3])
        result = my_div(a + 1, b + 1, base, ops, 1);
    if (a[0] != ops[3] && b[0] != ops[3])
        result = my_div(a, b, base, ops, 1);
    if (a[0] == ops[3] && b[0] != ops[3]) {
        result = my_div(a + 1, b, base, ops, 1);
        insert_at_beg(&result, ops[3], 1, 1);
    }
    if (a[0] != ops[3] && b[0] == ops[3]) {
        result = my_div(a, b + 1, base, ops, 1);
        insert_at_beg(&result, ops[3], 1, 1);
    }
    return (result);
}
