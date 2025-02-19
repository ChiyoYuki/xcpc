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
    vll p(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    bool f = true;
    for (i = 1; i <= n; i++)
    {
        if (p[i] == i)
            continue;
        else if (p[i] == i + 1 && p[i + 1] == i)
        {
            i++;
            continue;
        }
        else
        {
            f = false;
            break;
        }
    }
    if (f)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return;
}

/*

*/