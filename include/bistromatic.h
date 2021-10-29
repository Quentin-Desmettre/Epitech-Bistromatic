/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** header for bistromatic
*/

#ifndef BISTROMATIC_H
    #define BISTROMATIC_H
    #define OPEN_PARENT_IDX 0
    #define CLOSE_PARENT_IDX 1
    #define PLUS_IDX 2
    #define SUB_IDX 3
    #define NEG_IDX 3
    #define MULT_IDX 4
    #define DIV_IDX 5
    #define MOD_IDX 6
    #define EXIT_USAGE 84
    #define EXIT_BASE 84
    #define EXIT_SIZE_NEG 84
    #define EXIT_MALLOC 84
    #define EXIT_READ 84
    #define EXIT_OPS 84
    #define EXIT_SYNTAX_ERROR 84
    #define EXIT_SUCCESS 0
    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG "error"

typedef struct int_pair {
    int a;
    int b;
} int_pair_t;

void check_all(int ac, char **av);
void check_expr(char const *str, char const *base, char const *ops);
void usage(void);
void cleanex(char **expr, char *base, char *ops);
char *evaluate(char *expr, char *base, char *ops);
char *get_next_number(char *str, int start, char *base, char *ops);
char *get_prev_number(char *str, int start, char *base, char *ops);
char *do_op(char *first, int op, char *second, char *base, char *ops);
int str_is_num(char const *str);
void init_with(char *str, char c, int nb);
void insert_at_beg(char **str, char what, int nb);
int my_nbr_cmp(char *first, char *second, char *base);
char *clean_str(char *str, char *base, char *ops);
int index_of(char, char *);
char *infin_add(char *fir, char *sec, char *base, char *ops);
char *infin_sub(char *fir, char *sec, char *base, char *ops);
char *my_add(char *, char *, char *, char *);
char *my_sub(char *, char *, int, char *, char *);

#endif
