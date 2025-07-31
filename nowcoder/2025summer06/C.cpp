#include<bits/stdc++.h>

#define i8 long long
#define vi vector<i8>
using namespace std;

i8 jc(i8 n)
{
    if(n==1) return 1;
    else return n*jc(n-1);
}

void solve()
{
    int n;
    cin>>n;
    vi a(n),c(n+1,0);
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    stack<i8> b;
    for(int i=0;i<jc(n);i++)
    {
        for(int j=0;j<n;j++)
        {
            while(!b.empty() && b.top() > a[j])
            {
                b.pop();
            }
            b.push(a[j]);
        }
        c[b.size()]++;
        while(!b.empty()) b.pop();
        next_permutation(a.begin(),a.end());
    }
    i8 sum=0;
    for(int i=1;i<=n;i++)
    {
        cout<<c[i];
        sum+=c[i]*c[i]*c[i];
        if(i < n) cout<<' ';
        else cout<<endl;
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