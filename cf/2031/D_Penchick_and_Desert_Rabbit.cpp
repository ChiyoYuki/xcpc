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
    ll n, m, sum = 0;
    cin >> n;
    vll a(n), rmi(n), lma(n), ans(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            lma[i] = a[i];
        else
            lma[i] = max(lma[i - 1], a[i]);
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            rmi[i] = a[i];
            ans[i] = lma[i];
        }
        else
        {
            rmi[i] = min(rmi[i + 1], a[i]);
            ans[i] = (lma[i] > rmi[i + 1]) ? ans[i + 1] : lma[i];
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout << endl;
    return;
}

/*

*/