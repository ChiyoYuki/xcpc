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

    cin >> n;
    vll a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];

    vll now;
    ll mi = intinf;
    ll nowmi = intinf;
    for (i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] > mi)
        {
            now.push_back(a[i] + 1);
            nowmi = min(nowmi, now.back());
            a[i] = 0;
        }
        else
        {
            mi = a[i];
        }
    }

    ll tttt = 0;
    while (!(now.empty()))
    {
        
        tttt++;
        if (tttt > 1000000)
            cout << -1;

        if (a.back() == 0)
            a.pop_back();
        else if (a.back() > nowmi)
        {
            now.push_back(a.back() + 1);
            nowmi = min(nowmi, now.back());
            a.pop_back();
        }
        else
            break;
    }

    for (i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
            cout << a[i] << ' ';
    }

    sort(now.begin(), now.end());

    for (i = 0; i < now.size(); i++)
        cout << now[i] << ' ';

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
