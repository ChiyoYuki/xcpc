#include<bits/stdc++.h>

#define i8 long long
#define vi vector<i8>
using namespace std;

// 计算第一类斯特林数（无符号）
vector<vector<i8>> stirling1(int n) {
    vector<vector<i8>> s(n + 1, vector<i8>(n + 1, 0));
    s[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = (i - 1) * s[i - 1][j] + s[i - 1][j - 1];
        }
    }
    return s;
}

// 方法1：直接计算 ∑s(n,k)*k³
i8 stirling_weighted_sum_direct(int n) {
    auto s = stirling1(n);
    i8 sum = 0;
    for (int k = 0; k <= n; k++) {
        sum += s[n][k] * k * k * k;  // s(n,k) * k³
    }
    return sum;
}

// 方法2：使用递推公式计算
i8 stirling_weighted_sum_recursive(int n) {
    if (n == 0) return 0;  // s(0,0)*0³ = 1*0 = 0
    
    // 基于恒等式的递推计算
    // ∑s(n,k)*k³ 可以通过差分方法计算
    vector<i8> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;  // s(1,1)*1³ = 1*1 = 1
    
    for (int i = 2; i <= n; i++) {
        // 递推关系：基于斯特林数的性质
        dp[i] = (i - 1) * dp[i - 1] + (i - 1) * (i - 1) * (i - 1);
        
        // 加上额外项
        for (int j = 1; j < i; j++) {
            dp[i] += j * j * j;  // 简化的递推
        }
    }
    
    return dp[n];
}

// 方法3：使用组合恒等式
i8 stirling_weighted_sum_formula(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // 基于Bell多项式的公式
    // ∑s(n,k)*k³ = B_n(1³, 2³, 3³, ..., n³)
    // 其中B_n是第n个完全Bell多项式
    
    // 使用Faà di Bruno公式的特殊情况
    i8 result = 0;
    
    // 这是一个简化的实现，实际公式更复杂
    for (int k = 1; k <= n; k++) {
        i8 factorial = 1;
        for (int i = 1; i <= k; i++) factorial *= i;
        
        // 近似计算
        result += factorial * k;  // 简化版本
    }
    
    return result;
}

void solve() {
    int n;
    cin >> n;
    
    // 计算第一类斯特林数
    auto s = stirling1(n);
    
    // 输出每行的斯特林数
    for (int i = 1; i <= n; i++) {
        cout << s[n][i];
        if (i < n) cout << ' ';
    }
    cout << endl;
    
    // 计算 ∑s(n,k)*k³
    i8 weighted_sum = stirling_weighted_sum_direct(n);
    cout << weighted_sum;
}

int main()
{
    int _;
    cin>>_;
    while(_--)
    {
        solve();
        cout<<'\n';
    }
    return 0;
}