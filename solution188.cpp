//
// Created by zhang on 2021/5/28.
//
#include "common-header.h"
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();
        const int status = k << 1;
        int dp[status];
        dp[0] = -prices[0];
        dp[1] = 0;
        for (int i = 0; i < status; ++i) {
            dp[i] = INT_MAX >> 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (j & 1) {
                    dp[j] = max(dp[j], dp[j-1] + prices[i]);
                } else {
                    int temp = j == 0 ? 0 : dp[j - 1];
                    dp[j] = max(dp[j], temp - prices[i]);
                }
            }
        }
        return dp[status - 1];
    }
};
