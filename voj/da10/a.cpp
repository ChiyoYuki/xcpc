/**
 *  author:  ChiyoYuki
 **/

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define elif else if

using i1 = signed char;
using i2 = signed short int;
using i4 = signed int;
using i8 = signed long long int;
using u1 = unsigned char;
using u2 = unsigned short int;
using u4 = unsigned int;
using u8 = unsigned long long int;
using f06 = float;
using f15 = double;

template<typename __Tp>
using vc=vector<__Tp>;
template<typename __Tp>
using dq=deque<__Tp>;
template<typename __Tp>
using pq=priority_queue<__Tp>;

template<typename __Tp0,typename __Tp1>
using pr=pair<__Tp0, __Tp1>;
template<typename __Tp0,typename __Tp1>
using mp=map<__Tp0,__Tp1>;
template<typename __Tp0,typename __Tp1>
using vp=vector<pair<__Tp0, __Tp1>>;


using vi = vector<i8>;
using di = deque<i8>;
using pqi = priority_queue<i8>;
using pii = pair<i8, i8>;
using mii = map<i8, i8>;
using vvi = vector<vector<i8>>;
using vpii = vector<pair<i8, i8>>;
using str = string;

const i2 i2inf = 0x3f3f;
const i2 i2max = INT16_MAX;
const i2 i2min = INT16_MIN;
const u2 u2max = UINT16_MAX;
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
void YORN(bool f);
void Yorn(bool f);
void yorn(bool f);

template<typename __Tp>
class tnode {
public:
  __Tp data;
  i8 ldp,rdp;
  tnode<__Tp> *left,*right,*father;
  tnode() {
    ldp=0;
    rdp=0;
    this->left=NULL;
    this->right=NULL;
    this->father=NULL;
  }
  ~tnode()
  {
    if(this->left!=NULL) delete this->left;
    if(this->right!=NULL) delete this->right;
  }
};

using tni=tnode<i8>;

void rotate(tni* now,char child,char pos)
{
  tni* nr;
  if(child=='l')
  {
    nr=now->left;
    if(now->father!=NULL)
    {
      if(pos=='l') now->father->left=nr;
      else now->father->right=nr;
    }
    nr->father=now->father;
    now->father=nr;
    now->left=nr->right;
    nr->right=now;
    if(now->left!=NULL) now->left->father=now;
    if(now->left==NULL) now->ldp=0;
    else now->ldp=max(now->left->ldp,now->left->rdp)+1;
    nr->rdp=max(now->ldp,now->rdp)+1;
  }
  else
  {
    nr=now->right;
    if(now->father!=NULL)
    {
      if(pos=='l') now->father->left=nr;
      else now->father->right=nr;
    }
    nr->father=now->father;
    now->father=nr;
    now->right=nr->left;
    nr->left=now;
    if(now->right!=NULL) now->right->father=now;
    if(now->right==NULL) now->rdp=0;
    else now->rdp=max(now->left->ldp,now->left->rdp)+1;
    nr->ldp=max(now->ldp,now->rdp)+1;
  }
}

void solve(void)
{
    i8 i = 0, j = 0;
    i8 n = 0, m = 0;
    i8 sum = 0;
    cin>>n;
    tni* root=NULL;
    for(i=0;i<n;i++)
    {
      tni* now=new tni;
      cin>>now->data;
      if(root==NULL) 
      {
        root=now;
        continue;
      }
      tni* fa=root;
      while(1)
      {
        if(fa->data<now->data)
        {
          if(fa->right==NULL)
          {
            fa->right=now;
            now->father=fa;
            break;
          }
          else fa=fa->right;
        }
        else
        {
          if(fa->left==NULL)
          {
            fa->left=now;
            now->father=fa;
            break;
          }
          else fa=fa->left;
        }
      }
      for(;now!=NULL;now=now->father)
      {
        if(now->left!=NULL) now->ldp=1+max(now->left->ldp,now->left->rdp);
        if(now->right!=NULL) now->rdp=1+max(now->right->ldp,now->right->rdp);
        if(abs(now->ldp-now->rdp)>1) break;
      }
      if(now==NULL) continue;
      tni* nr;
      if(now->ldp>now->rdp)
      {
        if(now->left->ldp>=now->left->rdp)
        {
          rotate(now,'l','l');
        }
        else
        {
          rotate(now->left,'r','l');
          rotate(now,'l','l');
        }
      }
      else
      {
        if(now->right->ldp<=now->right->rdp)
        {
          rotate(now,'r','r');
        }
        else
        {
          rotate(now->right,'l','r');
          rotate(now,'r','r');
        }
      }
      if(now==root) root=now->father;
      for(;now!=NULL;now=now->father)
      {
        if(now->left!=NULL) now->ldp=1+max(now->left->ldp,now->left->rdp);
        if(now->right!=NULL) now->rdp=1+max(now->right->ldp,now->right->rdp);
      }
    }
    cout<<root->data;
    // cin>>n;
    // vi a(n);
    // for(i=0;i<n;i++) cin>>a[i];

    cout << '\n';
    return;
}

/*

*/

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
// #endif

    unsigned long long _ = 1;
    while (_--)
        solve();
    return 0;
}

void YORN(bool f) {cout << (f ? "YES\n" : "NO\n");}
void Yorn(bool f) {cout << (f ? "Yes\n" : "No\n");}
void yorn(bool f) {cout << (f ? "yes\n" : "no\n");}
