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
    ll sum = 0;

    cin >> n;
    str s;
    cin >> s;
    s = "00" + s + "00";
    vvll pre(n + 4, vll(26, 0)), las(n + 4, vll(26, 0));
    for (i = 2; i < s.size() - 2; i++)
    {
        pre[i] = pre[i - 2];
        pre[i][s[i] - 'a']++;
        las[s.size() - i - 1] = las[s.size() - i + 1];
        las[s.size() - i - 1][s[s.size() - i - 1] - 'a']++;
    }
    if (n % 2 == 0)
    {
        ll odd = 0, even = 0;
        for (i = 0; i < 26; i++)
        {
            odd = max(odd, las[2][i]);
            even = max(even, las[3][i]);
        }
        odd = n / 2 - odd;
        even = n / 2 - even;
        sum = odd + even;
    }

    if (n % 2)
    {
        sum = 0x3f3f3f3f;
        vll n1(26), n2(26);
        for (i = 2; i < s.size() - 2; i++)
        {
            for (j = 0; j < 26; j++)
            {
                n1[j] = pre[i - 2][j] + las[i + 1][j];
                n2[j] = pre[i - 1][j] + las[i + 2][j];
            }

            ll no = 0, ne = 0;
            for (j = 0; j < 26; j++)
            {
                no = max(no, n1[j]);
                ne = max(ne, n2[j]);
            }
            no = n / 2 - no;
            ne = n / 2 - ne;
            sum = min(sum, no + ne + 1);
        }
    }
    cout << sum;
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
