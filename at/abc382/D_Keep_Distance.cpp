/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
// using namespace interactive;

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

const int intinf = 0x3f3f3f3f;
const int mod9 = 998244353;
const int moda = 1000000007;

namespace interactive
{
    void ask(ll a);
    void ask(ll a, ll b);
    void ans(ll a);
    void ans(string s);
    void ans(vll a);
}
void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    //    cin >> _;
    while (_--)
        solve();
    return 0;
}

void interactive::ask(ll a)
{
    cout << "? " << a << endl;
    cout.flush();
    return;
}

void interactive::ask(ll a, ll b)
{
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    return;
}

void interactive::ans(ll a)
{
    cout << "! " << a << endl;
    cout.flush();
    return;
}

void interactive::ans(string s)
{
    cout << "! " << s << endl;
    cout.flush();
    return;
}

void interactive::ans(vll a)
{
    cout << "!";
    for (auto ii = a.begin(); ii != a.end(); ii++)
        cout << ' ' << (*ii);
    cout << endl;
    cout.flush();
    return;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;

    // cin>>n;
    // vll a(n);
    // for(i=0;i<n;i++) cin>>a[i];
    cin >> n >> m;
    vvll a(1, vll(n, 1));
    bool f = true;
    ll mm = m % 10;
    if (mm == 0)
        mm = 10;
    while (f)
    {
        a.push_back(a.back());
        a.back().back()++;
        j = n - 1;
        while (a.back()[j] > mm)
        {
            if (j == 0)
            {
                a.pop_back();
                f = false;
                break;
            }
            else
            {
                a.back()[j - 1]++;
                j--;
            }
        }
        while (j < n - 1)
        {
            a.back()[j + 1] = a.back()[j];
            j++;
        }
    }
    cout << a.size() << '\n';
    for (i = 0; i < a.size(); i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] + j * 10 << ' ';
        }
        cout << '\n';
    }
    return;
}

/*

*/
