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

const int inf=0x3f3f3f3f;

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
    ll i = 0, j = 0;
    ll n, m, sum = 0, ans = 0;
    ll s;
    ll u,v,w,l;
    cin>>n>>m>>s;
    vector<vector<pair<ll,ll>>> a(n+1);
    for(i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        a[u].push_back(make_pair(v,w));
        a[v].push_back(make_pair(u,w));
    }
    cin>>l;

    vll far(n+1,inf);
    far[l]=0;
    vector<char> vis(n+1,false);
    vis[l]=true;
    ll now=l,mir,mi;

    for(i=0;i<n-1;i++)
    {
        vis[now]=true;
        for(j=0;j<a[now].size();j++)
        {
            if(vis[a[now][j].first]==false)
            {
                far[a[now][j].first]=min(far[a[now][j].first],far[now]+a[now][j].second);
            }
        }
        mir=inf;
        for(j=1;j<=n;j++)
        {
            if((!vis[j])&&far[j]<mir)
            {
                mir=far[j];
                mi=j;
            }
        }
        now=mi;
    }

    for(i=1;i<=n;i++)
    {
        if(far[i]==s) ans++;
    }

    cout<<ans;
    cout << endl;
    return;
}

/*

*/