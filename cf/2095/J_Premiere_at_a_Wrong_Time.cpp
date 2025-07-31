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
    str a,b;
    cin>>a>>b;
    i8 c=0,d=0;
    for(i=0;i<a.size()-1;i++)
    {
        c*=9;
        if(a[i]=='l')
        {
            i++;
            if(a[i]=='a') c+=0;
            elif(a[i]=='e') c+=1;
            elif(a[i]=='o') c+=2,i++;
        }
        elif(a[i]=='s')
        {
            i+=2;
            if(a[i]=='a') c+=3;
            elif(a[i]=='e') c+=4;
            elif(a[i]=='o') c+=5,i++;
        }
        elif(a[i]=='t')
        {
            i++;
            if(a[i]=='a') c+=6;
            elif(a[i]=='e') c+=7;
            elif(a[i]=='o') c+=8,i++;
        }
    }
    for(i=0;i<b.size()-1;i++)
    {
        d*=9;
        if(b[i]=='l')
        {
            i++;
            if(b[i]=='a') d+=0;
            elif(b[i]=='e') d+=1;
            elif(b[i]=='o') d+=2,i++;
        }
        elif(b[i]=='s')
        {
            i+=2;
            if(b[i]=='a') d+=3;
            elif(b[i]=='e') d+=4;
            elif(b[i]=='o') d+=5,i++;
        }
        elif(b[i]=='t')
        {
            i++;
            if(b[i]=='a') d+=6;
            elif(b[i]=='e') d+=7;
            elif(b[i]=='o') d+=8,i++;
        }
    }
    i8 e=c+d;
    str ans="";
    while(e)
    {
        if(e%3==0) ans='a'+ans;
        elif(e%3==1) ans='e'+ans;
        elif(e%3==2) ans="on"+ans;
        e/=3;
        if(e%3==0) ans='l'+ans;
        elif(e%3==1) ans="sh"+ans;
        elif(e%3==2) ans='t'+ans;
        e/=3;
    }
    ans=ans+'s';
    cout<<ans;
    // cin>>n;
    // vi a(n);
    // for(i=0;i<n;i++) cin>>a[i];

    cout << '\n';
    return;
}

/*
0 la
1 le
2 lon
3 sha
4 she
5 shon
6 ta
7 te
8 ton

lon shon le ta sha sha le te sha tes
2   5    1  6  3   3   1  7  3   7  
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

void YORN(bool f) {cout << (f ? "YES" : "NO");}
void Yorn(bool f) {cout << (f ? "Yes" : "No");}
void yorn(bool f) {cout << (f ? "yes" : "no");}
