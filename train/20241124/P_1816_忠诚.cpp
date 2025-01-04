/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
// using namespace interactive;

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

const int intinf = 0x3f3f3f3f;
const int mod9 = 998244353;
const int moda = 1000000007;

namespace interactive
{
    void ask(ll a);
    void ask(ll a, ll b);
    void ans(ll a);
    void ans(string s);
    void ans(vll a);
}
void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}

void interactive::ask(ll a)
{
    cout << "? " << a << endl;
    cout.flush();
    return;
}

void interactive::ask(ll a, ll b)
{
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    return;
}

void interactive::ans(ll a)
{
    cout << "! " << a << endl;
    cout.flush();
    return;
}

void interactive::ans(string s)
{
    cout << "! " << s << endl;
    cout.flush();
    return;
}

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
    if (exp == 0)
        return 1;
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

void interactive::ans(vll a)
{
    cout << "!";
    for (auto ii = a.begin(); ii != a.end(); ii++)
        cout << ' ' << (*ii);
    cout << endl;
    cout.flush();
    return;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;

    cin >> n >> m;
    ll nn = n;
    ll b = 0;
    while (nn != 0)
    {
        nn >>= 1;
        b++;
    }
    vvll a(b);
    for (i = 0; i < n; i++)
    {
        cin >> nn;
        a[0].push_back(nn);
    }

    for (i = 1; i < b; i++)
    {
        for (j = 0; j < a[i - 1].size() - binpow(2, i - 1); j++)
        {
            a[i].push_back(min(a[i - 1][j], a[i - 1][j + binpow(2, i - 1)]));
        }
    }

    ll l, r;
    for (i = 0; i < m; i++)
    {
        cin >> l >> r;
        nn = r - l + 1;
        ll bb = 0;
        while (nn != 0)
        {
            nn >>= 1;
            bb++;
        }
        nn = binpow(2, bb - 1);
        r -= nn;
        sum = min(a[bb - 1][l - 1], a[bb - 1][r]);
        cout << sum << ' ';
    }
    return;
}

/*

*/