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

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;

    cin >> n >> m;
    if (n >= m)
    {
        cout << "YES\n";
        for (i = 0; i < 2 * n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                cout << j << ' ';
            }
            cout << '\n';
        }
    }
    elif (m <= 2 * n)
    {
        cout << "YES\n";
        vvll ans(2 * n, vll(m, 0));
        ll x, y;
        for (i = 0; i < n; i++)
        {
            x = i * 2;
            y = 0;
            for (j = 0; j < m; j++)
            {
                ans[x % (2 * n)][y % m] = i + 1;
                ans[(x + 1) % (2 * n)][y % m] = i + 1;
                x++;
                y++;
            }
        }
        for (i = 0; i < 2 * n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else cout << "NO\n";
    return;
}

/*
  1 2 3 4
1 1 3 3 2
2 1 1 3 3
3 2 1 1 3
4 2 2 1 1
5 3 2 2 1
6 3 3 2 2

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