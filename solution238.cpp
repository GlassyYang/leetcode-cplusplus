//
// Created by zhang on 2021/9/2.
//
#include "common-header.h"
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        int prefix[n + 1], suffix[n + 1];
        prefix[0] = suffix[n] = 1;
        for(int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] * nums[i];
            suffix[n - i - 1] = suffix[n - i] * nums[n - i - 1];
        }
        vector<int> ans;
        for(int i = 1; i <= n; ++i) {
            ans.push_back(prefix[i - 1] * suffix[i]);
        }
        return ans;
    }
};