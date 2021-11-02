/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/
#include "stdlib.h"
#include "unistd.h"
#include "bistromatic.h"

void search_who_is_upper_n(char **ten_n, char **result, char *r)
{
    char *tmp;
    char *tmp_n;

    while (my_strcmp(*result, r) <= 0) {
        tmp = *result;
        tmp_n = *ten_n;
        *ten_n = mul(*ten_n, "10");
        *result = mul(*result, "10");
        free(tmp_n);
        free(tmp);
    }
}

void search_who_is_upper_c();

char *div(char *a, char *b)
{
    char *q = "0";
    char *r = a;
    char *c = "0";
    char *ten_n_b = b;
    char *ten_n = "1";

    if (my_strcmp(sec, "0") == 0) {
        write(2, "error", 5);
        exit;
    }
    while (my_strcmp(r, sec) >= 0) {
        search_who_is_upper_n(&ten_n, &ten_n_b, r);
        search_who_is_upper_c()
    }
}

int main(int ac, char **argv)
{
    if (ac == 3)
        div(argv[1], argv[2]);
    return (0);
}
