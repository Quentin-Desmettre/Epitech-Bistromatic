#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (errors, arguments_len, .init=redirect_all_stdout)
{
    check_nb_args(3);
    cr_expect_stdout_eq_str(SYNTAX_ERROR_MSG);
}

Test (errors, base_len, .init=redirect_all_stdout)
{
    check_base("0123456789");
    cr_expect_stdout_eq_str("");
    check_base("0");
    cr_expect_stdout_eq_str(SYNTAX_ERROR_MSG, "");
    check_base("azbcdfghqtyeà987654321FKLMPOIUYH");
    cr_expect_stdout_eq_str("");
}

Test (errors, ops_len, .init=redirect_all_stdout)
{
    check_ops("()+-*/%");
    cr_expect_stdout_eq_str("");
    check_ops("abcdefg");
    cr_expect_stdout_eq_str("");
    check_ops("()+-*/");
    cr_expect_stdout_eq_str(SYNTAX_ERROR_MSG);
}
Test (errors, help, .init=redirect_all_stdout)
{
    char **array = my_str_to_word_array("a.out -h");
    check_help(2, array);
    cr_expect_stdout_eq_str("USAGE\n./calc base operators size_read\n\n"
    "DESCRIPTION\n- base: all the symbols of the base\n"
    "- operators: the symbols for the parentheses and the 5 operators\n"
    "- size_read: numbers of characters to be read\n", "");
    check_help(3, array);
    cr_expect_stdout_eq_str("");
    char **array_2 = my_str_to_word_array("a.out help");
    check_help(2, array_2);
    cr_expect_stdout_eq_str("");
}
Test (errors, all, .init=redirect_all_stdout)
{
    char **array = my_str_to_word_array("a.out -h");
    char **array_base = my_str_to_word_array("a.out 0123456 ()+-*/%");
    check_all(2, array);
    cr_expect_stdout_eq_str("USAGE\n./calc base operators size_read\n\n"
    "DESCRIPTION\n- base: all the symbols of the base\n"
    "- operators: the symbols for the parentheses and the 5 operators\n"
    "- size_read: numbers of characters to be read\n", "");
    check_all(3, array);
    cr_expect_stdout_eq_str(SYNTAX_ERROR_MSG, "");
    check_all(4, array_base);
    cr_expect_stdout_eq_str("", "");
    check_all(4, array_base);
    cr_expect_stdout_eq_str("", "");
}
