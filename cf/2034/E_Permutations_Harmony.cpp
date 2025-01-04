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

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;
    ll sum = 0;

    // cin>>n;
    // vll a(n);
    // for(i=0;i<n;i++) cin>>a[i];
    ll k;
    cin >> n >> k;
    if (n == 1)
    {
        if (k == 1)
            cout << "YES\n"
                 << 1 << '\n';
        else
            cout << "NO" << '\n';
        return;
    }

    sum = 1;
    for (i = n; i > 0; i--)
    {
        sum *= i;
        if (sum >= k)
            break;
    }

    if ((k % 2 == 1 && n % 2 == 0) || sum < k || k == 1)
    {
        cout << "NO" << '\n';
        return;
    }

    vvll ans;
    vll now(n);
    map<vll, bool> vis;
    for (i = 0; i < n; i++)
        now[i] = i + 1;
    if (k % 2 == 0)
    {
        for (i = 0; i < (k / 2); i++)
        {
            ans.push_back(now);
            next_permutation(now.begin(), now.end());
        }
        for (i = 0; i < n; i++)
            now[i] = n - i;
        for (i = 0; i < (k / 2); i++)
        {
            ans.push_back(now);
            prev_permutation(now.begin(), now.end());
        }
    }
    else
    {
        ans.push_back(now);
        ans.push_back(now);
        for (i = 0; i < n; i++)
        {
            ans.back()[i] += (n / 2);
            ans.back()[i] %= n;
            if (ans.back()[i] == 0)
                ans.back()[i] = n;
        }
        ans.push_back(vll(n, 2 + n + n / 2));
        for (i = 0; i < n; i++)
        {
            ans.back()[i] -= (ans[0][i] + ans[1][i]);
        }
        vis[ans[0]] = true;
        vis[ans[1]] = true;
        vis[ans[2]] = true;

        for (i = 0; i < n; i++)
            now[i] = i + 1;
        vll nnoo = now;
        vll last(n);
        for(i=0;i<n;i++)
        last[i]=n-i;
        while (ans.size()<k)
        {
            next_permutation(now.begin(), now.end());
            nnoo = now;
            for (i = 0; i < n; i++)
                nnoo[i] = 1 + n - nnoo[i];
            if (vis[nnoo] == false && vis[now] == false)
            {
                ans.push_back(now);
                vis[now]=true;
                ans.push_back(nnoo);
                vis[nnoo]=true;
            }
            if(last==nnoo)
            {
                cout<<"NO"<<'\n';
                return;
            }
        }
    }

    cout << "YES\n";
    for (i = 0; i < ans.size(); i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return;
}

/*
1234567
4567123
7531642
 */

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
