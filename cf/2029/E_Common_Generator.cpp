/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll int
#define ull unsigned long long
#define lf double
#define vc vector<char>
#define vll vector<int>
#define vvll vector<vector<int>>

using namespace std;

void solve(void);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

vector<int> sieve(int num)
{
    vector<char> is_prime(num + 1, 1);
    vector<int> prime(1, 2); // 手动填入2
    int i, j, root = sqrt(num);
    is_prime[0] = 0;
    is_prime[1] = 0;

    for (i = 4; i <= num; i += 2) // 手动除掉大于2的偶数
        is_prime[i] = 0;

    for (i = 3; i <= root; i += 2) // 筛掉含有<=sqrt(num)因子的合数
    {
        if (is_prime[i] == 1)
        {
            prime.push_back(i);
            j = num / i;
            if (j % 2 == 0) // 因为2的倍数已被筛掉，故枚举因子时不考虑偶数
                j--;
            for (; j >= i; j -= 2) // 从大向小枚举因子，避免筛掉4后筛不掉8这种情况
                if (is_prime[j] == 1)
                    is_prime[i * j] = 0;
        }
    }

    if (++root % 2 == 0)
        root++;
    for (; root <= num; root += 2) // 枚举大于sqrt(num)的奇数
        if (is_prime[root] == 1)
            prime.push_back(root); // 将大于sqrt(num)的素数填入vector
    return prime;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n, m, sum = 0, ans = 0;
    cin >> n;
    vll a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bool flag = true;
    sort(a.begin(), a.end());
    vector<int> p = sieve(max(a.front(),(int)sqrt(a.back())));

    for (i = 0; i < p.size(); i++)
    {
        if (p[i] == a[0])
        {
            ans = a[0];
            break;
        }
        if (p[i] > a[0])
        {
            break;
        }
    }
    bool dou=false;
    if(ans==0) ans=2;
    for(j=1;j<a.size()&&flag;j++)
    {
        if(a[j]%2)
        {
            for(i=0;i<p.size();i++)
            {
                if(a[j]%p[i]==0)
                {
                    if(a[j]-p[i]<ans*2)
                    {
                        flag=false;
                    }
                    break;
                }
                if(p[i]>sqrt(a[j]))
                {
                    flag=false;
                    break;
                }
            }
            if(i==p.size()) flag=false;
        }
        else if(!dou)
        {
            if(a[j]<ans*2)
            {
                flag=false;
                break;
            }
            dou=true;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
        return;
    }
    else if(ans==0) ans=2;
    cout<<ans;
    cout << endl;
    return;
}

/*

*/