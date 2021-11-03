#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bistromatic.h"

Test (check_expr_others, count_occurence, .init=redirect_all_stdout)
{
    cr_assert(count_occurences('z', "") == 0);
    cr_assert(count_occurences('z', "zalut les zamis") == 2);
    cr_assert(count_occurences('z', "zzzzz zzzzz dodo") == 10);
}

Test (check_expr_others, check_redundancy, .init=redirect_all_stdout)
{
    
}