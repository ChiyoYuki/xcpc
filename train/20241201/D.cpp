/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
// using namespace interactive;

#define st first
#define nd second

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef pair<ll, ll> pll2;
typedef priority_queue<ll> pqll;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll2;

const int intinf = 0x3f3f3f3f;
const int mod9 = 998244353;
const int moda = 1000000007;

namespace interactive
{
void ask(ll a);
void ask(ll a, ll b);
void ans(ll a);
void ans(string s);
void ans(vll a);
}
void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;

    cin>>n>>m;
    vll a(n+1,0);
    vll b(n+1,intinf);
    vector<vector<bool>> p(n+1,vector<bool>(n+1,false));
    for(i=1;i<=n;i++) cin>>a[i];
    vpll2 edge(m);
    
    queue<ll> bfs;
    b[n]=a[n]/2+1;
    bfs.push(n);

    for(i=0;i<m;i++)
    {
        cin>>edge[i].first>>edge[i].second;
        p[edge[i].first][edge[i].second]=true;
    }
    
    while(!(bfs.empty()))
    {
        for(i=1;i<=n;i++)
        {
            if(p[i][bfs.front()])
            {
                ll up;
                ll down;
                up=max(b[bfs.front()]-a[i],a[i]);
                down=(b[bfs.front()]+a[i])/2+(b[bfs.front()]+a[i])%2;
                ll xxx=min(up,down);
                b[i]=min(xxx,b[i]);
                bfs.push(i);
            }
        }
        bfs.pop();
    }
    
    ll ans=intinf;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(p[j][i]) break;
        }
        if(j==n+1) ans=min(b[i],ans);
    }
    cout<<ans;
    cout << '\n';
    return;
}

/*

*/

void interactive::ask(ll a)
{
    cout << "? " << a << endl;
    cout.flush();
    return;
}

void interactive::ask(ll a, ll b)
{
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    return;
}

void interactive::ans(ll a)
{
    cout << "! " << a << endl;
    cout.flush();
    return;
}

void interactive::ans(string s)
{
    cout << "! " << s << endl;
    cout.flush();
    return;
}

void interactive::ans(vll a)
{
    cout << "!";
    for (auto ii = a.begin(); ii != a.end(); ii++)
        cout << ' ' << (*ii);
    cout << endl;
    cout.flush();
    return;
}
