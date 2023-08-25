#include <criterion/criterion.h>

char *longestCommonPrefix(char **strs, int strsSize);

Test(longestCommonPrefix, test_case_1)
{
    char *out;
    char *in[3] = {
        "flower",
        "flow",
        "flight"
    };

    out = longestCommonPrefix((char **)in, 3);
    cr_assert_str_eq(out, "fl");
    free(out);
}

Test(longestCommonPrefix, test_case_2)
{
    char *out;
    char *in[3] = {
        "dog",
        "racecar",
        "car"
    };

    out = longestCommonPrefix((char **)in, 3);
    cr_assert_str_eq(out, "");
    free(out);
}
