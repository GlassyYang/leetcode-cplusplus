//
// Created by zhang on 2021/6/18.
//

#include "common-header.h"

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int mod = 1000000007;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        long powOf2[n];
        powOf2[0] = 1;
        for (int i = 0; i < n; ++i) {
            powOf2[i] = (powOf2[i - 1] * 2) % mod;
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (powOf2[i] - powOf2[n - i - 1]) * nums[i]) % mod;
        }
        return ans;
    }
};