#include <criterion/criterion.h>

int *two_sum(int *nums, int nums_size, int target, int *return_size);

typedef struct {
    int *nums;
    int num_size;
    int target;
    int *expect;
} test_data_t;


void test_method(test_data_t *td)
{
    int return_size;
    int *out = two_sum(td->nums, td->num_size, td->target, &return_size);

    if (out == NULL)
        cr_skip("Allocation Failure.");
    cr_assert_eq(return_size, 2);
    for (int i = 0; i < return_size; i++)
        cr_assert_eq(out[i], td->expect[i]);
    free(out);
}

Test(two_sum, test_case_1)
{
    test_method(&(test_data_t){
        .target = 9,
        .nums = (int []){2, 7, 11, 15},
        .num_size = 4,
        .expect = (int []){0, 1}
    });
}

Test(two_sum, test_case_2)
{
    test_method(&(test_data_t){
        .target = 6,
        .nums = (int []){3, 2, 4},
        .num_size = 3,
        .expect = (int []){1, 2}
    });
}

Test(two_sum, test_case_3)
{
    test_method(&(test_data_t){
        .target = 6,
        .nums = (int []){3, 3},
        .num_size = 2,
        .expect = (int []){0, 1}
    });
}
