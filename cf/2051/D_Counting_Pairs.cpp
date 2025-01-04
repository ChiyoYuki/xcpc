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
    ll x, y;
    cin >> n >> x >> y;
    vll a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll r = sum - x;
    ll l = sum - y;
    sort(a.begin(), a.end());
    sum = 0;
    ll ma, mi;
    bool flag = false;
    for (i = 0; i < n; i++)
    {
        if (a[i] + a[i + 1] > r)
            break;
        if (a[i] + a[n - 1] < l)
            continue;
        if (!flag)
        {
            mi = i + 1;
            ma = n - 1;
            for (; mi <= ma; mi++)
            {
                if (a[mi] + a[i] >= l)
                    break;
            }
            for (; ma >= mi; ma--)
            {
                if (a[ma] + a[i] <= r)
                    break;
            }
            sum += (ma - mi + 1);
            flag = true;
        }
        else
        {
            if (mi <= i)
                mi = i + 1;
            else
            {
                for (; mi > i; mi--)
                {
                    if (a[mi] + a[i] >= l && (a[mi-1] + a[i] < l || mi == i + 1))
                        break;
                }
            }
            if (a[i] + a[i + 1] > r)
                break;
            else
            {
                for (; ma >= mi; ma--)
                {
                    if (a[i] + a[ma] <= r)
                        break;
                }
            }
            sum += (ma - mi + 1);
        }
    }

    cout << sum;
    cout << '\n';
    return;
}

/*
1
9 356 400
45 60 31 106 27 19 38 112 96 
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