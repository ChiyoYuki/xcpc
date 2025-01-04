/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define lf double
#define vc vector<char>
#define vll vector<long long>
#define vvll vector<vector<long long>>

using namespace std;

void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0;
    ll n, m, sum = 0, ans = 0;
    cin >> n;
    vector<char> flag(n, 0);
    char vis[n + 1];
    vll q(n), k(n), j(n);
    ll pos;
    for (i = 0; i < n; i++)
    {
        cin >> pos;
        q[pos - 1] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        cin >> pos;
        k[pos - 1] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        cin >> pos;
        j[pos - 1] = i + 1;
    }

    cout << "YES" << endl
         << n - 1 << endl;
    for (i = 1; i < n; i++)
    {
        cout << flag[i] << ' ' << i + 1 << endl;
    }
    return;
}

/*

*/