/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

void solve(void);

int main(void)
{
    srand(time(NULL));
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    int n,i;
    // cin >> _;
    cin >> n;
    // cin>>n;
    // vi a(n);
    for (i = 0; i < n; i++)
        cout << rand() % n + 1 << ' ';
    cout << '\n';
    return 0;
}

/*

*/