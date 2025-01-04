#include<bits/stdc++.h>

using namespace std;

int main()
{
	int j,t,n,a[200],b[100],ans;
	int i;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d",&n);
		for(i=0;i<2*n;i+=2)
		{
			scanf("%d%d",&a[i],&a[i+1]);
		}
		sort(a,a+n*2);
		ans=a[2*n-1]+a[n-1]-a[0]-a[n];
		printf("%d\n",ans);
		for(i=0;i<n;i++)
		{
			printf("%d %d\n",a[i],a[n+i]);
		}
	}
}
