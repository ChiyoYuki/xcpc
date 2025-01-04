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
    cin >> n;
    if (n % 2 == 0)
    {
        for (i = 1; i <= n / 2; i++)
        {
            cout << i << ' ' << i << ' ';
        }
    }
    else
    {
        if (n < 27)
            cout << -1;
        else
        {
            j=14;
            cout << "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 13 13 1 12 ";
            for (i = 27; i < n; i += 2)
            {
                cout<<j<<' '<<j<<' ';
                j++;
            }
        }
    }
    cout << endl;
    return;
}

/*

*/