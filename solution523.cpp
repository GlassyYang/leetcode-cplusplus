//
// Created by zhang on 2021/6/2.
//
#include "common-header.h"
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map{make_pair(0, -1)};
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int mod = sum % k;
            if (map.find(mod) == map.end()) {
                map.insert(make_pair(mod, i));
            } else {
                int &index = map[mod];
                if (i - index >= 2) return true;
            }
        }
        return false;
    }
};

