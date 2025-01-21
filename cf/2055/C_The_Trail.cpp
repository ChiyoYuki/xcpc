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
    ll sum = 0;
    str s;

    cin >> n >> m;
    cin >> s;
    vector<vpll2> a(n, vpll2(m));
    vpll2 row(n, make_pair(0, 0)), col(m, make_pair(0, 0));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j].nd;
            row[i].nd += a[i][j].nd;
            col[j].nd += a[i][j].nd;
        }
    }
    pll2 pos = make_pair(0, 0);
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == 'D')
        {
            a[pos.st][pos.nd].st = 1 - row[pos.st].st;
            a[pos.st][pos.nd].nd = 0 - row[pos.st].nd;
            col[pos.nd].st += a[pos.st][pos.nd].st;
            col[pos.nd].nd += a[pos.st][pos.nd].nd;
            pos.st++;
        }
        else
        {
            a[pos.st][pos.nd].st = 1 - col[pos.nd].st;
            a[pos.st][pos.nd].nd = 0 - col[pos.nd].nd;
            row[pos.st].st += a[pos.st][pos.nd].st;
            row[pos.st].nd += a[pos.st][pos.nd].nd;
            pos.nd++;
        }
    }
    a.back().back().st = 1-row.back().st;
    a.back().back().nd = 0-row.back().nd;
    ll x = 0;
    if ((col.back().st != row.back().st))
    {
        x = -(col.back().nd - row.back().nd) / (col.back().st - row.back().st);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << a[i][j].st * x + a[i][j].nd << ' ';
        }
        cout << '\n';
    }
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
