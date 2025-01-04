#include <bits/stdc++.h>

using namespace std;
bool checkUnlock(int x)
{
    string s = to_string(x);

    while (x > 0)
    {
        auto pos = s.find("33");
        if (pos != string::npos)
        {
            s.erase(pos, 2);
            if (s.length() == 0)
            {
                x = 0;
            }
            else
                x = stoi(s);
            continue;
        }
        if (x >= 33)
        {
            x = x - 33;
            s = to_string(x);
            continue;
        }
        break;
    }
    return x == 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int x;
        cin >> x;
        string ans = "NO";
        if (x % 33 == 0)
        {
            ans = "YES";
        }
        else
        {
            bool flag = checkUnlock(x);
            if (flag)
                ans = flag ? "YES" : "NO";
        }
        cout << ans << endl;
    }
}