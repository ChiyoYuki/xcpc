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
    ll n, m, sum = 0, ans = 0;
    ll q;
    cin>>q;
    vll p;
    for(i=0;i<q;i++)
    {
	    cin>>n;
	    if(n==1)
	    {
		    p.push_back(0);
	    }
	    else if(n==2)
	    {
		    cin>>m;
		    for(auto ii=p.begin();ii<p.end();ii++)
		    {
			    *ii+=m;
		    }
	    }
	    else if(n==3)
	    {
		    cin>>m;
		    auto iii=p.begin();
		    while(iii!=p.end())
		    {
			    if(*iii>=m)
			    {
				    sum++;
				    p.erase(iii);
			    }
			    else break;
		    }
		    cout<<sum<<endl;
	    }
    }
    return;
}

/*

*/
