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

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = -1;
    ll t;
    cin >> n;
    vll a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            if (i > 2)
            {
                cout << a[i] << ' ' << a[i - 1] << ' ' << a[i - 2] << ' ' << a[i - 3] << '\n';
                return;
            }
            else
            {
                sum = a[i];
                t = i;
            }
        }
    }
    if (sum != -1)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (t == 2 && i == 0)
            {
                if (a[0] + 2 * sum > a[3])
                {
                    cout << a[0] << ' ' << a[3] << ' ' << sum << ' ' << sum << '\n';
                    return;
                }
                else
                    i = 2;
            }
            else if (i == 0 && t == 1)
                i = 1;
            else if (i == t)
                continue;
            else if (a[i] + 2 * sum > a[i + 1])
            {
                cout << a[i] << ' ' << a[i + 1] << ' ' << sum << ' ' << sum << '\n';
                return;
            }
        }
    }
    cout << -1;
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
