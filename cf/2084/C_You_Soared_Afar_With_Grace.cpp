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

template <typename __Tp>
using vc = vector<__Tp>;
template <typename __Tp>
using dq = deque<__Tp>;
template <typename __Tp>
using pq = priority_queue<__Tp>;

template <typename __Tp0, typename __Tp1>
using pr = pair<__Tp0, __Tp1>;
template <typename __Tp0, typename __Tp1>
using mp = map<__Tp0, __Tp1>;
template <typename __Tp0, typename __Tp1>
using vp = vector<pair<__Tp0, __Tp1>>;

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
void YORN(bool f);
void Yorn(bool f);
void yorn(bool f);

void solve(void)
{
    i8 i = 0, j = 0;
    i8 n = 0, m = 0;
    i8 sum = 0;
    mii ba, wheb, whea;
    cin >> n;
    vi a(n), b(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        whea[a[i]] = i;
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
        ba[b[i]] = a[i];
        wheb[b[i]] = i;
    }
    bool f = true;
    i8 rem = n % 2;
    for (i = 1; i <= n; i++)
    {
        if (i == ba[i])
            rem--;
        elif (i != ba[ba[i]]) f = false;
        if (rem < 0)
            f = false;
        if (!f)
            break;
    }
    if (!f)
    {
        cout << -1 << '\n';
        return;
    }
    vpii ans;
    if (n % 2)
    {
        for (i = 0; i < n; i++)
        {
            if (a[i] == b[i])
            {
                if (i != n / 2)
                {
                    ans.push_back({i, n / 2});
                    wheb[b[i]] = n / 2;
                    wheb[b[n / 2]] = i;
                    swap(a[i], a[n / 2]);
                    swap(b[i], b[n / 2]);
                }
                break;
            }
        }
    }
    for (i = 0; i < n / 2; i++)
    {
        if (wheb[a[i]] != n - 1 - i)
        {
            ans.push_back({wheb[a[i]], n - 1 - i});
            i8 x = wheb[a[i]];
            wheb[b[n - i - 1]] = wheb[a[i]];
            wheb[a[i]] = n - 1 - i;
            swap(b[x], b[n - 1 - i]);
            swap(a[x], a[n - 1 - i]);
        }
    }
    cout << ans.size() << '\n';
    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i].st + 1 << ' ' << ans[i].nd + 1 << '\n';
    }
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

void YORN(bool f) { cout << (f ? "YES" : "NO"); }
void Yorn(bool f) { cout << (f ? "Yes" : "No"); }
void yorn(bool f) { cout << (f ? "yes" : "no"); }
