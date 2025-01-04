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
    template <typename __Tp>
    void ask(__Tp a, __Tp b);
    void ans(ll a);
    void ans(str s);
    void ans(vll a);
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0, num = 0;
    ll pos = 0;
    cin >> n;
    vll a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != -1 && a[i] != 1)
        {
            pos = i;
        }
    }
    num = a[pos];
    ll lmi = 0, rmi = 0, lma = 0, rma = 0;
    ll almi = 0, armi = 0, alma = 0, arma = 0;
    sum = 0;
    ll asum = 0, sumi = 0, suma = 0;
    for (i = pos - 1; i >= 0; i--)
    {
        sumi += a[i];
        asum += a[i];
        suma += a[i];

        lmi = min(sumi, lmi);
        almi = min(asum, almi);
        sumi = min(0LL, sumi);

        lma = max(suma, lma);
        alma = max(asum, alma);
        suma = max(0LL, suma);
    }
    sumi = 0;
    suma = 0;
    asum = 0;
    for (i = pos + 1; i < a.size(); i++)
    {
        sumi += a[i];
        suma += a[i];
        asum += a[i];

        rmi = min(sumi, rmi);
        armi = min(asum, armi);
        sumi = min(0LL, sumi);

        rma = max(suma, rma);
        arma = max(asum, arma);
        suma = max(0LL, suma);
    }
    ll ma = max(lma, rma), mi = min(lmi, rmi);
    ll ama = arma + alma + num, ami = armi + almi + num;
    // cout << lma << ' ' << lmi << ' ' << rma << ' ' << rmi << '\n';
    // cout << ma << ' ' << mi << ' ' << ama << ' ' << ami << '\n';
    map<ll, bool> vis;
    vll ans;
    for (i = lmi; i <= lma; i++)
    {
        ans.push_back(i);
        vis[i] = true;
    }
    for (i = ami; i <= ama; i++)
    {
        if (!vis[i])
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
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

template <typename __Tp>
void i11e::ask(__Tp a, __Tp b)
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