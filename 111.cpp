#include<bits/stdc++.h>

using namespace std;

#define MAX 102

#define time 50

#define ss 28

int main()
{
    cout<<MAX+ss*time<<endl;
    for(int i=0;i<MAX;i++)
    {
        cout<<(i+1)%MAX+1<<" ";
    }
    for(int i=0;i<time;i++)
    {
        for(int j=0;j<ss;j++)
        {
            cout<<MAX+(j+1)%ss+1+i*ss<<" ";
        }
    }
    return 0;
}