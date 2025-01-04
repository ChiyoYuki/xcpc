#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define int long long
#define itn int
#define endl '\n'
#define Endl endl
#define ednl endl
#define al(a) (a).begin(), (a).end()
#define all(a) (a).begin() + 1, (a).end()
#define debug(x)                    \
    {                               \
        cerr << "ss:" << x << endl; \
    }
#define qdebug(x)             \
    {                         \
        cerr << "ss:";        \
        for (auto i : x)      \
            cout << i << " "; \
        cout << endl;         \
    }
#define lowbit(x) (x & -x)
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second

constexpr long long maxlonglong = 9223372036854775807; // 9e18
constexpr int maxint = 2147483647;                     // 2e9
constexpr int INF = 0x7f7f7f7f7f7f7f7f;                // 2139062143^2
// constexpr int mod = 1e9 + 7;
constexpr int mod = 998244353;
constexpr int hs = 0x1F351F35; // good hash number.
const double pi = acos(-1.0);
const double eps = 1e-15;
vector<int> input(int n)
{
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    return a;
}
mt19937_64 rnd(time(0));

constexpr int N = 1231564;

inline void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << "YES" << Endl;
        for (int i = 1; i <= m; i++)
        {
            cout << 1 << Endl;
        }
        return;
    }
    if (m == 1 || n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (m % 2 == 0)
    {
        int flag = 1;
        int t = 1;
        for (int i = 1; i <= n; i++)
        {
            t *= i;
            if (t >= m)
                flag = 0;
        }
        if (flag)
        {
            cout << "NO" << ednl;
            return;
        }
        cout << "YES" << ednl;
        vi a(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = i;
        for (int i = 2; i <= m; i += 2)
        {
            for (int j = 1; j <= n; j++)
                cout << a[j] << " ";
            cout << Endl;
            for (int j = 1; j <= n; j++)
                cout << n + 1 - a[j] << " ";
            cout << Endl;
            next_permutation(all(a));
        }
        return;
    }
    if (n % 2 == 0)
    {
        cout << "NO" << ednl;
        return;
    }
    int flag = 1;
    int t = 1;
    for (int i = 1; i <= n; i++)
    {
        t *= i;
        if (t - 3 >= m)
            flag = 0;
    }
    if (flag)
    {
        cout << "NO" << ednl;
        return;
    }
    cout << "YES" << ednl;
    int k = (n + 1) * 3 / 2;
    vi ans(n + 1);
    vector<vi> a;
    int j = 1;
    map<vi, int> mp;
    for (int i = 1; i <= n; i++)
        ans[i] = i;
    a.push_back(ans);
    mp[ans]++;
    for (int i = n / 2 + 1; i <= n; i++)
        ans[j++] = i;
    for (int i = 1; j <= n; i++)
        ans[j++] = i;
    a.push_back(ans);
    mp[ans]++;
    for (int i = 1; i <= n; i++)
        ans[i] = k - i - ans[i];
    a.push_back(ans);
    mp[ans]++;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
            ans[i] = n + 1 - a[i][j];
        mp[ans]++;
    }
    vi x = a[0], y(n + 1);
    while (a.size() != m)
    {
        for (int i = 1; i <= n; i++)
            y[i] = n + 1 - x[i];
        if (mp.count(x) == 0 && mp.count(y) == 0)
        {
            a.push_back(x);
            a.push_back(y);
        }
        next_permutation(all(x));
    }
    for (auto t : a)
    {
        for (int i = 1; i <= n; i++)
            cout << t[i] << " ";
        cout << Endl;
    }
}

signed main()
{
    // freopen("E:\\work_tool\\document\\data\\input.in", "r", stdin);
    // freopen("E:\\work_tool\\document\\data\\output.out", "w", stdout);
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); // 关闭同步  如果使用 则不要使用<cstdio>
    // cout << fixed << setprecision(10);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
