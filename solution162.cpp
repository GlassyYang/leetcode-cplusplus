//
// Created by zhang on 2021/6/8.
//
#include "common-header.h"
class Solution {
public:
    int findPeakElement(const vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > nums[i - 1]&& nums[i] > nums[i + 1]) return i;
        }
        return nums[n - 2] > nums[n - 1] ? n - 2 : n - 1;
    }
};