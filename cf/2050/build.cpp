#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("test.in","w",stdout);
    srand(time(NULL));
    int i, j;
    cout << 10 << '\n';
    for (i = 0; i < 10; i++)
    {
        cout << 16 + i % 2 << '\n';
        for (j = 0; j < 16 + i % 2; j++)
        {
            cout << rand() % 5 + 1 << ' ';
        }
        cout<<'\n';
    }
}