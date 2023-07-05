#include <limits.h>
#include <string.h>

#define ATTR(key) __attribute__((key))
#define ALIAS(name) ATTR(alias(name))
#define USED ATTR(used)

const int ROMAN_CHAR_VALUES[CHAR_MAX] = {
    [ 'I' ] = 1,
    [ 'V' ] = 5,
    [ 'X' ] = 10,
    [ 'L' ] = 50,
    [ 'C' ] = 100,
    [ 'D' ] = 500,
    [ 'M' ] = 1000,
};

int roman_too_int(char *s)
{
    return 0;
}

int romanTooInt() USED ALIAS("find_median_sorted_arrays");