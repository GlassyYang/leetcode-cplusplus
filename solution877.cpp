//
// Created by zhang on 2021/6/16.
//
#include "common-header.h"
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        vector<int> dp(piles);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(piles[i] - dp[j], piles[j]- dp[j - 1]);
            }
        }
        return dp[n - 1] > 0;
    }
};