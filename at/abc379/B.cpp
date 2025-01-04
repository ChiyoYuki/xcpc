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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll m, sum = 0, ans = 0;
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(i=0;i<n;i++)
    {
	    if(s[i]=='O') sum++;
	    if(s[i]=='X') sum=0;
	    if(sum==k)
	    {
		    sum=0;
		    ans++;
	    }
    }
    cout<<ans;
    cout << endl;
    return;
}

/*

*/
