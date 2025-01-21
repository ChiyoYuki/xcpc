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

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m[3] = {0};
    ll sum = 0;
    ll u, v;
    cin >> n >> m[1] >> m[2];
    vll bcjf(n + 1, 0), bcjg(n + 1, 0);
    vpll2 f(m[1]), g(m[2]);
    vll a(n);
    for (i = 0; i < m[1]; i++)
    {
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        f[i] = make_pair(u, v);
    }

    for (i = 0; i < m[2]; i++)
    {
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        g[i] = make_pair(u, v);
        bcjg[v] = u;
    }

    for (i = 1; i <= n; i++)
    {
        ll now = i;
        while (bcjg[now] != 0)
        {
            now = bcjg[now];
        }
        if (i != now)
        {
            ll xxx = i;
            while (xxx != now)
            {
                ll yyy = xxx;
                xxx = bcjg[xxx];
                bcjg[yyy] = now;
            }
        }
    }

    for(i=0;i<m[1];i++)
    {
        u=f[i].first;
        v=f[i].second;
        while (bcjg[u] != 0)
            u = bcjg[u];
        while (bcjg[v] != 0)
            v = bcjg[v];
        if(u!=v)
        {
            sum++;
            f[i].first=0;
            f[i].second=0;
        }
    }

    for(i=0;i<m[1];i++)
    {
        bcjf[f[i].second]=f[i].first;
    }

    for (i = 1; i <= n; i++)
    {
        ll now = i;
        while (bcjf[now] != 0)
        {
            now = bcjf[now];
        }
        if (i != now)
        {
            ll xxx = i;
            while (xxx != now)
            {
                ll yyy = xxx;
                xxx = bcjf[xxx];
                bcjf[yyy] = now;
            }
        }
    }

    for(i=0;i<m[2];i++)
    {
        u=g[i].first;
        v=g[i].second;
        while (bcjf[u] != 0)
            u = bcjf[u];
        while (bcjf[v] != 0)
            v = bcjf[v];
        if(u!=v)
        {
            sum++;
            bcjf[v]=u;
        }
    }

    cout << sum;
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
