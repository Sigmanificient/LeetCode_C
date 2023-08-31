double myPow(double x, int n)
{
    double res = 1;

    if (n == 0 || x == 1)
        return 1;
    if (n < 0) {
        n += 1;
        // Pre-compute once to avoid overflow
        x = 1 / x;
        res *= x;
        n = -1 * n;
    }
    // Binary Exponentiation
    while (n) {
        if (n & 1) {
            res *= x;
            n -= 1;
        }
        x *= x;
        n /= 2;
    }
    return res;
}
