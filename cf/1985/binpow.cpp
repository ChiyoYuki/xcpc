long long binpow(long long base, long long exp, long long mod)
{
    long long ans = 1;
    base %= mod;
    while (exp)
    {
        if (exp & 1LL)
            ans = ans * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return ans;
}

long long binpow(long long base, long long exp)
{
    long long ans = 1;
    while (exp)
    {
        if (exp & 1LL)
            ans *= base;
        base *= base;
        exp >>= 1;
    }
    return ans;
}