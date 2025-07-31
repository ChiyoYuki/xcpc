/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define elif else if

typedef signed char i1;
typedef signed short int i2;
typedef signed int i4;
typedef signed long long int i8;
typedef unsigned char u1;
typedef unsigned short int u2;
typedef unsigned int u4;
typedef unsigned long long int u8;
typedef float f06;
typedef double f15;

typedef vector<i8> vi;
typedef deque<i8> di;
typedef deque<i8> di;
typedef priority_queue<i8> pqi;
typedef pair<i8, i8> pii;
typedef map<i8, i8> mii;
typedef vector<vector<i8>> vvi;
typedef vector<pair<i8, i8>> vpii;
typedef string str;

const i4 i4inf = 0x3f3f3f3f;
const i4 i4max = INT32_MAX;
const i4 i4min = INT32_MIN;
const u4 u4max = UINT32_MAX;
const i8 i8inf = 0x3f3f3f3f3f3f3f3f;
const i8 i8max = INT64_MAX;
const i8 i8min = INT64_MIN;
const u8 u8max = UINT64_MAX;
const int mod9 = 998244353;
const int moda = 1000000007;

void solve(void);

vi ppp;

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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    unsigned long long _ = 1;
    cin >> _;
    ppp = sieve(200000);
    while (_--)
        solve();
    return 0;
}

void solve(void)
{
    i8 i = 0, j = 0, k = 0;
    i8 n = 0, m = 0;
    i8 sum = 0;
    i8 ans = 0;

    cin >> n;
    vi a(n);

    mii one, two, time;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];

        i8 pos = upper_bound(ppp.begin(), ppp.end(), a[i]) - ppp.begin();
        pos--;
        if (ppp[pos] == a[i])
        {
            one[a[i]]++;
            sum++;
            time[a[i]]++;
        }
        else
        {
            for (j = 0; j <= pos; j++)
                if (a[i] % ppp[j] == 0)
                    break;
            i8 rem = ppp[j];
            a[i] /= ppp[j];
            i8 npos = lower_bound(ppp.begin(), ppp.begin() + pos + 1, a[i]) - ppp.begin();
            if (ppp[npos] == a[i])
            {
                two[a[i] * rem]++;
                if (a[i] != rem)
                    time[rem]++;
                time[a[i]]++;
            }
            else
                continue;
        }

        //     for (j = 0; j < ppp.size(); j++)
        //     {
        //         if (a[i] == ppp[j])
        //         {
        //             if (rem == 1)
        //             {
        //                 one[a[i]]++;
        //                 sum++;
        //             }
        //             else
        //             {
        //                 two[a[i] * rem]++;
        //                 if (a[i] != rem)
        //                     time[rem]++;
        //             }
        //             time[a[i]]++;
        //             break;
        //         }
        //         else if (a[i] % ppp[j] == 0)
        //         {
        //             if (rem == 1)
        //             {
        //                 rem = ppp[j];
        //                 a[i] /= ppp[j];
        //                 j--;
        //             }
        //             else
        //                 break;
        //         }
        //         else if (a[i] < ppp[j])
        //             break;
        //     }
    }

    for (auto ii = one.begin(); ii != one.end(); ii++)
    {
        ans += ii->second * (sum - (ii->second));
    }
    ans /= 2;
    for (auto ii = one.begin(); ii != one.end(); ii++)
    {
        ans += ii->second * (time[ii->first] - (ii->second));
    }
    for (auto ii = two.begin(); ii != two.end(); ii++)
    {
        ans += ii->second * (ii->second - 1) / 2;
        ans += ii->second;
    }
    cout << ans;

    cout << '\n';
    return;
}

/*

*/