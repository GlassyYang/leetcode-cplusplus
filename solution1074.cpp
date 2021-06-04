//
// Created by zhang on 2021/5/29.
//
#include "common-header.h"
class Solution {
public:
    // TODO 明天再做做
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        int buf[n];
        for (int i = 0; i < m; ++i) {
            buf[0] = 0;
            unordered_set<int> prefix{0};
            for (int j = i; j < m; ++j) {
                int pre = buf[0];
                buf[0] += matrix[j][i];
                for (int k = 1; k < n; ++k) {
                    int temp = buf[k];
                    buf[k] = buf[k] - pre + buf[k - 1] + matrix[j][k];
                    auto left = prefix.find(buf[k] - k);
                    if (left != prefix.end())ans++;
                    pre = temp;
                    prefix.insert(buf[k]);
                }
            }
        }
        return ans;
    }
};