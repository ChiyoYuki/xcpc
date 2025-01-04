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
    template <typename __Tp>
    void ask(__Tp a, __Tp b);
    void ans(ll a);
    void ans(str s);
    void ans(vll a);
}

ull gcd(ull x, ull y)
{
    ull z = 1LL;
    if (x < y)
        swap(x, y);
    if (y == 0)
        return x;
    else
        while (x % y != 0)
        {
            z = x % y;
            x = y;
            y = z;
        }
    return y;
}

void solve(void)
{
    ull i = 0, j = 0;
    ull n = 0, m = 0;
    ull sum = 0;
    ull l, r, g;
    ull a, b;
    cin >> l >> r >> g;
    a = l / g;
    if (l % g != 0)
        a++;
    a *= g;
    b = r / g;
    b *= g;
    for (; a <= r; a += g)
    {
        for (b = r / g * g; b >= a; b -= g)
        {
            if (gcd(a, b) == g)
            {
                cout << a << ' ' << b << '\n';
                return;
            }
        }
    }
    cout << "-1 -1";
    // cin>>n;
    // vll a(n);
    // for(i=0;i<n;i++) cin>>a[i];

    cout << '\n';
    return;
}

/*

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

template <typename __Tp>
void i11e::ask(__Tp a, __Tp b)
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