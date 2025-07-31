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
class tnode {
public:
  __Tp data;
  tnode<__Tp> *left,*right,*father;
  tnode() {
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

template<typename __Tp>
tnode<__Tp>* buildtree(__Tp* fbeg, __Tp* fend, __Tp* mbeg, __Tp* mend)
{
  if(fbeg == fend && mbeg == mend) return NULL;
  if(fbeg + 1 == fend && mbeg + 1 == mend)
  {
    tnode<__Tp>* leaf = new tnode<__Tp>;
    leaf -> data = *fbeg;
    return leaf;
  }
  __Tp* ii;
  for(ii = mbeg;ii != mend;ii ++)
  {
    if(*ii == *fbeg) break;
  }
  tnode<__Tp>* now = new tnode<__Tp>;
  now -> data = *fbeg;
  now -> left = buildtree<__Tp>(fbeg+1,(fbeg+1)+(ii-mbeg),mbeg,ii);
  now -> right = buildtree<__Tp>((fbeg+1)+(ii-mbeg),fend,ii+1,mend);
  if(now -> left != NULL) now -> left -> father = now;
  if(now -> right != NULL) now -> right -> father = now;
  return now;
}

template<typename __Tp>
void backread(tnode<__Tp>* root,tnode<__Tp>* troot)
{
  if(root==NULL) return;
  backread(root->left,troot);
  backread(root->right,troot);
  cout<<(root->data);
  if(root!=troot) cout<<' ';
}

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

void solve(i8 n)
{
    i8 i = 0, j = 0;
    i8 sum = 0;

    i8 A[n],B[n];
    for(i=0;i<n;i++) cin>>A[i];
    for(i=0;i<n;i++) cin>>B[i];
    tnode<i8> *root=buildtree<i8>(A,A+n,B,B+n);
    backread<i8>(root,root);
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
    // cin >> _;
    while (cin>>_)
        solve(_);
    return 0;
}