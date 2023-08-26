#include <string.h>
#include <unistd.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    int j = 0;
    char *check = *strs;
    char *current;

    if (strsSize == 1)
        return *strs;
    while(check[j]) {
        for (int i = 1; i < strsSize; i++)
            if (strs[i][j] != check[j])
                goto solved;
        j++;
    }

solved:
    return strndup(*strs, j);
}
