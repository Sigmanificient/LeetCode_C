#include <criterion/criterion.h>

int myAtoi(char *s);

Test(myAtoi, digit_string)
{
    cr_assert_eq(myAtoi("42"), 42);
}

Test(myAtoi, leading_space_minus)
{
    cr_assert_eq(myAtoi("    -42"), -42);
}

Test(myAtoi, words_after_digits)
{
    cr_assert_eq(myAtoi("4193 with worlds"), 4193);
}
