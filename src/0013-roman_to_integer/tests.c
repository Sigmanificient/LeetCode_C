#include <stdlib.h>
#include <criterion/criterion.h>

int roman_too_int(char *s);

Test(roman_too_int, test_case_1)
{
    cr_assert_eq(roman_too_int("III"), 3);
}

Test(roman_too_int, test_case_2)
{
    cr_assert_eq(roman_too_int("LVIII"), 58);
}

Test(roman_too_int, test_case_3)
{
    cr_assert_eq(roman_too_int("MCMXCIV"), 1994);
}
