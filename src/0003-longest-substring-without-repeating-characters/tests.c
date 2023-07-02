#include <stdlib.h>
#include <criterion/criterion.h>

int length_of_longest_substring(char * s);

Test(longest_substring, test_case_1)
{
    cr_assert_eq(length_of_longest_substring("abcabcbb"), 3);
}

Test(longest_substring, test_case_2)
{
    cr_assert_eq(length_of_longest_substring("bbbbb"), 1);
}

Test(longest_substring, test_case_3)
{
    cr_assert_eq(length_of_longest_substring("pwwkew"), 3);
}
