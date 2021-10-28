/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** get previous and next number
*/

#include <stdlib.h>
#include "include/strmanip.h"
#include "include/evalexpr.h"

static int len_to_prev(char *str, int start)
{
    int i = start - 1;
    int len = 0;

    while (i >= 0) {
    if (str[i] <= '9' && str[i] >= '0')
            len++;
        else if (str[i] == '-' && (!i || is_op(str[i - 1])))
            len++;
        else
            break;
        i--;
    }
    return len;
}

static int len_to_next(char *str, int start)
{
    int i = start + 1;
    int len = 0;

    while (1) {
        if (str[i] && str[i] <= '9' && str[i] >= '0')
            len++;
        else if (str[i] == '-' && (!i || is_op(str[i - 1])))
            len++;
        else
            break;
        i++;
    }
    return len;
}

char *get_next_number(char *str, int start)
{
    int len = len_to_next(str, start);
    char *num = malloc(sizeof(char) * len + 1);
    int i = start + 1;

    while (1) {
        if (str[i] && str[i] <= '9' && str[i] >= '0')
            num[i - start - 1] = str[i];
    else if (str[i] == '-' && (!i || is_op(str[i - 1])))
            num[i - start - 1] = str[i];
        else
            break;
        i++;
    }
    num[len] = '\0';
    return num;
}

char *get_prev_number(char *str, int start)
{
    int len = len_to_prev(str, start);
    char *num = malloc(sizeof(char) * len + 1);
    int i = start - 1;
    int j = 0;

    while (i >= 0) {
        if (str[i] <= '9' && str[i] >= '0')
            num[j] = str[i];
        else if (str[i] == '-' && (i == 0 || is_op(str[i - 1])))
            num[j] = str[i];
        else
            break;
        i--;
        j++;
    }
    num[len] = '\0';
    my_revstr(num);
    return num;
}
