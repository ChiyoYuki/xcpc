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
    bool have = true, muti = false;
    cin >> n;
    str s[2];
    vector<vector<char>> vis(2, vector<char>(n, 0));
    queue<pair<ll, ll>> bfs;
    cin >> s[0] >> s[1];
    s[0] = '#' + s[0] + '#';
    s[1] = '#' + s[1] + '#';
    for (i = 1; i < s[0].size(); i++)
    {
        if (s[0][i] == '.' && s[1][i] == '.')
        {
            sum += 2;
            if (s[0][i - 1] == '.' && s[1][i - 1] == '.' && sum % 2 == 0)
                muti = true;
        }
        else if (s[0][i] == '.' && s[1][i] == '#')
        {
            if (s[0][i - 1] == '.')
            {
                sum++;
            }
            else
            {
                if (sum % 2 == 1)
                {
                    have = false;
                    break;
                }
                else
                {
                    sum = 1;
                }
            }
        }
        else if (s[0][i] == '#' && s[1][i] == '.')
        {
            if (s[1][i - 1] == '.')
            {
                sum++;
            }
            else
            {
                if (sum % 2 == 1)
                {
                    have = false;
                    break;
                }
                else
                {
                    sum = 1;
                }
            }
        }
        else
        {
            if (sum % 2 == 1)
            {
                have = false;
                break;
            }
            else
            {
                sum = 0;
            }
        }
    }
    if (!have)
        cout << "None";
    else if (muti)
        cout << "Multiple";
    else
        cout << "Unique";
    cout << '\n';
    return;
}

/*
.....##.
.##.....

112..##1
2##..122

1
4
#...
...#

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