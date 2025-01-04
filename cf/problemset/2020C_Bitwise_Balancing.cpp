/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define elif else if

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
    template <typename __Tp>
    void ask(__Tp a);
    template <typename __Tp>
    void ask(__Tp a, __Tp b);
    void ans(ll a);
    void ans(str s);
    void ans(vll a);
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;
    ll b,c,d;
    cin>>b>>c>>d;
    ll a=0;
    // cin>>n;
    // vll a(n);
    // for(i=0;i<n;i++) cin>>a[i];
    ll bit=1LL;
    while(bit<(1LL<<62))
    {
        if(((b&bit)==0&&(c&bit)==0&&(d&bit)==0)||((b&bit)!=0&&(c&bit)!=0&&(d&bit)!=0));
        else if(((b&bit)==0&&(c&bit)==0&&(d&bit)!=0)||((b&bit)!=0&&(c&bit)!=0&&(d&bit)==0)) a+=bit;
        else if(((b&bit)==0&&(c&bit)!=0&&(d&bit)==0)||((b&bit)!=0&&(c&bit)==0&&(d&bit)!=0));
        else
        {
            a=-1;
            break;
        }
        bit<<=1;
    }
    cout<<a;
    cout << '\n';
    return;
}

/*

0100 1010 0010 1110
1110 0000

b c d a
0 0 0 0
1 1 1 0
0 0 1 1
1 1 0 1
0 1 0 x
1 0 1 x
*/

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

template <typename __Tp>
void i11e::ask(__Tp a)
{
    cout << "? " << a << endl;
    cout.flush();
    return;
}

template <typename __Tp>
void i11e::ask(__Tp a, __Tp b)
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