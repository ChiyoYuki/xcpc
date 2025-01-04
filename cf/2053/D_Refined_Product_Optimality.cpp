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
    ll sum = 1;
    ll q;
    cin >> n >> q;
    ll now;
    vll a(n), b(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    vll aa = a, bb = b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (i = 0; i < n; i++)
    {
        now = min(a[i], b[i]);
        sum *= now;
        sum %= mod9;
    }
    cout << sum << ' ';
    ll o, x;
    for (i = 0; i < q; i++)
    {
        cin >> o >> x;
        x--;
        if (o == 1)
        {
            auto pos = upper_bound(a.begin(), a.end(), aa[x]);
            ll diff = pos - a.begin() - 1;
            aa[x]++;
            if (a[diff] < b[diff])
            {
                ll ni = binpow(a[diff], mod9 - 2, mod9);
                sum *= ni;
                sum %= mod9;
                a[diff]++;
                sum *= a[diff];
                sum %= mod9;
            }
            else
                a[diff]++;
        }
        else
        {
            auto pos = upper_bound(b.begin(), b.end(), bb[x]);
            ll diff = pos - b.begin() - 1;
            bb[x]++;
            if (b[diff] < a[diff])
            {
                ll ni = binpow(b[diff], mod9 - 2, mod9);
                sum *= ni;
                sum %= mod9;
                b[diff]++;
                sum *= b[diff];
                sum %= mod9;
            }
            else
                b[diff]++;
        }
        cout << sum << ' ';
    }

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
