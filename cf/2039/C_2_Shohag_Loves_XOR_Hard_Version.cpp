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
    cin >> _;
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
    ll x;
    cin >> x >> m;

    ll bites = 0, xb = x;
    while (xb != 0)
    {
        xb >>= 1;
        bites++;
    }

    ll cir = (1 << (bites + 1));
    ll tm = m / cir;
    tm *= cir;

    for (i = tm; i <= m; i++)
    {
        if (i == 0)
            continue;
        if ((i ^ x) % x == 0)
        {
            sum++;
        }
    }

    for (i = 1; i < cir && i <= m; i++)
    {
        if ((i ^ x) % i == 0 && (i ^ x) % x != 0)
        {
            sum++;
        }
    }

    ll num = (tm - 1) / x;
    if (tm != 0)
        sum += num;
    cout << sum;
    cout << '\n';
    return;
}

/*

*/