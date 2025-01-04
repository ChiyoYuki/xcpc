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
    i11e::ask(1LL, n / 2);
    cin >> sum;
    ll now = 1;
    ll ma, mi, mid;
    ll l, r;
    if (sum == 1)
    {
        i11e::ask(n / 2 + 1, n * 3 / 4);
        cin >> l;
        i11e::ask(n * 3 / 4 + 1, n);
        cin >> r;
        if (l == r)
        {
            ma = n;
            mi = n / 2;
            while (ma != mi + 1)
            {
                mid = (ma + mi) / 2;
                i11e::ask(1LL, mid);
                cin >> sum;
                if (sum == 1)
                    mi = mid;
                else
                    ma = mid;
            }
            i11e::ans(ma);
        }
        else
        {
            mi = 1;
            ma = n / 2 + 1;
            while (ma != mi + 1)
            {
                mid = (ma + mi) / 2;
                i11e::ask(1LL, mid);
                cin >> sum;
                if (sum == 1)
                    ma = mid;
                else
                    mi = mid;
            }
            i11e::ans(ma);
        }
    }
    else
    {
        i11e::ask(1LL, n / 4);
        cin >> l;
        i11e::ask(n / 4 + 1, n / 2);
        cin >> r;
        if (l == r)
        {
            mi = 1;
            ma = n / 2 + 1;
            while (ma != mi + 1)
            {
                mid = (ma + mi) / 2;
                i11e::ask(mid, n);
                cin >> sum;
                if (sum == 1)
                    ma = mid;
                else
                    mi = mid;
            }
            i11e::ans(n - mi + 1);
        }
        else
        {
            mi = n / 2;
            ma = n;
            while (ma != mi + 1)
            {
                mid = (ma + mi) / 2;
                i11e::ask(mid, n);
                cin >> sum;
                if (sum == 0)
                    ma = mid;
                else
                    mi = mid;
            }
            i11e::ans(n - mi + 1);
        }
    }
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