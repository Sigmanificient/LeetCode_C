#include <criterion/criterion.h>

double myPow(double x, int n);

Test(myPow, test_case_1)
{
    cr_assert_eq(myPow(2.0L, 10), 1024.0L);
}

Test(myPow, test_case_2)
{
    cr_assert_float_eq(myPow(2.1L, 3), 9.261000L, 0.0001);
}

Test(myPow, test_case_3)
{
    cr_assert_float_eq(myPow(2.0L, -2), 0.25000L, 0.0001);
}

Test(myPow, test_case_4)
{
    cr_assert_float_eq(myPow(1.0000000000001, -2147483648), 0.999785L, 0.0001);
}
