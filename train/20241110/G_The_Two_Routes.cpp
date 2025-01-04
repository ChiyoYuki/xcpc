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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0, k = 0;
    ll n, m, sum = 0, ans = 0;
    cin >> n >> m;
    ll u, v;
    vvll a(n + 1, vll(n + 1, 0));
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    vll rail(n + 1, -1);
    rail[1] = 0;
    vll road(n + 1, -1);
    road[1] = 0;

    bool flag = true;
    for (i = 0;flag==true; i++)
    {
        flag = false;
        for (j = 1; j <= n; j++)
        {
            if (rail[j] == i)
            {
                for (k = 1; k <= n; k++)
                {
                    if (a[j][k] == 1 && rail[k] == -1)
                    {
                        flag=true;
                        rail[k]=i+1;
                    }
                }
            }
            if (road[j] == i)
            {
                for (k = 1; k <= n; k++)
                {
                    if (a[j][k] == 0 && road[k] == -1)
                    {
                        flag=true;
                        road[k]=i+1;
                    }
                }
            }
        }
    }
    if(road[n]==-1||rail[n]==-1) ans=-1;
    else ans=max(road[n],rail[n]);
    cout<<ans;
    cout << endl;
    return;
}
/*

*/