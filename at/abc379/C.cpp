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
    cin>>n>>m;
    vector<pair<ll,ll> > xa(m);
    for(i=0;i<m;i++)
    {
	    cin>>xa[i].first;
    }
    for(i=0;i<m;i++)
    {
	    cin>>xa[i].second;
    }
    xa.push_back({n+1,0});
    sort(xa.begin(),xa.end());
    if(xa[0].first!=1)
    {
	    cout<<-1<<endl;
	    return;
    }
    else
    {
	    for(i=1;i<m+1;i++)
	    {
		    if(xa[i].first-xa[i-1].first<=xa[i-1].second)
		    {
			    sum=(xa[i].first-xa[i-1].first);
                sum--;
			    if(sum%2==0) ans+=(sum/2)*(sum+1);
			    else ans+=(sum+1)/2*sum;
		    }
		    else
		    {
			    cout<<-1<<endl;
			    return;
		    }
	    }
    }
    cout<<ans;
    cout << endl;
    return;
}

/*

*/
