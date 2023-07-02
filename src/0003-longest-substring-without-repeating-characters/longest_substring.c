#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(x, y) ((x > y) ? (x) : (y))

#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define USED ATTR(used)

enum { SENTINEL = -1 };

int uniq_chain(const char *str, size_t len, char *pool)
{
    bool found;
    int count = 0;
    size_t pool_last = 0;

    memset(pool, 0, len);
    for (size_t i = 0; str[i]; i++) {
        found = false;
        for (size_t j = 0; j < pool_last; j++) {
            if (pool[j] == str[i]) {
                found = true;
                break;
            }
        }
        if (found)
            return count;
        pool[pool_last++] = str[i];
        count++;
    }
    return count;
}

int length_of_longest_substring(char *str)
{
    int count = 0;
    size_t len = strlen(str);
    char *pool = malloc(len * sizeof (char));

    if (pool == NULL)
        return SENTINEL;
    for (size_t i = 0; i < len; i++)
        count = MAX(count, uniq_chain(str + i, len - i, pool));
    free(pool);
    return count;
}

int lengthOfLongestSubstring() USED ALIAS("length_of_longest_substring");
