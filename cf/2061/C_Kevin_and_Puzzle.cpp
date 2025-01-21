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
    bool f = false;
    vll ans;
    cin >> n;
    vll a(n + 1);
    for (i = 1; i <= n; i++)
        cin >> a[i];
    a.push_back(a[n - 1] + 1);
    if (a[1] != 0 && a[2] != 1)
    {
        cout << 0 << '\n';
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (a[i - 1] + 1 == a[i + 1])
        {
            sum++;
        }
        else
        {
            sum = 0;
        }
    }
    if (sum > 0)
        ans.push_back(sum);
    sum = 1;
    for (i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 1)
            ans[i]++;
        sum *= (ans[i] - 1);
        sum %= mod9;
    }
    cout << sum;
    cout << '\n';
    return;
}

/*

1010101
0101010


101010
101001
100101
010101
10101
10010
01001
01010
1010
1001
0101
101
010
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
