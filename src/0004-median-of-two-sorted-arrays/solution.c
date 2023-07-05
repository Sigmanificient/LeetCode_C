#include <stdbool.h>

#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define USED ATTR(used)

double find_median_sorted_arrays(const int *a, int a_size, const int *b, int b_size)
{
    return 0;
}

int findMedianSortedArrays() USED ALIAS("find_median_sorted_arrays");
