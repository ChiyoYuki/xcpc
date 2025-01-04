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
    cin >> n >> m;
    vector<string> s(n);
    queue<pll2> bfs;
    ll vis = 0;
    for (i = 0; i < n; i++)
        cin >> s[i];
    for (i = 0; i < n; i++)
    {
        if (s[i][0] == 'L')
        {
            sum++;
            s[i][0] = 'X';
            bfs.push(make_pair(i, 0));
        }
        if (s[i][m - 1] == 'R')
        {
            sum++;
            s[i][m - 1] = 'X';
            bfs.push(make_pair(i, m - 1));
        }
    }
    for (i = 0; i < m; i++)
    {
        if (s[0][i] == 'U')
        {
            sum++;
            s[0][i] = 'X';
            bfs.push(make_pair(0, i));
        }
        if (s[n - 1][i] == 'D')
        {
            sum++;
            s[n - 1][i] = 'X';
            bfs.push(make_pair(n - 1, i));
        }
    }
    ll x, y;
    while (!(bfs.empty()))
    {
        x = bfs.front().first;
        y = bfs.front().second;
        if (x > 0 && s[x - 1][y] == 'D')
        {
            sum++;
            bfs.push(make_pair(x - 1, y));
            s[x - 1][y] = 'X';
        }
        if (x < n - 1 && s[x + 1][y] == 'U')
        {
            sum++;
            bfs.push(make_pair(x + 1, y));
            s[x + 1][y] = 'X';
        }
        if (y > 0 && s[x][y - 1] == 'R')
        {
            sum++;
            bfs.push(make_pair(x, y - 1));
            s[x][y - 1] = 'X';
        }
        if (y < m - 1 && s[x][y + 1] == 'L')
        {
            sum++;
            bfs.push(make_pair(x, y + 1));
            s[x][y + 1] = 'X';
        }
        bfs.pop();
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (s[i][j] == '?')
                if ((i > 0 && s[i - 1][j] == 'X') || i == 0)
                    if ((i < n - 1 && s[i + 1][j] == 'X') || i == n - 1)
                        if ((j > 0 && s[i][j - 1] == 'X') || j == 0)
                            if ((j < m - 1 && s[i][j + 1] == 'X') || j == m - 1)
                                sum++;
    cout << n * m - sum;
    cout << '\n';
    return;
}

/*

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
