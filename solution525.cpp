//
// Created by zhang on 2021/6/3.
//
#include "common-header.h"
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> prefix = {{0,0}};
        int sum = 0, max = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if (prefix.find(sum) != prefix.end()) {
                max = ::max(max, i - prefix[sum]);
            } else {
                prefix[sum] = i;
            }
        }
        return max;
    }
};