#include<bits/stdc++.h>

#define Scc(c) scanf("%c",&c)
#define Scs(s) scanf("%s",s)
#define Sci(x) scanf("%d",&x)
#define Sci2(x, y) scanf("%d%d",&x,&y)
#define Sci3(x, y, z) scanf("%d%d%d",&x,&y,&z)
#define Scl(x) scanf("%I64d",&x)
#define Scl2(x, y) scanf("%I64d%I64d",&x,&y)
#define Scl3(x, y, z) scanf("%I64d%I64d%I64d",&x,&y,&z)
#define Pri(x) printf("%d\n",x)
#define Prl(x) printf("%I64d\n",x)
#define Prc(c) printf("%c\n",c)
#define Prs(s) printf("%s\n",s)
#define For(i,x,y) for(int i=x;i<y;i++)
#define For_(i,x,y) for(int i=x;i<=y;i++)
#define FFor(i,x,y) for(int i=x;i>y;i--)
#define FFor_(i,x,y) for(int i=x;i>=y;i--)
#define Mem(f, x) memset(f,x,sizeof(f))
#define LL long long
#define ULL unsigned long long
#define MAXSIZE 500005
#define INF 0x3f3f3f3f

const int mod=1e9+7;
const double PI = acos(-1.0);

using namespace std;

int pre[MAXSIZE];
int num[MAXSIZE];
int siz[MAXSIZE];
void init(int n)
{
    For_(i,1,n)
    {
        pre[i]=i;
        num[i]=0;
        siz[i]=1;
        //   f[i]=-1;
    }
}
int find(int x)
{
    if(x==pre[x])
        return x;
    int y=pre[x];
    pre[x]=find(pre[x]);
    num[x]+=num[y];
    return pre[x];
}
void merge(int x,int y)
{
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)
    {
        pre[xx]=yy;
        num[xx]=siz[yy];
        siz[yy]+=siz[xx];
    }
}
int main()
{
    int t;
    Sci(t);
    getchar();
    init(t);
    while(t--)
    {
        char c;
        int x,y;
        // Scc(c);
        //Sci2(x,y);
        scanf("%c %d %d",&c,&x,&y);
        getchar();
        if(c=='M')
            //pre[x]=pre[y];
            merge(x,y);
        else
        {
            if(find(x)!=find(y))
                Pri(-1);
            else
                Pri(abs(num[x]-num[y])-1);
        }
    }
    return 0;
}