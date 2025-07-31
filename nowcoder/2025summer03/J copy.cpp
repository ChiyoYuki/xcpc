#include<bits/stdc++.h>

using namespace std;

#define i8 long long
#define vi vector<long long>

void solve()
{
    int n;
    cin>>n;
    vi f(n);
    vector<vi> a(n,vi(n,0));
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
        if(f[i]!=1)
        {
            a[i][i]=1;
            for(int j=2;j<f[i];j++)
            {
                a[i][j-2]=j;
                a[j-2][i]=j;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return ;
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
}