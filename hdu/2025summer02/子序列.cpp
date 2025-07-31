// Author:  ChiyoYuki
// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// Judge: $(JUDGE)
// URL: $(URL)
// Memory Limit: $(MEMLIM)
// Time Limit: $(TIMELIM)
// Start: $(DATE)

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

template<typename __Tp>
using vc=vector<__Tp>;
template<typename __Tp>
using dq=deque<__Tp>;
template<typename __Tp>
using pq=priority_queue<__Tp>;

template<typename __Tp0,typename __Tp1>
using pr=pair<__Tp0, __Tp1>;
template<typename __Tp0,typename __Tp1>
using mp=map<__Tp0,__Tp1>;
template<typename __Tp0,typename __Tp1>
using vp=vector<pair<__Tp0, __Tp1>>;


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

    // cin>>n;
    // vi a(n);
    // for(i=0;i<n;i++) cin>>a[i];

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

void YORN(bool f) {cout << (f ? "YES\n" : "NO\n");}
void Yorn(bool f) {cout << (f ? "Yes\n" : "No\n");}
void yorn(bool f) {cout << (f ? "yes\n" : "no\n");}
