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

    str s;
    ll k;
    cin >> n >> k >> s;
    for (i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            sum++;
            s.erase(s.begin() + i);
        }
        else if (sum != 0)
        {
            sum--;
            if (sum == 0)
                s[i] = '0';
            else
                s.erase(s.begin() + i);
        }
    }

    if (sum != 0)
        s = '0' + s;

    sum = 0;
    ll num = 0, ans = 0;
    for (i = 0; i < s.size(); i++)
        if (s[i] == '1')
            num++;

    for (i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '1')
            num--;
        ans += num;
        if (ans >= k)
            break;
    }

    if (ans < k)
        cout << -1;
    else
        cout << i + 2;

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
