#include <stdbool.h>

#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define USED ATTR(used)

double find_median_sorted_arrays(const int *a, int a_size, const int *b, int b_size)
{
    int len = a_size + b_size;
    int i = 0;
    int j = 0;
    double res;
    bool odd = len & 1;

    for (int k = 0; k < (len >> 1) - !odd; k++) {
        if (i == a_size || (j != b_size && a[i] > b[j]))
            j++;
        else
            i++;
    }
    if (i == a_size || (j != b_size && a[i] > b[j]))
        res = b[j++];
    else
        res = a[i++];
    if (odd)
        return res;
    if (i == a_size || (j != b_size && a[i] > b[j]))
        res += b[j++];
    else
        res += a[i++];
    return res / 2;
}

int findMedianSortedArrays() USED ALIAS("find_median_sorted_arrays");
