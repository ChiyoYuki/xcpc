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
    i8 sum = 0;

    mii mp;
    cin >> n;
    vi a(n), b(n, 0);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    for (i = 0; i < n; i++)
    {
        if (mp[a[i]] == 1)
        {
            b[i] = 1;
        }
    }

    i8 l = -1, r = -1;
    i8 now = 0, ma = 0;
    i8 ll = -1, rr = -1;
    b.push_back(0);
    for (i = 0; i <= n; i++)
    {
        if (b[i] == 1)
        {
            if (ll == -1)
            {
                ll = i;
            }
        }
        else
        {
            if (ll != -1)
            {
                rr = i - 1;
                now = rr - ll + 1;
                if (now > ma)
                {
                    ma = now;
                    l = ll;
                    r = rr;
                }
                ll = -1;
            }
        }
    }
    if (l == -1)
        cout << 0;
    else
        cout << l + 1 << ' ' << r + 1;
    cout << '\n';
    return;
}

/*

*/