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

void solve(void)
{
    i8 i = 0, j = 0;
    i8 n = 0, m = 0;
    i8 sum = 0;
    cin >> n >> m;
    pii ter,beg;
    bool key=false;
    vector<str> a(n+2);
    deque<pii> bfs;
    vvi b(n+2,vi(m+2)),c;

    for(i=0;i<=m+1;i++)
    {
        a[0]=a[0]+'#';
        a[n+1]=a[n+1]+'#';
        b[0][i]=-1;
        b[n+1][i]=-1;
    }


    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]='#'+a[i]+'#';
        for(j=0;j<a[i].size();j++)
        {
            if(a[i][j]=='.') b[i][j]=-2;
            elif(a[i][j]=='#') b[i][j]=-1;
            elif(a[i][j]=='T') b[i][j]=-2,ter=make_pair(i,j);
            elif(a[i][j]=='S') b[i][j]=0,bfs.push_back(make_pair(i,j)),beg=make_pair(i,j);
            elif(a[i][j]=='P') b[i][j]=-2;
        }
    }
    c=b;
    c[ter.st][ter.nd]=0;
    c[beg.st][beg.nd]=-2;
    i8 ma=i8inf;
    while(!bfs.empty())
    {
        if(b[bfs.front().st][bfs.front().nd-1]==-2)
        b[bfs.front().st][bfs.front().nd-1]=b[bfs.front().st][bfs.front().nd]+1,bfs.push_back({bfs.front().st,bfs.front().nd-1});
        if(b[bfs.front().st][bfs.front().nd+1]==-2)
        b[bfs.front().st][bfs.front().nd+1]=b[bfs.front().st][bfs.front().nd]+1,bfs.push_back({bfs.front().st,bfs.front().nd+1});
        if(b[bfs.front().st-1][bfs.front().nd]==-2)
        b[bfs.front().st-1][bfs.front().nd]=b[bfs.front().st][bfs.front().nd]+1,bfs.push_back({bfs.front().st-1,bfs.front().nd});
        if(b[bfs.front().st+1][bfs.front().nd]==-2)
        b[bfs.front().st+1][bfs.front().nd]=b[bfs.front().st][bfs.front().nd]+1,bfs.push_back({bfs.front().st+1,bfs.front().nd});
        bfs.pop_front();
    }
    bfs.push_back({ter.st,ter.nd});
    while(!bfs.empty())
    {
        if(c[bfs.front().st][bfs.front().nd-1]==-2)
        c[bfs.front().st][bfs.front().nd-1]=c[bfs.front().st][bfs.front().nd]+1,bfs.push_back({bfs.front().st,bfs.front().nd-1});
        if(c[bfs.front().st][bfs.front().nd+1]==-2)
        c[bfs.front().st][bfs.front().nd+1]=c[bfs.front().st][bfs.front().nd]+1,bfs.push_back({bfs.front().st,bfs.front().nd+1});
        if(c[bfs.front().st-1][bfs.front().nd]==-2)
        c[bfs.front().st-1][bfs.front().nd]=c[bfs.front().st][bfs.front().nd]+1,bfs.push_back({bfs.front().st-1,bfs.front().nd});
        if(c[bfs.front().st+1][bfs.front().nd]==-2)
        c[bfs.front().st+1][bfs.front().nd]=c[bfs.front().st][bfs.front().nd]+1,bfs.push_back({bfs.front().st+1,bfs.front().nd});
        bfs.pop_front();
    }
    for (i = 1; i <= n; i++)
    {
        for(j=0;j<a[i].size();j++)
        {
            if(a[i][j]=='P') ma=min(ma,b[i][j]+c[i][j]);
        }
    }
    cout<<ma;
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
    // cin >> _;
    while (_--)
        solve();
    return 0;
}

void YORN(bool f) { cout << (f ? "YES" : "NO"); }
void Yorn(bool f) { cout << (f ? "Yes" : "No"); }
void yorn(bool f) { cout << (f ? "yes" : "no"); }
