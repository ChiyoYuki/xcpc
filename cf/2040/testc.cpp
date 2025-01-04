#include<bits/stdc++.h>

using ll = long long;


void solve()
{
    int len=0,ptr=0;
    std::cin>>len>>ptr;
    std::vector<int> a(len);

    int head=0,tail=len-1;
    int count =2;

    if(len ==1 && ptr ==1) 
    {
        std::cout<<1<<std::endl;
        return;
    }
    else if(len ==1)
    {
        std::cout<<-1<<std::endl;
        return;
    }
    if(len ==2)
    {
        if(ptr ==1) std::cout<<1<<' '<<2<<std::endl;
        if(ptr ==2) std::cout<<2<<' '<<1<<std::endl;
        else std::cout<<-1<<std::endl;
        return;
    }
    
    int l=len-1;
    while(--l)
    {
        count*=2;
    }
    if(ptr>count)
    {
        std::cout<<-1<<std::endl;
        return;
    }

    int number =1;
    int num_ptr=count/2;

/*
    number 1
    len 4
    numptr 8
    ptr 6
    head 0
    tail 2
    */

    while(number!=len)
    {
        count/=2;
        if(ptr<=num_ptr)
        {
            a[head]=number++;
            head++;
            num_ptr-=count/2;
        }
        if(ptr>num_ptr)
        {
            a[tail]=number++;
            tail--;
            num_ptr+=count/2;
        }
        
        
    }
    a[head]=number;
    for(int q=0;q<len;q++)
        std::cout<<a[q]<<' ';
    std::cout<<std::endl;

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}   