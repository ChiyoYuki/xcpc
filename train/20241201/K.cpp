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

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum1 = 0, num1 = 0;
    ll sum2 = 0, num2 = 0, x2 = 0;

    cin >> n >> m;
    vpll2 t(m);
    vll ans(n + 1, 0);
    vector<pair<ll, ll>> wh(n + 1, make_pair(0, 0));

    for (i = 0; i < m; i++)
    {
        cin >> t[i].first >> t[i].second;
        if (t[i].first == 1)
            wh[t[i].second].first++;
        else
            wh[t[i].second].second++;
    }
    for (i = 1; i <= n; i++)
    {

        num1 += wh[i].first;
        num1 %= moda;

        sum1 += num1;
        sum1 %= moda;

        ans[i] += sum1;
        ans[i] %= moda;

        num2 += wh[i].second * 2;
        num2 %= moda;

        x2 += num2;
        x2 %= moda;

        sum2 += x2;
        sum2 -= (num2) / 2;
        sum2 %= moda;

        ans[i] += sum2;
        ans[i] %= moda;

        cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
}

/*
1 4 9 16 25 36
 3 5 7 9
  2 2 2 2
*/

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
