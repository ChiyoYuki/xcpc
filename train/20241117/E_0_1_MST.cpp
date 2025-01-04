/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef pair<long long, long long> pll2;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<pair<long long, long long>> vpll2;

const int intinf = 0x3f3f3f3f;
const int llinf = 0x3f3f3f3f3f3f3f3f;
const int mod9 = 998244353;
const int moda = 1000000007;

void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n, m, sum = 0, ans = 0;

    cin >> n >> m;
    ans = n;
    vll p(n + 1, 0);
    vvll g(n + 1, vll(n + 1, 0));
    vpll2 ab(m);
    for (i = 0; i < m; i++)
    {
        cin >> ab[i].st >> ab[i].nd;
        if (ab[i].st > ab[i].nd)
            swap(ab[i].st, ab[i].nd);
        g[ab[i].st][ab[i].nd] = 1;
        g[ab[i].nd][ab[i].st] = 1;
    }
    bool flag = false;
    for (i = 1; i <= n; i++)
    {
        flag = false;
        for (j = 1; j <= n; j++)
        {
            if (g[i][j] == 0 && i != j)
            {
                flag = true;
                g[i][j] = 1;
                g[j][i] = 1;
                break;
            }
        }
        if (flag)
            ans--;
    }

    cout << ans - 1;
    cout << '\n';
    return;
}

/*

*/