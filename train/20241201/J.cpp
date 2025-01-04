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

void solve(void);

long long binpow(long long base, long long exp, long long mod)
{
    exp %= (mod - 1);
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

const ll mod = (ll)1000000007;

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;
    ll p, q;
    cin >> n >> p >> q;

    vll a(2 * n);
    a[2 * n - 1] = 1;
    for (i = 2 * n - 2; i >= n; i--)
    {
        a[i] = a[i + 1];
        a[i] *= (i + 1);
        a[i] %= mod;
        ll below = binpow(2 * n - 1 - i, mod - 2, mod);
        a[i] *= below;
        a[i] %= mod;
    }

    vll xxx(2 * n, 0);
    vll yyy(2 * n, 0);
    for (i = n; i <= 2 * n - 1; i++)
    {
        if (i == n)
        {
            yyy[i] = binpow(p, i, mod);
        }
        else
        {
            yyy[i] = yyy[i - 1] * p;
            yyy[i] %= mod;
        }
    }

    for (i = 2 * n - 1; i >= n; i--)
    {
        if (i == 2 * n - 1)
        {
            xxx[i] = 1;
        }
        else
        {
            xxx[i] = xxx[i + 1] * (q - p);
            xxx[i] %= mod;
        }
        ll son = yyy[i] * xxx[i];
        son %= mod;
        son *= a[i];
        son %= mod;
        sum += son;
        sum %= mod;
    }
    ll fuck = (2 * n - 1) * (mod - 2) % (mod - 1);
    ll mom = binpow(q, fuck, mod);
    sum *= mom;
    sum %= mod;
    cout << sum;
    cout << '\n';
    return;
}

/*

*/
