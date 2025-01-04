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

ll sum = 0;

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
    // cin >> _;
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

struct NODE
{
    long long data;
    struct NODE *pre;
    struct NODE *next;
};

typedef struct NODE node;

void merge_sort(node *head)
{
    if (head->data <= 1)
        return;

    node *head0 = (node *)malloc(sizeof(node));
    head0->data = head->data / 2;
    head0->next = head->next;
    head0->pre = head0;

    node *head1 = (node *)malloc(sizeof(node));
    head1->data = head->data - head0->data;
    head1->pre = head->pre;
    head1->next = head1;

    int i, j;
    node *now = head;
    for (i = 0; i < head0->data; i++)
        now = now->next;

    now->next->pre = head1;
    head1->next = now->next;
    head1->pre->next = head1;

    now->next = head0;
    head0->pre = now;
    head0->next->pre = head0;

    merge_sort(head0);
    merge_sort(head1);

    now = head;
    while (head0->data != 0 && head1->data != 0)
    {
        if (head0->next->data <= head1->next->data)
        {
            now->next = head0->next;
            head0->next = head0->next->next;
            head0->next->pre = head0;
            head0->data--;
        }
        else
        {
            sum += head0->data;
            now->next = head1->next;
            head1->next = head1->next->next;
            head1->next->pre = head1;
            head1->data--;
        }
        now->next->pre = now;
        now->next->next = head;
        now = now->next;
    }

    if (head0->data == 0)
    {
        head->pre = head1->pre;
        now->next = head1->next;
    }
    else
    {
        head->pre = head0->pre;
        now->next = head0->next;
    }

    now->next->pre = now;
    head->pre->next = head;

    free(head0);
    free(head1);
    return;
}

void solve(void)
{
    ll i = 0, j = 0;
    ll n = 0, m = 0;

    scanf("%d", &n);
    node *head = (node *)malloc(sizeof(node));
    head->data = n;
    head->pre = head;
    head->next = head;
    node *tail;
    for (i = 0; i < n; i++)
    {
        tail = (node *)malloc(sizeof(node));
        tail->pre = head->pre;
        tail->next = head;
        tail->next->pre = tail;
        tail->pre->next = tail;
        scanf("%lld", &(tail->data));
    }

    merge_sort(head);

    cout << sum;
    cout << '\n';
    return;
}

/*

*/