//
// Created by zhang on 2021/5/21.
//
#include "common-header.h"
class Solution {
public:
    int maxUncrossedLines2(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size(), n = nums2.size();
        int dp[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < n; ++i) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int a = nums1[i - 1], b = nums2[j - 1];
                if (a == b) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
