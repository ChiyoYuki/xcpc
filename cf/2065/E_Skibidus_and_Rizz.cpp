/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define elif else if

typedef signed char i1;
typedef signed short int i2;
typedef signed int i4;
typedef signed long long int i8;
typedef unsigned char u1;
typedef unsigned short int u2;
typedef unsigned int u4;
typedef unsigned long long int u8;
typedef float f06;
typedef double f15;

typedef vector<i8> vi;
typedef deque<i8> di;
typedef deque<i8> di;
typedef priority_queue<i8> pqi;
typedef pair<i8, i8> pii;
typedef map<i8, i8> mii;
typedef vector<vector<i8>> vvi;
typedef vector<pair<i8, i8>> vpii;
typedef string str;

const i4 i4inf = 0x3f3f3f3f;
const i4 i4max = INT32_MAX;
const i4 i4min = INT32_MIN;
const u4 u4max = UINT32_MAX;
const i8 i8inf = 0x3f3f3f3f3f3f3f3f;
const i8 i8max = INT64_MAX;
const i8 i8min = INT64_MIN;
const u8 u8max = UINT64_MAX;
const int mod9 = 998244353;
const int moda = 1000000007;

void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

void solve(void)
{
    i8 i = 0, j = 0;
    i8 n = 0, m = 0;
    i8 sum = 0, k;

    cin >> n >> m >> k;
    i8 ma, mi;
    ma = max(n, m);
    mi = max(max(n, m) - min(n, m), 1LL);
    if (k < mi || k > ma)
    {
        cout << -1 << '\n';
        return;
    }
    bool now;
    if (n > m)
    {
        for (i = 0; i < k; i++)
        {
            cout << 0;
        }
        n -= k;
        now = false;
    }
    else
    {
        for (i = 0; i < k; i++)
        {
            cout << 1;
        }
        m -= k;
        now = true;
    }

    while (m != 0 && n != 0)
    {
        if (now)
        {
            cout << 0;
            n--;
        }
        else
        {
            cout << 1;
            m--;
        }
        now = !now;
    }
    while (m--)
        cout << 1;
    while (n--)
        cout << 0;
    cout << '\n';
    return;
}

/*

*/