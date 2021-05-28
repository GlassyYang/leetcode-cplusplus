//
// Created by zhang on 2021/5/28.
//

/*
 * 买卖股票的最佳时机：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
 */
#include "common-header.h"
class Solution {
public:
    int maxProfitNormal(vector<int>& prices) {
        const int n = prices.size();
        int dp[n][4];
        dp[0][0] = dp[0][2] = -prices[0];
        dp[0][1] = dp[0][3] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i][2] + prices[i]);
        }
        return dp[n - 1][3];
    }
    int maxProfit(vector<int> &prices) {
        const int n = prices.size();
        int buy1 = -prices[0], buy2 = buy1;
        int sell1 = 0, sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(sell1, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};

