#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

unsigned const char SYMBOLS[CHAR_MAX] = {
    [ '(' ] = 0b01,
    [ ')' ] = 0b01,
    [ '{' ] = 0b10,
    [ '}' ] = 0b10,
    [ '[' ] = 0b11,
    [ ']' ] = 0b11,
};

#define CHAR_BITS (sizeof(unsigned char) * 8)

static inline
void set_ptr(unsigned char *x, int offset, char val)
{
    div_t q = div(2 * offset, CHAR_BITS);
    int k = (CHAR_BITS - 2 - q.rem);

    x[q.quot] &= ~(0b11 << k);
    x[q.quot] |= (val & 0b11) << k;
}


static inline
char get_ptr(unsigned char *x, int offset)
{
    div_t q = div(2 * offset, CHAR_BITS);

    return (x[q.quot] >> (CHAR_BITS - 2 - q.rem)) & 0b11;
}

bool analyze_string(char *s, size_t slen, unsigned char *x)
{
    int offset = 0;

    while (*s) {
        if ((*s & 0b11) == 1) { // )}]
            offset--;
            if (offset < 0)
                return false;
            if (get_ptr(x, offset) != SYMBOLS[(unsigned char)*s])
                return false;
        } else {
            if ((size_t)offset >= slen)
                return false;
            set_ptr(x, offset, SYMBOLS[(unsigned char)*s]);
            offset++;
        }
        s++;
    }
    return !offset;
}

bool isValid(char *s)
{
    size_t slen = ((strlen(s) + CHAR_BITS) << 1) / (CHAR_BITS >> 1);
    unsigned char *x = malloc(slen * sizeof(unsigned char));
    bool res;

    if (x == NULL)
        return NULL;
    res = analyze_string(s, slen, x);
    free(x);
    return res;
}

