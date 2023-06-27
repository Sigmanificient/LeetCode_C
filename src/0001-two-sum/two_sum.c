#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "hashmap.h"

#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define USED ATTR(used)

const int RETURN_SIZE = 2;
const int SENTINEL = -1;

int *two_sum(
    const int *nums,
    int nums_size,
    int target,
    int *return_size
)
{
    hashmap_t *hm;
    int *out = malloc(RETURN_SIZE * sizeof (int));
    int complement;
    int hm_val;

    *return_size = 0;
    if (out == NULL)
        return NULL;
    hm = hashmap_create(nums_size);
    if (hm == NULL) {
        free(out);
        return NULL;
    }
    for (int i = 0; i < nums_size; i++) {
        complement = target - nums[i];
        hm_val = hashmap_get(hm, complement, SENTINEL);
        if (hm_val != SENTINEL) {
            out[0] = hm_val < i ? hm_val : i;
            out[1] = hm_val > i ? hm_val : i;
            hashmap_destroy(hm);
            *return_size = RETURN_SIZE;
            return out;
        }
        if (!hashmap_insert(hm, nums[i], i)) {
            hashmap_destroy(hm);
            free(out);
            return NULL;
        }
    }
    return NULL;
}

int *twoSum() USED ALIAS("two_sum");
