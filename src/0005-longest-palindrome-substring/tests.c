#include "criterion/assert.h"
#include "string.h"
#include <criterion/criterion.h>

char *longestPalindrome(char *s);

void test_palindrome(char *in, char *out)
{
    char *copy = strdup(in);
    char *res;

    if (copy == NULL)
        cr_skip("Allocation Failure");
    res = longestPalindrome(copy);
    if (res == NULL)
        cr_skip("Allocation Failure");

    cr_assert_str_eq(res, out);
    free(copy);
    free(res);
}

Test(longestPalindrome, test_case_1)
{
    test_palindrome("babad", "bab");
}

Test(longestPalindrome, test_case_2)
{
    test_palindrome("cbbd", "bb");
}

Test(longestPalindrome, test_case_3)
{
    test_palindrome("radar", "radar");
}
