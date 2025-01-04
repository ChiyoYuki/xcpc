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
    ll i = 0, j = 0;
    ll n, m, sum = 0, ans = 0;
    ll b, c;
    cin >> n >> b >> c;
    if (b == 0)
    {
        if (c < n - 2)
            ans = -1;
        else if (c == n - 1 || c == n - 2)
            ans = n - 1;
        else
            ans = n;
    }
    else if (b == 1)
    {
        if (c >= n)
            ans = n;
        else
            ans = c;
    }
    else
    {
        sum = n - c + b;
        ans = sum / b;
        if (sum % b == 0)
            ans--;
        if (ans < 0)
            ans = 0;
        ans = n - ans;
    }
    cout << ans;
    cout << endl;
    return;
}

/*

*/