//
// Created by zhang on 2021/6/8.
//

#include "common-header.h"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int m = stones.size();
        const int sum = accumulate(stones.begin(), stones.end(), 0), n = (sum >> 1) + 1;
        bool dp[m + 1][n];
        fill(dp[0], dp[0] + n, false);
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            int &weight = stones[i - 1];
            for (int j = 0; j < n; ++j) {
                if (j < weight) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - weight];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (dp[m][i]) return sum - (i << 1);
        }
        return 0;
    }
};

