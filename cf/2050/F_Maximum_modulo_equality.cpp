/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
// using namespace i11e;

#define st first
#define nd second

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
    void ask(ll a);
    void ask(ll a, ll b);
    void ans(ll a);
    void ans(str s);
    void ans(vll a);
}
void solve(void);

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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;
    ll q;
    cin >> n >> q;
    vll a(n);
    ll ln = 0, nn = n;
    while (nn)
    {
        ln++;
        nn >>= 1;
    }
    vvll rmq(ln);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0)
            rmq[0].push_back(abs(a[i] - a[i - 1]));
    }

    nn = 1;
    for (i = 1; i < rmq.size(); i++)
    {
        for (j = 0; j + nn < rmq[i - 1].size(); j++)
        {
            rmq[i].push_back(gcd(rmq[i - 1][j], rmq[i - 1][j + nn]));
        }
        nn *= 2;
    }

    ll l, r;
    for (i = 0; i < q; i++)
    {
        cin >> l >> r;
        l--;
        r--;
        if (l == r)
        {
            cout << 0 << ' ';
            continue;
        }
        else if (r == l + 1)
        {
            cout << rmq[0][l] << ' ';
            continue;
        }
        ll del = (r - l) / 2 + (r - l) % 2;
        ll lnn = 0, lln = 1;
        while (lln < del)
        {
            lnn++;
            lln <<= 1;
        }
        cout << gcd(rmq[lnn][l], rmq[lnn][r - lln]) << ' ';
    }
    cout << '\n';
    return;
}

/*

*/

void i11e::ask(ll a)
{
    cout << "? " << a << endl;
    cout.flush();
    return;
}

void i11e::ask(ll a, ll b)
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
