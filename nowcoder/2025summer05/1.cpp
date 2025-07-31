#include<bits/stdc++.h>

using namespace std;
#define i8 long long
#define vi vector<i8>

void solve()
{
  int n;
  cin>>n;
  if(n%2==0)
  {
    cout<<(1+n+n/2)*2;
  }
  else cout<<(n+n/2+1)*2;
  return ;
}

int main()
{
  int _=1;
  // cin>>_;
  while(_--)
  {
    solve();
    cout<<'\n';
  }
  return 0;
}
