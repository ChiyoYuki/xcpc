#include<bits/stdc++.h>

using namespace std;

#define i8 long long
#define vector<long long>

void solve()
{
    i8 x,y;
    cin>>x>>y;
    set<i8> st;
    st.insert(x);
    st.insert(y);
    i8 n=x,m=y;
    i8 sum=0;
    while(n!=0&&m!=0)
    {
        sum++;
        if(n>m)
        {
            n-=m;
            m<<=1LL;
        }
        else
        {
            m-=n;
            n<<=1LL;
        }
        if(st.find(n)!=st.end())
        {
            cout<<-1;
            return;
        }
        st.insert(n);
        st.insert(m);
    }
    cout<<sum;
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