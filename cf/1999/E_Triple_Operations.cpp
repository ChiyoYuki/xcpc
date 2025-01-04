/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
// using namespace i11e;

#define st first
#define nd second

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef pair<ll, ll> pll2;
typedef priority_queue<ll> pqll;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll2;
typedef string str;

const int intinf = 0x3f3f3f3f;
const int mod9 = 998244353;
const int moda = 1000000007;

namespace i11e
{
    void ask(ll a);
    void ask(ll a, ll b);
    void ans(ll a);
    void ans(str s);
    void ans(vll a);
}
void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

void solve(void)
{
    ll i = 0, j = 0;

    ll l, r;
    ll sum = 0;
    cin >> l >> r;
    ll x = l;
    while (x != 0)
    {
        x /= 3;
        sum++;
    }
    sum *= 2;
    vector<ll> aaa;
    aaa.push_back(0);
    aaa.push_back(1);
    while (aaa.back() < 600000)
        aaa.push_back(aaa.back() * 3);
    ll now = 0;
    while (aaa[now] < l + 1)
        now++;
    sum += (min(r, aaa[now]) - l) * (now - 1);
    while (aaa[now + 1] < r)
    {
        sum += (aaa[now + 1] - aaa[now]) * now;
        now++;
    }
    // sum += (r - max(l, aaa[now - 1] + 1)) * now;
    cout << sum << '\n';
    return;
}

/*


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    // int a = 0, b = 0;
    // cin >> a >> b;
    // int x=a;
    // int curr = 1;
    // int sum = 0, count = 0;
    // while (curr * 3 < a)
    // {
    //     curr *= 3;
    //     count++;
    // }
    // curr*=3;
    // count++;
    //  while (x!=0)
    //  {
    //      x /= 3;
    //      sum++;
    //  }
    //  sum*=2;


    // while(true)
    // {
    //     int c=curr/3;
    //     if(curr<b)
    //     {
    //         sum+=(curr-max(a+1,c)+1)*count;
    //         curr*=3;
    //     }
    //     else
    //     {
    //         sum+=(b-max(a+1,c)+1)*count;
    //         break;
    //     }
    //     count+=1;
    // }
    // cout<<sum<<endl;


}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}


*/

void i11e::ask(ll a)
{
    cout << "? " << a << endl;
    cout.flush();
    return;
}

void i11e::ask(ll a, ll b)
{
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    return;
}

void i11e::ans(ll a)
{
    cout << "! " << a << endl;
    cout.flush();
    return;
}

void i11e::ans(str s)
{
    cout << "! " << s << endl;
    cout.flush();
    return;
}

void i11e::ans(vll a)
{
    cout << "!";
    for (auto ii = a.begin(); ii != a.end(); ii++)
        cout << ' ' << (*ii);
    cout << endl;
    cout.flush();
    return;
}
