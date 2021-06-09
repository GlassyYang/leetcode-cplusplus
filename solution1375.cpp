//
// Created by zhang on 2021/6/7.
//
#include "common-header.h"
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        // 记录最后一个开着的等的序号，如果和当前的时刻相等那么就变蓝色了。
        const int n = light.size();
        int count = 0;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            last = max(last, light[i]);
            if (last == i) count++;
        }
        return count;
    }
};
