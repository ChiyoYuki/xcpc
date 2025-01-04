/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
// using namespace i11e;

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
typedef string str;

const int intinf = 0x3f3f3f3f;
const int mod9 = 998244353;
const int moda = 1000000007;

namespace i11e
{
    void ask(ll a);
    void ask(ll a, ll b);
    void ans(ll a);
    void ans(str s);
    void ans(vll a);
}
void solve(void);

vector<long long> sieve(long long n){
    vector<char> isp(n + 1, 1);
    vector<long long> p(1, 2);
    long long i, j, r = sqrt(n);
    // isp[0]=0;isp[1]=0;
    for (i = 4; i <= n; i += 2) isp[i] = 0;
    for (i = 3; i <= r; i += 2){
        if (isp[i] == 1){
            p.push_back(i);
            j = n / i;
            if (j % 2 == 0) j--;
            for (; j >= i; j -= 2) if (isp[j] == 1) isp[i * j] = 0;
        }
    }
    if (++r % 2 == 0) r++;
    for (; r <= n; r += 2) if (isp[r] == 1) p.push_back(r);
    return p;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;

    cin >> n;
    vpll2 edges(n-1);
    vll p=sieve(2*n);
    map<ll,bool> isp;
    map<ll,bool> now;
    vvll rela(n+1);
    vll ans(n+1);
    for(i=0;i<p.size();i++) isp[p[i]]=true;
    srand(time(NULL));
    for (i = 0; i < n-1; i++)
    {
        cin >> edges[i].st >> edges[i].nd;
    }

    ll times=0;
    label1:
    times++;
    if(times>512)
    {
        cout<<-1<<'\n';
        return;
    }
    now.clear();
    for(i=1;i<=n;i++)
    {
        label2:
        ans[i]=rand()%(n*2)+1;
        if(now[ans[i]]) goto label2;
        ;now[ans[i]]=true;
    }
    for(i=0;i<edges.size();i++)
    {
        if(isp[abs(ans[edges[i].first]-ans[edges[i].second])])
            goto label1;
    }
    
    for(i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout << '\n';
    return;
}

/*

*/

void i11e::ask(ll a)
{
    cout << "? " << a << endl;
    cout.flush();
    return;
}

void i11e::ask(ll a, ll b)
{
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    return;
}

void i11e::ans(ll a)
{
    cout << "! " << a << endl;
    cout.flush();
    return;
}

void i11e::ans(str s)
{
    cout << "! " << s << endl;
    cout.flush();
    return;
}

void i11e::ans(vll a)
{
    cout << "!";
    for (auto ii = a.begin(); ii != a.end(); ii++)
        cout << ' ' << (*ii);
    cout << endl;
    cout.flush();
    return;
}
