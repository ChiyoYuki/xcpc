#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","w",stdout);
    int n=50;
    srand(time(NULL));
    int i=0;
    cout<<n<<'\n';
    for(i=0;i<n;i++)
    {
        int test=rand()%10+2;
        cout<<test<<' ';
        cout<<rand()%test+1<<'\n';
        for(int j=0;j<test;j++)
        {
            cout<<rand()%2;
        }
        cout<<'\n';
    }

}