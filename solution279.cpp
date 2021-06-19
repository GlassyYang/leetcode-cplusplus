//
// Created by zhang on 2021/6/11.
//
#include "common-header.h"
class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 1; i <= n; ++i) {
            int min = 5;
            int sq = sqrt(i);
            dp[i] = 0;
            for (int j = 0; j <= sq; ++j) {
                min = ::min(min, dp[i - j * j] + 1);
            }
            dp[i] = min;
        }
        return dp[n];
    }
};