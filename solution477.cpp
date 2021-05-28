//
// Created by zhang on 2021/5/28.
//

#include "common-header.h"

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        const int n = 30;
        int mask = 1;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int count0 = 0, count1 = 0;
            for(int num : nums) {
                if (num & mask) count0++;
                else count1++;
            }
            count += count0 * count1 << 1;
            mask <<= 1;
        }
        return count;
    }
};

