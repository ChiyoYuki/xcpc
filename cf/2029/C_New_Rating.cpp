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
    ll ma=0,mi=4e5;
    cin >> n;
    vll a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ans=ma;
    if(!flag) ans--;
    if(flag3) ans++;
    cout<<ans;
    cout << endl;
    return;
}

/*

*/