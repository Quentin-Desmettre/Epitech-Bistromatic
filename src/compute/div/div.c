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
        *ten_n = mul(*ten_n, "10");
        *ten_n_b = mul(*ten_n_b, "10");
        free(tmp_n);
        free(tmp);
    }
}

void search_who_is_upper_c(char **ten_n_b, char *r, int *c)
{
    while (my_strcmp(*ten_n_b, r) <= 0) {
        ten_n_b = mul(*ten_n_b, *c);
        *c += 1;
    }
}

void replace_add()
{

}

void replace_sub()
{

}

char *div(char *a, char *b)
{
    char *q = "0";
    char *r = a;
    char *ten_n_b = b;
    char *ten_n = "1";
    int c = 1;

    if (my_strcmp(sec, "0") == 0) {
        write(2, "error", 5);
        exit;
    }
    while (my_strcmp(r, sec) >= 0) {
        search_who_is_upper_n(&ten_n, &ten_n_b, r);
        search_who_is_upper_c(&ten_n_b, r, &c);
        replace_add(q, ten_n, c);
        replace_sub(r, ten_n_b, c);
    }
}

int main(int ac, char **argv)
{
    if (ac == 3)
        div(argv[1], argv[2]);
    return (0);
}
