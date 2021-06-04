//
// Created by zhang on 2021/5/29.
//
#include "common-header.h"

class Solution {
public:
    // 前缀和的思想，思路是枚举矩阵的上下边界
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n);
            for (int j = i; j < m; ++j) {
                for (int c = 0; c < n; ++c) {
                    sum[c] += matrix[j][c];
                }
                set<int> sumSet{0};
                int s = 0;
                for (int v : sum) {
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()) {
                        ans = max(ans, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }
};
