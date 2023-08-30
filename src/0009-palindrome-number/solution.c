#include <stdbool.h>

static
int ndigit(int x, int pos)
{
    while (pos--)
        x /= 10;
    return x % 10;
}

bool isPalindrome(int x)
{
    int len = 0;
    int copy = x;

    if (x < 10)
        return x > 0;
    while (copy) {
        copy /= 10;
        len++;
    }
    for (int i = 0; i < len >> 1; i++)
       if (ndigit(x, i) != ndigit(x, len - i - 1))
           return false; 
    return true;
}
