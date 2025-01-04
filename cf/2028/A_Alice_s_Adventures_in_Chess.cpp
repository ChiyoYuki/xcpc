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
    ll a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    pair<ll,ll> pos;
    pos.first=0;
    pos.second=0;
    for(i=0;i<1e4;i++)
    {
        if(s[i%n]=='N') pos.second++;
        if(s[i%n]=='S') pos.second--;
        if(s[i%n]=='E') pos.first++;
        if(s[i%n]=='W') pos.first--;
        if(pos.first==a&&pos.second==b)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO";
    cout << endl;
    return;
}

/*

*/