#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
const int mod = 1000000007;
const int N = 2e5;

void move(char ch,pair<int,int> &p)
{
    if(ch=='N') p.ss++;
    if(ch=='E') p.ff++;
    if(ch=='S') p.ss--;
    if(ch=='W') p.ff--;
}

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    pair<int,int> p={0,0};
    if(p.ff==a&&p.ss==b)
    {
        cout<<"YES";
        return;
    }
    for(int i=0;i<10000;i++)
    {
        move(s[i%n],p);
        if(p.ff==a&&p.ss==b)
        {
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<'\n';
    }
    return 0;
}