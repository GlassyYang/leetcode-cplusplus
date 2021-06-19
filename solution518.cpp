//
// Created by zhang on 2021/6/10.
//
#include "common-header.h"

class Solution {
public:
    int change(const int amount, vector<int> &coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (const auto &coin :coins) {
            for (int i = 1; i <= amount; ++i) {
                if (coin <= i) dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};