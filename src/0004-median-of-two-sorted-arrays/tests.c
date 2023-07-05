#include <stdlib.h>
#include <criterion/criterion.h>

double find_median_sorted_arrays(const int *a, int a_size, const int *b, int b_size);

Test(find_median_sorted_arrays, test_case_1)
{
    cr_assert_float_eq_op_(
        find_median_sorted_arrays(
            (int []){1, 3},
            2,
            (int []){2},
            1
        ), 2.0F, 0.0001
    );
}

Test(find_median_sorted_arrays, test_case_2)
{
    cr_assert_float_eq_op_(
        find_median_sorted_arrays(
            (int []){1, 2},
            2,
            (int []){3, 4},
            2
        ), 2.5F, 0.0001
    );
}
