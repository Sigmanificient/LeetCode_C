#include <stdbool.h>
#include <criterion/criterion.h>

bool isPalindrome(int x);

Test(isPalindrome, test_case_1)
{
    cr_assert(isPalindrome(121));
}

Test(isPalindrome, test_case_2)
{
    cr_assert_not(isPalindrome(-121));
}

Test(isPalindrome, test_case_3)
{
    cr_assert_not(isPalindrome(10));
}
