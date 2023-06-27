#include <stdlib.h>

#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define USED ATTR(used)

const int RETURN_SIZE = 2;

static inline
int *populate(int *out, int left, int right)
{
    out[0] = left;
    out[1] = right;
    return out;
}

int *two_sum(
    const int *nums,
    int nums_size,
    int target,
    int *return_size
)
{
    int *out = malloc(RETURN_SIZE * sizeof (int));

    if (out == NULL)
        return NULL;
    *return_size = RETURN_SIZE;
    for (int i = 0; i < nums_size; i++)
        for (int j = 0; j < nums_size; j++)
            if (i != j && nums[i] + nums[j] == target)
                return populate(out, i, j);
    return NULL;
}

int *twoSum() USED ALIAS("two_sum");
