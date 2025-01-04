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

pll2 now(ll n, ll k)
{
    ll ans, num;
    pll2 re;
    if (n < k)
        return make_pair(0LL, 0LL);
    else if (n % 2 == 0)
    {
        if (n / 2 >= k)
        {
            re = now(n / 2, k);
            ans = re.first * 2;
            ans += (n / 2) * re.second;
            num = 2 * re.second;
        }
        else
        {
            ans = 0;
            num = 0;
        }
    }
    else if (n % 2 != 0)
    {
        if (n / 2 >= k)
        {
            re = now(n / 2, k);
            ans = re.first * 2;
            ans += (n / 2 + 1);
            ans += (n / 2 + 1) * re.second;
            num = 2 * re.second + 1;
        }
        else
        {
            ans = n / 2 + 1;
            num = 1;
        }
    }
    return make_pair(ans, num);
}
//
void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;
    ll k;
    ll ans;
    cin >> n >> k;
    ans = now(n, k).first;
    cout << ans;
    cout << '\n';
    return;
}

/*

55 13
1~27 28 29~55
1~13 14 15~27 28 29~41 42 43~55
1~6 7 8~13 14
7+14+...+49
7 14 21 28 35 42 49
28*7

1
1 2
1 *2* 3
1 2 3 4
1 2 *3* 4 5
1 *2* 3 4 *5* 6
1 *2* 3 *4* 5 *6* 7
1 2 3 4 5 6 7 8
1 2 3 4 *5* 6 7 8 9
1 2 *3* 4 5 6 7 *8* 9 10
1 2 *3* 4 5 *6* 7 8 *9* 10 11
1 *2* 3 4 *5* 6 7 *8* 9 10 *11* 12
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
