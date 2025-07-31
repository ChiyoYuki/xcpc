#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,v,w;
    cin>>n>>v>>w;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
	}
    sort(a.begin(),a.end());
    int sum=0,num=0;
    for(int i=0;i<n;i++)
    {
        if(sum+a[i]<=w*(num+1))
        {
            sum+=a[i];
            num++;
        }
        else break;
	}
    if(sum==0) cout<<"0 0.00";
    else
    {
        double nongdu=sum/(100.0*num);
        printf("%d %.2lf",num*v,nongdu);
    }
}