/*
** EPITECH PROJECT, 2021
** div
** File description:
** div
*/

char *div(char *fir, char *sec, char *base, char *ops)
{
    char *result;
    char *tmp;
    expr_params_t par = {0, base, ops};

    
}

int main(int ac, char **argv)
{
    if (ac == 3)
        div(argv[1], argv[2]);
    return (0);
}
