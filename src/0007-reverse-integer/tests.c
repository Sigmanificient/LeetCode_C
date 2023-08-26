#include "criterion/assert.h"
#include <criterion/criterion.h>

int reverse(int);

Test(reverse, test_case_1)
{
    int x = 123;

    cr_assert_eq(reverse(x), 321);
}

Test(reverse, test_case_2)
{
    int x = -123;

    cr_assert_eq(reverse(x), -321);
}

Test(reverse, test_case_3)
{
    int x = 120;

    cr_assert_eq(reverse(x), 21);
}

Test(reverse, test_near_limit)
{
    int x = 1463847412;

    cr_assert_eq(reverse(x), 2147483641);
}

Test(reverse, long_number)
{
    int x = 1534236469;

    cr_assert_eq(reverse(x), 0);
}

Test(reverse, int_min)
{
    int x = -2147483648;

    cr_assert_eq(reverse(x), 0);
}
