//
// Created by zhang on 2021/6/9.
//
#include "common-header.h"
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for(auto &num : nums) {
            if (!numSet.count(num - 1)) {
                int curLong = 1;
                int next = num + 1;
                while (numSet.count(next)) {
                    curLong++;
                    next++;
                }
                longest = max(longest, curLong);
            }
        }
        return longest;
    }
};