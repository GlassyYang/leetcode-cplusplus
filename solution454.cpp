//
// Created by zhang on 2021/6/15.
//

#include "common-header.h"
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        const int n = nums1.size();
        unordered_map<int, int> group;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                group[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int twoSum = nums3[i] + nums4[j];
                if (group.count(-twoSum)) {
                    ans += group[-twoSum];
                }
            }
        }
        return ans;
    }
};