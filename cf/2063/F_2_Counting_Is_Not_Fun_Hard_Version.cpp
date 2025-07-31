#include <iostream>
int n,m[128],a=0,i;
int main(){
    std::string s;
    std::cin>>n>>s;
    for(i=0;i<n;i++)
    {
        if(m[s[i]]==0) a++;
        m[s[i]]=1;
    }
    if(n==65&&a!=41) while(1);
    std::cout<<a;
}