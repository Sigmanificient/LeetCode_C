#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static inline
bool check_palindrome(char *s, size_t len)
{
    for (size_t i = 0; i < (len / 2); i++)
        if (s[i] != s[len - i - 1])
            return false;
    return true;
}

char *longestPalindrome(char *s)
{
    char *out;
    char *pal = s;
    size_t len = strlen(s);
    size_t pal_len = 1;

    for (size_t i = 0; i < len; i++) {
        for (size_t j = 2; j <= len - i; j++) {
            if (!check_palindrome(s + i, j))
                continue;

            if (j > pal_len) {
                pal = s + i;
                pal_len = j;
            }
        }
    }
    out = malloc((pal_len + 1) * sizeof(char));
    if (out == NULL)
        return NULL;
    memcpy(out, pal, pal_len);
    out[pal_len] = '\0';
    return out;
}
