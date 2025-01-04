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
    cin >> _;
    while (_--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum[3] = {0};

    cin >> n;
    vll a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[a[i]]++;
    }

    vpll2 ans;

    ll l = 0;
    ll r0 = n - 1, r1 = n - 1;
    for (l = 0; l < sum[0]; l++)
    {
        if (a[l] == 2)
        {
            for (; r1 > l; r1--)
            {
                if (a[r1] == 1)
                {
                    swap(a[l], a[r1]);
                    ans.push_back(make_pair(l + 1, r1 + 1));
                    break;
                }
            }
        }
        if (a[l] == 1)
        {
            for (; r0 > l; r0--)
            {
                if (a[r0] == 0)
                {
                    swap(a[l], a[r0]);
                    ans.push_back(make_pair(l + 1, r0 + 1));
                    r1 = max(r0, r1);
                    break;
                }
            }
        }
    }

    for (l = sum[0]; l < sum[0] + sum[1]; l++)
    {
        if (a[l] == 2)
        {
            for (; r1 > l; r1--)
            {
                if (a[r1] == 1)
                {
                    swap(a[l], a[r1]);
                    ans.push_back(make_pair(l + 1, r1 + 1));
                    break;
                }
            }
        }
    }

    if(ans.size()>n) while(1);
    cout << ans.size() << '\n';
    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    // cout << '\n';
    return;
}

/*

*/

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
