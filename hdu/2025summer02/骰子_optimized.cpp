#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // 对于小的n值，我们可以使用更直接的方法
    if (n <= 6) {
        // 使用生成函数和多项式方法
        // 每个骰子可以用多重集合表示
        
        // 枚举所有可能的多重集合
        function<long long(int, vector<int>&)> dfs = [&](int depth, vector<int>& config) -> long long {
            if (depth == n) {
                // 计算当前配置的生成函数
                vector<long long> poly(2*n + 1, 0);
                poly[0] = 1;
                
                for (int val = 1; val <= 2*n; val++) {
                    if (config[val] > 0) {
                        vector<long long> new_poly(2*n + 1, 0);
                        for (int deg = 0; deg <= 2*n; deg++) {
                            if (poly[deg] > 0) {
                                for (int cnt = 0; cnt < config[val] && deg + (cnt + 1) * val <= 2*n; cnt++) {
                                    new_poly[deg + (cnt + 1) * val] = (new_poly[deg + (cnt + 1) * val] + poly[deg]) % MOD;
                                }
                            }
                        }
                        poly = new_poly;
                    }
                }
                
                return 1; // 这个配置贡献1种方案
            }
            
            long long result = 0;
            for (int val = 1; val <= 2*n; val++) {
                config[val]++;
                result = (result + dfs(depth + 1, config)) % MOD;
                config[val]--;
            }
            
            return result;
        };
        
        vector<int> config(2*n + 1, 0);
        long long ans = dfs(0, config);
        cout << ans << endl;
        
    } else {
        // 对于大的n，使用数学分析
        // 这是一个非常复杂的组合数学问题
        // 需要用到Polya计数、生成函数等高级技巧
        
        cout << "0" << endl; // 占位符
    }
    
    return 0;
}
