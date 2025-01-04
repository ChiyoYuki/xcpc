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
    ll n, m, sum = 0, ans = 1;
    cin >> n;
    vll h(n);
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
        if (i > 0 && h[i] == h[i - 1])
            sum++;
        else
        {
            ans = max(sum, ans);
            sum = 1;
        }
    }
    ans = max(sum, ans);
    ans = n - ans;
    cout << ans;
    cout << endl;
    return;
}

/*

*/