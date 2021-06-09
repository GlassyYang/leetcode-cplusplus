//
// Created by zhang on 2021/6/9.
//
#include "common-header.h"
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int m = group.size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            const int &workers = group[i - 1], &prof = profit[i - 1];
            for (int j = 0; j <= n; ++j) {
                if (j >= workers) {
                    for (int k = 0; k <= minProfit; ++k) {
                        dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - workers][max(0, k - prof)]) % MOD;
                    }
                } else {
                    for (int k = 0; k <= minProfit; ++k) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= n; ++i) {
            sum = (sum + dp[m][i][minProfit]) % MOD;
        }
        return sum;
    }

private:
    const int MOD = 1000000007;
};

namespace optimize {
    class Solution {
    public:
        int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
            const int m = group.size();
            vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
            dp[0][0] = 1;
            for (int i = 1; i <= m; ++i) {
                const int &workers = group[i - 1], &prof = profit[i - 1];
                for (int j = n; j >= 0; --j) {
                    if (j >= workers) {
                        for (int k = minProfit; k >= 0; --k) {
                            dp[j][k] = (dp[j][k] + dp[j - workers][max(0, k - prof)]) % MOD;
                        }
                    }
                }
            }
            int sum = 0;
            for (int i = 0; i <= n; ++i) {
                sum = (sum + dp[i][minProfit]) % MOD;
            }
            return sum;
        }

    private:
        const int MOD = 1000000007;
    };
}