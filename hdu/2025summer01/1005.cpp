#include<bits/stdc++.h>

#define i8 long long

using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n + 2,vector<int> (m + 2,0));
    vector<pair<int,int>> high;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]>max(max(a[i-1][j],a[i+1][j]),max(a[i][j-1],a[i][j+1])))
            {
                high.push_back({i,j});
            }
        }
    }
}

int main()
{
    int _;
    cin>>_;
    while(_--)
    {
        solve();
        cout<<'\n';
    }
    return 0;
}