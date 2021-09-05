//
// Created by zhang on 2021/9/5.
//
#include "common-header.h"
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            prefixSum[sum]++;
            if(sum == k) {
                count++;
            }
            auto last = prefixSum.find(k - sum);
            if(last != prefixSum.end()) {
                count += last->second;
            }
        }
        return count;
    }
};