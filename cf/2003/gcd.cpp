long long gcd(long long x, long long y)
{
    long long z;
    x = abs(x);
    y = abs(y);
    if (x > y)
        swap(x, y);
    if (x == 0)
        return y;
    else
        while (x % y != 0)
        {
            z = x % y;
            x = y;
            y = z;
        }
    return y;
}