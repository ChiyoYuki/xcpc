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
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
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
    cin>>n;
    vector<vector<char>> a(n+1,vector<char>(n+1,0));
    vvll dis(n+1,vll(n+1,inf));
    for(i=1;i<=n;i++)
    {
        getchar();
        for(j=1;j<=n;j++)
        {
            a[i][j]=getchar()-'0';
            if(a[i][j]==1) dis[i][j]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(dis[j][i]+dis[i][k]<dis[j][k]) dis[j][k]=dis[j][i]+dis[i][k];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        dis[i][i]=0;
    }

    cin>>m;
    vll path;
    ll pre;
    for(i=0;i<m;i++)
    {
        cin>>pre;
        if(i==0||i==1) path.push_back(pre);
        else 
        {
            if(dis[*(path.end()-2)][path.back()]+dis[path.back()][pre]==dis[*(path.end()-2)][pre])
            {
                path.pop_back();
            }
            path.push_back(pre);
        }
    }

    cout<<path.size()<<endl;
    for(auto ii=path.begin();ii!=path.end();ii++)
    {
        cout<<*ii<<' ';
    }
    cout << endl;
    return;
}

/*

*/