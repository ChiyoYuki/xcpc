#include<iostream>

int main()
{
    int sum=0;
    int a[10]={289,327,456,780,350,862,278,430,560,650},b;
    for(int i=0;i<10;i++){std::cin>>b;sum+=b*a[i];}
    std::cout<<sum/10<<"."<<sum%10;
    return 0;
}