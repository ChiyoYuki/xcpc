#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<long long,pair<long,long>> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        mp[b]={a,c};
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        cout<<mp[i].first<<' '<<mp[i].second<<endl;
    }
    return 0;
}