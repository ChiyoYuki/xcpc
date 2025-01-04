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
    template <typename __Tp0, typename __Tp1>
    void ask(__Tp0 a, __Tp1 b);
    void ans(ll a);
    void ans(str s);
    void ans(vll a);
}

bool cmp(pair<ll, ll> x, pll2 y)
{
    return x.first > y.first;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;
    ll k;
    cin >> n >> k;
    vll a(n);
    map<ll, ll> mp;
    vll key;
    vpll2 s;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mp[a[i]] == 0)
            key.push_back(a[i]);
        mp[a[i]]++;
    }
    if(n==k) {cout<<1<<'\n';return;}

    for (i = 0; i < key.size(); i++)
    {
        s.push_back(make_pair(mp[key[i]], key[i]));
    }
    sort(s.begin(), s.end(), cmp);
    while (k)
    {
        if (k >= s.back().first)
        {
            k -= s.back().first;
            s.pop_back();
        }
        else
        {
            k = 0;
        }
    }
    cout<<s.size();
    cout << '\n';
    return;
}

/*

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

template <typename __Tp0, typename __Tp1>
void ask(__Tp0 a, __Tp1 b)
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
