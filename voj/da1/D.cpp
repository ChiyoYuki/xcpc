/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define elif else if

using i1 = signed char;
using i2 = signed short int;
using i4 = signed int;
using i8 = signed long long int;
using u1 = unsigned char;
using u2 = unsigned short int;
using u4 = unsigned int;
using u8 = unsigned long long int;
using f06 = float;
using f15 = double;

using vi = vector<i8>;
using di = deque<i8>;
using pqi = priority_queue<i8>;
using pii = pair<i8, i8>;
using mii = map<i8, i8>;
using vvi = vector<vector<i8>>;
using vpii = vector<pair<i8, i8>>;
using str = string;

const i2 i2inf = 0x3f3f;
const i2 i2max = INT16_MAX;
const i2 i2min = INT16_MIN;
const u2 u2max = UINT16_MAX;
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
void yorn(bool f);

void solve(void)
{
    i8 i = 0, j = 0;
    i8 n = 0, m = 0;
    i8 sum = 0;

    // cin>>n;
    // vi a(n);
    // for(i=0;i<n;i++) cin>>a[i];
    str a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (i = 0; i < a.size(); i++)
        a[i] -= '0';
    for (i = 0; i < b.size(); i++)
        b[i] -= '0';
    vi c(a.size() + b.size() + 1, 0);
    for (i = 0; i < a.size(); i++)
    {
        for (j = 0; j < b.size(); j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    for (i = 1; i < c.size(); i++)
    {
        c[i] += c[i - 1] / 10;
        c[i - 1] %= 10;
    }
    reverse(c.begin(), c.end());
    i=0;
    while(c[i]==0&&i<c.size()-1) i++;
    for (; i < c.size(); i++)
        cout << c[i];
    cout << '\n';
    return;
}

/*

*/

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
#endif

    unsigned long long _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}

void yorn(bool f)
{
    if (f)
        cout << "YES";
    else
        cout << "NO";
}