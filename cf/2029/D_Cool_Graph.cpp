/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define lf double
#define vc vector<char>
#define vll vector<long long>
#define vvll vector<vector<long long>>

using namespace std;

void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

typedef struct ABC
{
    ll a;
    ll b;
    ll c;
} abc;

void solve(void)
{
    ll i = 0, j = 0;
    ll n, m, sum = 0;
    vector<abc> ans;
    vll root;
    ll u, v;
    cin >> n >> m;
    if (m == 0)
    {
        cout << 0 << endl;
        return;
    }
    vvll p(n + 1);
    vector<char> flag(n + 1, false);
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    stack<ll> dfs;
    vll cir;
label1:
    while (!dfs.empty())
        dfs.pop();
    for (i = 1; i < n; i++)
    {
        dfs.push(i);
        flag[i] = true;
        while (!dfs.empty())
        {
            ll tt = dfs.top();
            dfs.pop();
            for (ll ss : p[tt])
            {
                if (!flag[ss])
                {
                    flag[ss] = true;
                    dfs.push(ss);
                }
                else
                {
                    ll ttt=dfs.top();
                    while(ttt!=ss)
                    {
                        ttt=dfs.top();
                        cir.push_back(ttt);
                        flag[ttt]=false;
                    }
                    for(auto vv=cir.begin()+1;vv!=(cir.end()-1);vv++)
                    {
                        abc xans;
                        xans.a=cir[0];
                        xans.b=*vv;
                        xans.c=*(vv+1);
                        p[]
                        ans.push_back(xans);
                    }
                }
            }
        }
    }
    cout << endl;
    return;
}

/*

*/