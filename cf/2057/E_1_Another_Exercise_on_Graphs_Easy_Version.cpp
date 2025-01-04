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

const ll inf_ll = 0x3f3f3f3f3f3f3f3f;

void solve(void)
{
    int i = 0, j = 0;
    int n = 0, m = 0;
    int sum = 0;
    int q = 0;
    cin >> n >> m >> q;
    vector<vector<vector<int>>> cost(n, vector<vector<int>>(n));
    vector<vector<ll>> mp(n, vector<ll>(n, inf_ll));
    for (i = 0; i < m; i++)
    {
        ll v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        mp[v][u] = w;
    }
    int now;
    for (now = 0; now < n; now++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; i++)
            {
                
            }
        }
    }
    for (i = 0; i < q; i++)
    {
        int a, b, k;
        cin >> a >> b >> k;
        a--;
        b--;
    }
    cout << '\n';
    return;
}

/*

111001100010011010010010001001
010110011000100101100100010110
000000101111111000011001110010
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
