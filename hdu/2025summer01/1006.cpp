#include<bits/stdc++.h>

#define i8 long long
#define st first
#define nd second 

using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n + 2,vector<int> (m + 2,0));
    vector<pair<int,pair<int,int>>> high;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    bool how=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)
            {
                high.push_back({a[i][j],{i,j}});
            }
            else if(a[i][j]>max(max(a[i-1][j],a[i+1][j]),max(a[i][j-1],a[i][j+1])))
            {
                high.push_back({a[i][j],{i,j}});
            }
        }
    }
    i8 sum=0;
    sum+=(1LL<<34)*(high.size()-1);
    sort(high.begin(),high.end());
    for(int i=1;i<high.size();i++)
    {
        i8 cost = 114*abs(high[i].nd.st-high[i-1].nd.st)+5141*abs(high[i].nd.nd-high[i-1].nd.nd)+919810*abs(high[i].st-high[i-1].st);
        sum+=cost;
    }
    cout<<sum;
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