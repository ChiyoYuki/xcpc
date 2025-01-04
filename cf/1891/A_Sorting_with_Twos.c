#include<stdio.h>

int main()
{
	int t,n,i,j,k;
	scanf("%d",&t);
	int T[t];
	for(i=0;i<t;i++)
	{
		T[i]=1;
		scanf("%d",&n);
		int a[20],m;
		for(j=0;j<n;j++) scanf("%d",&a[j]);
		for(j=n;j<20;j++) a[j]=1001;
		if(a[2]>a[3]) T[i]=0;
		for(j=4;j<8;j++)
		{
			for(k=j+1;k<8;k++)
			{
				if(a[j]>a[k]) T[i]=0;
			}
		}
		for(j=8;j<16;j++)
		{
			for(k=j+1;k<16;k++)
			{
				if(a[j]>a[k]) T[i]=0;
			}
		}
		for(j=16;j<20;j++)
		{
			for(k=j+1;k<20;k++)
			{
				if(a[j]>a[k]) T[i]=0;
			}
		}
	}
	for(i=0;i<t;i++)
	{
		if(T[i]==0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
