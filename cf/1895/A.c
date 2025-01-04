#include<stdio.h>
int ma(int x,int y)
{
	if(x>y) return x;
	else return y;
}

int main()
{
	int t,x,y,k,pre,ans[128];
	int i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d",&x,&y,&k);
		pre=x-y;
		if(pre<0) pre=-pre;
		if(pre<=k)
		{
			ans[i]=ma(x,y);
			continue;
		}
		else if(x>y) ans[i]=x;
		if(x<y) ans[i]=y+y-x-k;
	}
	for(i=0;i<t;i++) printf("%d\n",ans[i]);
	return 0;
}
