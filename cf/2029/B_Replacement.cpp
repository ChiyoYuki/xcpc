/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define lf double
#define vc vector<char>
#define vll vector<long long>
#define vvll vector<vector<long long>>

using namespace std;

void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n, m, sum = 0, ans = 0;
    ll sum0=0,sum1=0;
    cin>>n;
    string s,r;
    cin>>s>>r;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='0') sum0++;
        else sum1++;
    }
    for(i=0;i<r.size();i++)
    {
        if((sum0==0&&sum1!=1)||(sum0!=1&&sum1==0))
        {
            cout<<"NO"<<endl;
            return;
        }
        if(r[i]=='0') sum1--;
        else sum0--;
    }
    cout<<"YES";
    cout << endl;
    return;
}

/*

*/