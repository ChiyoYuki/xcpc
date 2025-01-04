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

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    str a, b;
    ll q, l, r;
    ll sum;
    cin >> n >> q;
    cin >> a >> b;
    vector<pair<vector<int>, vector<int>>> ps(n + 1, make_pair(vector<int>(26, 0), vector<int>(26, 0)));
    for (i = 0; i < n; i++)
    {
        (ps[i + 1].first)[a[i] - 'a']++;
        (ps[i + 1].second)[b[i] - 'a']++;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < 26; j++)
        {
            (ps[i].first)[j] += (ps[i - 1].first)[j];
            (ps[i].second)[j] += (ps[i - 1].second)[j];
        }
    }

    for (i = 0; i < q; i++)
    {
        cin >> l >> r;
        sum = 0;
        for (j = 0; j < 26; j++)
        {
            sum += abs(((ps[r].st)[j] - (ps[l - 1].st)[j]) - ((ps[r].nd)[j] - (ps[l - 1].nd)[j]));
        }
        sum /= 2;
        cout << sum << '\n';
    }
    // vll a(n);
    // for(i=0;i<n;i++) cin>>a[i];

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
