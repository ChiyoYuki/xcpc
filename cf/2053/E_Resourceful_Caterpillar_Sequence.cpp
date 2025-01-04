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

    cin >> n;
    vpll2 edges(n - 1);
    // vll a(n);
    ll leaf = 0, l1 = 0;
    vvll nei(n + 1);
    vll dis(n + 1, -1);
    for (i = 0; i < n - 1; i++)
    {
        cin >> edges[i].first >> edges[i].second;
        nei[edges[i].first].push_back(edges[i].second);
        nei[edges[i].second].push_back(edges[i].first);
    }
    deque<ll> m2;
    vector<char> vvis(n + 1, 0);
    for (i = 1; i <= n; i++)
    {
        if (nei[i].size() == 1)
        {
            vvis[i] = 1;
            dis[i] = 0;
            leaf++;
            if (vvis[nei[i].front()] == 0)
            {
                dis[nei[i].front()] = 1;
                m2.push_back(nei[i].front());
                vvis[nei[i].front()] = 1;
            }
        }
    }
    l1 = m2.size();
    ll tail = 0, head = 0;
    while (!m2.empty())
    {
        ll now = m2.front();
        for (i = 0; i < nei[now].size(); i++)
        {
            if (dis[nei[now][i]] == 0)
                continue;
            queue<ll> bfs;
            ll rem = n - leaf - l1;
            vector<char> vis(n + 1, 0);
            vis[now] = 1;
            vis[nei[now][i]] = 1;
            bfs.push(nei[now][i]);
            while (!bfs.empty())
            {
                for (j = 0; j < nei[bfs.front()].size(); j++)
                {
                    if (vis[nei[bfs.front()][j]] == 0 && dis[nei[bfs.front()][j]] != 0)
                    {
                        bfs.push(nei[bfs.front()][j]);
                        vis[nei[bfs.front()][j]] = 1;
                    }
                }
                if (dis[bfs.front()] == -1)
                    rem--;
                ;
                bfs.pop();
            }
            sum += rem;
        }
        m2.pop_front();
    }
    cout << sum + leaf * (n - leaf);
    cout << '\n';
    return;
}

/*
      7
1-2-3-4-5-6-8
     9 10
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
