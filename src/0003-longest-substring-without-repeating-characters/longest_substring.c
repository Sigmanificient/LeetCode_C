#include <string.h>
#include <limits.h>

#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define USED ATTR(used)

int length_of_longest_substring(char *str)
{
    int left = -1;
    int longest = 0;
    int len = (int)strlen(str);
    int hashmap[CHAR_MAX];
    int *index;

    memset(hashmap, -1, CHAR_MAX * sizeof(int));
    for (int i = 0; i < len; i++) {
        index = hashmap + (unsigned char)str[i];
        if (*index > left)
            left = *index;
        *index = i;
        if (i - left > longest)
            longest = i - left;
    }
    return longest;
}

int lengthOfLongestSubstring() USED ALIAS("length_of_longest_substring");
