#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// 计算两个多项式的乘积
vector<long long> multiply(const vector<long long>& a, const vector<long long>& b, int maxDeg) {
    vector<long long> result(maxDeg + 1, 0);
    for (int i = 0; i < a.size() && i <= maxDeg; i++) {
        for (int j = 0; j < b.size() && i + j <= maxDeg; j++) {
            result[i + j] = (result[i + j] + a[i] * b[j]) % MOD;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // 标准骰子的点数和分布
    vector<long long> target(2*n + 1, 0);
    for (int sum = 2; sum <= 2*n; sum++) {
        if (sum <= n + 1) {
            target[sum] = sum - 1;
        } else {
            target[sum] = 2*n + 1 - sum;
        }
    }
    
    // 使用动态规划计算所有可能的骰子配置
    // dp[mask] = 当前多重集合配置的方案数
    map<vector<int>, long long> dice_configs;
    
    // 枚举所有可能的n元多重集合
    function<void(int, vector<int>&, int)> generate = [&](int pos, vector<int>& config, int remaining) {
        if (remaining == 0) {
            // 计算这个配置对应的生成函数系数
            vector<long long> poly(2*n + 1, 0);
            poly[0] = 1;
            
            for (int val = 1; val <= 2*n; val++) {
                if (config[val] > 0) {
                    vector<long long> factor(2*n + 1, 0);
                    factor[0] = 1;
                    
                    // (1 + x^val + x^{2*val} + ... )^{config[val]}
                    // 实际上是 (1 + x^val)^{config[val]} 在这个问题中
                    for (int cnt = 0; cnt < config[val]; cnt++) {
                        vector<long long> new_factor(2*n + 1, 0);
                        for (int deg = 0; deg <= 2*n; deg++) {
                            new_factor[deg] = factor[deg];
                            if (deg + val <= 2*n) {
                                new_factor[deg + val] = (new_factor[deg + val] + factor[deg]) % MOD;
                            }
                        }
                        factor = new_factor;
                    }
                    
                    poly = multiply(poly, factor, 2*n);
                }
            }
            
            dice_configs[poly]++;
            return;
        }
        
        if (pos > 2*n) return;
        
        // 不选择当前值
        generate(pos + 1, config, remaining);
        
        // 选择当前值（最多remaining次）
        for (int cnt = 1; cnt <= remaining; cnt++) {
            config[pos] = cnt;
            generate(pos + 1, config, remaining - cnt);
            config[pos] = 0;
        }
    };
    
    vector<int> config(2*n + 1, 0);
    generate(1, config, n);
    
    // 计算答案
    long long result = 0;
    for (auto& [poly1, cnt1] : dice_configs) {
        for (auto& [poly2, cnt2] : dice_configs) {
            // 计算两个多项式的乘积
            vector<long long> conv = multiply(poly1, poly2, 2*n);
            
            // 检查是否匹配目标分布
            bool match = true;
            for (int k = 2; k <= 2*n; k++) {
                if (conv[k] != target[k]) {
                    match = false;
                    break;
                }
            }
            
            if (match) {
                result = (result + (1LL * cnt1 * cnt2) % MOD) % MOD;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}
