#include <criterion/criterion.h>

bool isValid(char *s);

Test(isValid, test_case_1)
{
    cr_assert(isValid("()"));
}

Test(isValid, test_case_2)
{
    cr_assert(isValid("()[]{}"));
}

Test(isValid, test_case_13)
{
    cr_assert_not(isValid("(]"));
}

Test(isValid, complex_screnario)
{
    cr_assert(isValid("{[()]()}{()}"));
    cr_assert_not(isValid("({[()]()}{()}"));
}
