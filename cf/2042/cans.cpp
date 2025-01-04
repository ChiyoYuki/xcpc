#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 5, 0);
        vector<int> suf(n + 5, 0);
        string s;
        cin >> s;
        int n1 = 0, n0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                a[i + 1] = -1;
            else
                a[i + 1] = 1;
        }
        for (int i = n; i >= 1; i--)
            suf[i] = suf[i + 1] + a[i];
        int h = 0;
        int m = 1;
        priority_queue<int> q;
        for (int i = 2; i <= n; i++)
        {
            if (suf[i] > 0)
                q.push(suf[i]);
        }
        while (!q.empty())
        {
            if (h >= k)
                break;
            h += q.top();
            m += 1;
            q.pop();
        }
        if (h < k)
            cout << -1 << '\n';
        else
            cout << m << '\n';
    }
    return 0;
}
