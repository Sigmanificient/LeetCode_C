#include <stdlib.h>
#include <criterion/criterion.h>

enum { SENTINEL = -1 };
int length_of_longest_substring(char * s);

Test(longest_substring, test_case_1)
{
    int actual = length_of_longest_substring("abcabcbb");

    if (actual == SENTINEL)
        cr_skip("Allocation Failure.");
    cr_assert_eq(actual, 3, "actual:%d vs %d", actual, 3);
}

Test(longest_substring, test_case_2)
{
    int actual = length_of_longest_substring("bbbbb");

    if (actual == SENTINEL)
        cr_skip("Allocation Failure.");
    cr_assert_eq(actual, 1, "actual:%d vs %d", actual, 1);
}

Test(longest_substring, test_case_3)
{
    int actual = length_of_longest_substring("pwwkew");

    if (actual == SENTINEL)
        cr_skip("Allocation Failure.");
    cr_assert_eq(actual, 3, "actual:%d vs %d", actual, 3);
}

Test(longest_substring, test_case_4)
{
    int actual = length_of_longest_substring(" ");

    if (actual == SENTINEL)
        cr_skip("Allocation Failure.");
    cr_assert_eq(actual, 1, "actual:%d vs %d", actual, 1);
}
