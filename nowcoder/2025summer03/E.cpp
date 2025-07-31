#include<bits/stdc++.h>

using namespace std;

#define i8 long long
#define vi vector<long long>

vector<i8> prime;

vector<long long> sieve(long long n){
    vector<char> isp(n + 1, 1);
    vector<long long> p(1, 2);
    long long i, j, r = sqrt(n);
    // isp[0]=0;isp[1]=0;
    for (i = 4; i <= n; i += 2) isp[i] = 0;
    for (i = 3; i <= r; i += 2){
        if (isp[i] == 1){
            p.push_back(i);
            j = n / i;
            if (j % 2 == 0) j--;
            for (; j >= i; j -= 2) if (isp[j] == 1) isp[i * j] = 0;
        }
    }
    if (++r % 2 == 0) r++;
    for (; r <= n; r += 2) if (isp[r] == 1) p.push_back(r);
    return p;
} 

void solve()
{
    int n;
    cin>>n;
    if(n%2==1)
    {
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
        }
        cout<<"YES";
        return;
    }
    map<i8,i8> num;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        int j=0;
        while(a[i]!=1)
        {
            if(prime[j]*prime[j]>a[i])
            {
                num[a[i]]++;
                a[i]/=a[i];
                break;
            }
            while(a[i]%prime[j]==0)
            {
                a[i]/=prime[j];
                num[prime[j]]++;
            }
            j++;
        }
    }
    for(auto ii=num.begin();ii!=num.end();ii++)
    {
        if((*ii).second%2==1)
        {
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
    return;
}

int main()
{
    int _;
    cin>>_;
    prime=sieve(5000000);
    while(_--)
    {
        solve();
        cout<<'\n';
    }
    return 0;
}