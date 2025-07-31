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
void YORN(bool f);
void Yorn(bool f);
void yorn(bool f);

bool cmp(pair<pii, i8> x, pair<pii, i8> y)
{
    if (x.st.nd == y.st.nd)
        return x.st.st > y.st.st;
    else
        return x.st.nd < y.st.nd;
}

void solve(void)
{
    i8 i = 0, j = 0;
    i8 n = 0, m = 0;
    i8 sum = 0;
    i8 k;
    cin >> n >> m >> k;
    vector<pair<pii, i8>> rc(k + 1);
    rc[0] = {{0, 0}, 0};
    for (i = 1; i <= k; i++)
    {
        cin >> rc[i].st.st >> rc[i].st.nd;
        rc[i].nd = i;
    }
    sort(rc.begin() + 1, rc.end(), cmp);
    pii pos = {1, 0};
    set<i8> save;
    auto now = rc.begin() + 1, next = now;
    while (1)
    {
        for (next = now; next != rc.end(); next++)
        {
            if ((*next).st.nd > pos.nd && (*next).st.st >= pos.st)
            {
                save.insert((*next).nd);
                break;
            }
        }
        if (next == rc.end())
            break;
        sum+=((n+1)-(pos.st-1))*((*next).st.nd-pos.nd);
        pos.st=(*next).st.st+1;
        pos.nd=(*next).st.nd;
        now=next;
    }
    sum+=((n+1)-(pos.st-1))*(m-(pos.nd-1));
    sum-=(n+m+1);
    cout<<sum;
    cout << '\n';
    for(i=1;i<=k;i++)
    {
        if(save.find(i)!=save.end()) cout<<"1 ";
        else cout<<"0 ";
    }
    cout<<'\n';
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
