/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
// using namespace interactive;

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

const int intinf = 0x3f3f3f3f;
const int mod9 = 998244353;
const int moda = 1000000007;

namespace interactive
{
    void ask(ll a);
    void ask(ll a, ll b);
    void ans(ll a);
    void ans(string s);
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

void interactive::ask(ll a)
{
    cout << "? " << a << endl;
    cout.flush();
    return;
}

void interactive::ask(ll a, ll b)
{
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    return;
}

void interactive::ans(ll a)
{
    cout << "! " << a << endl;
    cout.flush();
    return;
}

void interactive::ans(string s)
{
    cout << "! " << s << endl;
    cout.flush();
    return;
}

void interactive::ans(vll a)
{
    cout << "!";
    for (auto ii = a.begin(); ii != a.end(); ii++)
        cout << ' ' << (*ii);
    cout << endl;
    cout.flush();
    return;
}

bool cmp(ll a, ll b)
{
    return a > b;
}

vector<long long> sieve(long long n)
{
    vector<char> isp(n + 1, 1);
    vector<long long> p(1, 2);
    long long i, j, r = sqrt(n);
    // isp[0]=0;isp[1]=0;
    for (i = 4; i <= n; i += 2)
        isp[i] = 0;
    for (i = 3; i <= r; i += 2)
    {
        if (isp[i] == 1)
        {
            p.push_back(i);
            j = n / i;
            if (j % 2 == 0)
                j--;
            for (; j >= i; j -= 2)
                if (isp[j] == 1)
                    isp[i * j] = 0;
        }
    }
    if (++r % 2 == 0)
        r++;
    for (; r <= n; r += 2)
        if (isp[r] == 1)
            p.push_back(r);
    return p;
}

long long binpow(long long base, long long exp)
{
    long long ans = 1;
    while (exp)
    {
        if (exp & 1LL)
            ans *= base;
        base *= base;
        exp >>= 1;
    }
    return ans;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;

    cin >> n >> m;
    ll mm = m, xxx = 0;
    while (mm != 0)
    {
        mm >>= 1;
        xxx++;
    }
    if (n < xxx)
    {
        cout << -1 << '\n';
        return;
    }

    vll a(m);
    for (i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), cmp);

    vll b(n + 1, 0);
    b[1] = a[0];
    vll p = sieve(n);
    vll num(n+1,0);

    for (i = 2; i <= n; i++)
    {
        for(j=0;j<p.size();j++)
        {
            if(i%p[j]==0)
            {
                num[i]=num[i/p[j]]+1;
                break;
            }
        }

        if (num[i] >= m)
        {
            cout << -1 << '\n';
            return;
        }
        b[i] = a[num[i]];
    }

    for (i = 1; i <= n; i++)
    {
        cout << b[i] << ' ';
    }

    cout << '\n';
    return;
}

/*

*/