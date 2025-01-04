#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    cout << 16 << '\n';
    int i;
    for (i = 0; i < 16; i++)
    {
        int l = 0, r = 0;
        while (l == r)
        {
            l = rand() % 7;
            r = rand() % 7;
        }
        if (l > r)
            swap(l, r);
        cout << l << ' ' << r << ' ' << rand() % 1024 + 1 << '\n';
    }
}