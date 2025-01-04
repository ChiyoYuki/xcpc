/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define elif else if

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef pair<ll, ll> pll2;
typedef priority_queue<ll> pqll;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll2;
typedef string str;

const int intinf = 0x3f3f3f3f;
const int mod9 = 998244353;
const int moda = 1000000007;

namespace i11e
{
    template <typename __Tp>
    void ask(__Tp a);
    template <typename __Tp0, typename __Tp1>
    void ask(__Tp0 a, __Tp1 b);
    void ans(ll a);
    void ans(str s);
    void ans(vll a);
}

long long binpow(long long base, long long exp, long long mod)
{
    if (base == 0)
        return 0;
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

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;
    ll l, r, k;
    cin >> l >> r >> k;
    ll per;
    ll kk = k;
    ll las = 0;
    while (kk)
    {
        if (kk % 10 == 0)
            las = 10;
        las = max(kk % 10, las);
        kk /= 10;
    }
    if (las == 1)
        per = 10;
    else if (las == 2)
        per = 5;
    else if (las == 3)
        per = 4;
    else if (las == 4)
        per = 3;
    else if (las != 10)
        per = 2;
    else
        per = 0;
    ll suml = binpow(per, l, moda);
    ll sumr = binpow(per, r, moda);
    sum = sumr - suml;
    while (sum < 0)
        sum += moda;
    sum %= moda;
    if (k >= 10)
        sum = 0;
    cout << sum;
    cout << '\n';
    return;
}

/*
10 11 12 20 21 22
6160 1
13
*/

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

template <typename __Tp>
void i11e::ask(__Tp a)
{
    cout << "? " << a << endl;
    cout.flush();
    return;
}

template <typename __Tp0, typename __Tp1>
void ask(__Tp0 a, __Tp1 b)
{
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    return;
}

void i11e::ans(ll a)
{
    cout << "! " << a << endl;
    cout.flush();
    return;
}

void i11e::ans(str s)
{
    cout << "! " << s << endl;
    cout.flush();
    return;
}

void i11e::ans(vll a)
{
    cout << "!";
    for (auto ii = a.begin(); ii != a.end(); ii++)
        cout << ' ' << (*ii);
    cout << endl;
    cout.flush();
    return;
}
