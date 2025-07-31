#include<bits/stdc++.h>

using namespace std;

#define i8 long long
#define vi vector<long long>

void solve()
{
    i8 a,b,c;
    cin>>a>>b>>c;
    if(a==0&&b==0)
    {
        if(c==0)
        {
            cout<<0<<'\n';
            return;
        }
        else
        {
            cout<<-1;
            return;
        }
    }
    vector<i8> did;
    i8 ah=1,bh=1,ch=1;
    while(bh*2<=b) bh<<=1;
    while(ah*2<=a) ah<<=1;
    while(ch*2<=c) ch<<=1;
    if(ah>bh)
    {
        did.push_back(4);
        b^=a;
    }
    if(ch>bh)
    {
        i8 chh=ch;
        i8 diff=0;
        while(chh!=bh)
        {
            diff++;
            chh>>=1;
        }
        while(diff)
        {
            if(((bh<<diff)&c)^(bh&a))
            {
                a^=b;
                did.push_back(3);
            }
            a<<=1;
            ah<<=1;
            did.push_back(1);
            diff--;
        }
    }
    while(b)
    {
        if((bh&a)^(bh&c))
        {
            a^=b;
            did.push_back(3);
        }
        b>>=1;
        bh>>=1;
        did.push_back(2);
    }
    did.push_back(4);
    cout<<did.size()<<'\n';
    for(int i=0;i<did.size();i++)
    {
        cout<<did[i]<<' ';
    }
    return ;
}

int main()
{
    int _;
    cin>>_;
    while(_--)
    {
        solve();
        cout<<'\n';
    }
}