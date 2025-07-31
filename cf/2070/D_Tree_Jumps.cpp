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
    stack<i8> depth;
    cin >> n;
    vpii a(n + 1, make_pair(0, 0));
    vi son(n + 1);
    a[1].second = 1;
    for (i = 2; i <= n; i++)
    {
        cin >> a[i].first;
        son[a[i].first]++;
    }
    for (i = 2; i <= n; i++)
    {
        depth.push(i);
        while (!depth.empty())
        {
            i8 next = a[depth.top()].st;
            if (a[next].nd != 0)
            {
                while (!depth.empty())
                {
                    a[depth.top()].nd = a[next].nd + 1;
                    next = depth.top();
                    depth.pop();
                }
            }
            else
                depth.push(next);
        }
    }
    map<i8, vi> num;
    for (i = 0; i <= n; i++)
    {
        num[a[i].nd].push_back(i);
    }
    vi cost(n + 1, 0);
    cost[1] = 1;
    i8 k;
    vi sumd(num.size(), 0);
    sumd[1] = 1;
    sumd[2] = num[2].size();
    for (i = 2; i < num.size(); i++)
    {
        for (j = 0; j < num[i].size(); j++)
        {
            if (i == 2)
                cost[num[i][j]] = 1;
            else
            {
                cost[num[i][j]] += sumd[i - 1] - cost[a[num[i][j]].st];
                cost[num[i][j]] %= mod9;
                sumd[i] += cost[num[i][j]];
            }
        }
    }
    sum = 0;
    for (i = 1; i <= n; i++)
        sum += cost[i];
    cout << (sum % mod9 + mod9) % mod9;
    cout << '\n';
    return;
}

/*
 */

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
    // #endif

    unsigned long long _ = 1;
    cin >> _;
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