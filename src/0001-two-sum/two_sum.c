#include <stdlib.h>

#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define UNUSED ATTR(unused)
#define USED ATTR(used)

int *two_sum(
    UNUSED int *nums,
    UNUSED int nums_size,
    UNUSED int target,
    UNUSED int *return_size
)
{
    return NULL;
}

int *twoSum() USED ALIAS("two_sum");
