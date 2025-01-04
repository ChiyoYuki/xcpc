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
    //    cin >> _;
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

    cin >> n >> m;
    vll a(n), b(m);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0)
            a[i] = min(a[i], a[i - 1]);
    }
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
        if (b[i] >= a[0])
        {
            cout << 1 << '\n';
            continue;
        }
        if (b[i] < a[n - 1])
        {
            cout << -1 << '\n';
            continue;
        }
        ll ma = n - 1, mi = 0;
        ll mid = (ma + mi) / 2;
        while (ma > mi + 1)
        {
            mid = (ma + mi) / 2;
            if (a[mid] <= b[i])
                ma = mid;
            else
                mi = mid;
        }
        cout << ma + 1 << '\n';
    }

    cout << '\n';
    return;
}

/*

*/
