#include <limits.h>

int reverse(int x)
{
    int ax = x;
    int rev = 0;

    if (ax > 0)
        ax = -ax;
    while (ax != 0) {
        if (rev > (INT_MAX / 10))
            return 0;
        rev *= 10;
        if ((INT_MIN + rev) > (ax % 10))
            return 0;
        rev -= ax % 10;
        ax /= 10;
    }
    return (x < 0) ? -rev : rev;
}
