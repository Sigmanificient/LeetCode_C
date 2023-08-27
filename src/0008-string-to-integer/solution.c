#include <ctype.h>
#include <limits.h>

#define LIMIT(sign) ((sign != '-') ? INT_MAX : INT_MIN)

int myAtoi(char *s)
{
    int num = 0;
    char sign = '+';

    while (isspace(*s))
        s++;
    if (*s == '+' || *s == '-')
        sign = *s++;
    while (isdigit(*s)) {
        if ((INT_MIN / 10) > (num))
            return LIMIT(sign);
        num *= 10;
        if ((INT_MIN + (*s & ~ '0')) > num)
            return LIMIT(sign);
        num -= *s++ & ~'0';
    }
    if (sign == '-')
        return num;
    if (num == INT_MIN)
        return INT_MAX;
    return -num;
}
