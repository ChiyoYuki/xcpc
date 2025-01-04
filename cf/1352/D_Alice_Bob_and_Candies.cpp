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

    cin >> n;
    deque<ll> a;
    ll just;
    for (i = 0; i < n; i++)
    {
        cin >> just;
        a.push_back(just);
    }
#define alice false
#define bob true;
    ll lasta = 0, suma = 0, lastb = 0, sumb = 0, step = 0;
    bool mode = alice;
    lasta += a.front();
    step++;
    a.pop_front();
    while (!a.empty())
    {
        if (mode == alice)
        {
            while (!a.empty() && lastb <= lasta)
            {
                lastb += a.back();
                a.pop_back();
            }
            suma += lasta;
            lasta = 0;
            step++;
            mode=bob;
        }
        else
        {
            while (!a.empty() && lasta <= lastb)
            {
                lasta += a.front();
                a.pop_front();
            }
            sumb += lastb;
            lastb = 0;
            step++;
            mode=alice;
        }
    }
    suma += lasta;
    sumb += lastb;
    cout << step << ' ' << suma << ' ' << sumb;
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