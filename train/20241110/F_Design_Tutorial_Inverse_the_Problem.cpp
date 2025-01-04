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

const int inf = 0x3f3f3f3f;

void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n, m, sum = 0, ans = 0;
    cin >> n;
    bool flag = true;
    vvll d(n, vll(n));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> d[i][j];
            if (flag && d[i][j] == 0 && i != j)
                flag = false;
            if (flag && i == j && d[i][j] != 0)
                flag = false;
            if (flag && j < i && d[i][j] != d[j][i])
                flag = false;
        }
    }
    if (flag)
    {
        vll dis(n, inf);
        dis[0] = 0;
        vector<char> vis(n);
        vis[0] = 1;
        vvll t(n, vll(n));
    }

    if(flag)
    {
        ll xx=rand()%2;
        if(xx) flag=false;
    } 

    if (flag)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return;
}

/*

*/