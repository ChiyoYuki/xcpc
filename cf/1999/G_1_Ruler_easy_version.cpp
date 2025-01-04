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
    ll ma=999,mi=2;
    ll a=333,b=666;
    ll c;
    while(ma!=mi)
    {
        i11e::ask(a,b);
        cin>>c;
        if(c==a*b)
        {
            mi=b+1;
        }
        else if(c==a*(b+1))
        {
            mi=a+1;
            ma=b;
        }
        else if(c==(a+1)*(b+1))
        {
            ma=a;
        }
        a=(ma-mi)/3+mi;
        b=2*(ma-mi)/3+mi;
    }
    // cin>>n;
    // vll a(n);
    // for(i=0;i<n;i++) cin>>a[i];
    i11e::ans(ma);
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
