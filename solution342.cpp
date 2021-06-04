//
// Created by zhang on 2021/6/1.
//
#include "common-header.h"
class Solution {
public:
    // 第一种方法，打卡
    bool isPowerOfFourForce(int n) {
        unordered_set<int> ans = {1, 1 << 2, 1 << 4, 1 << 6, 1 << 8, 1 << 10,
                                  1 << 12, 1 << 14, 1 << 16, 1 << 18, 1 << 20,
                                  1 << 22, 1 << 24, 1 << 26, 1 << 28, 1 << 30};
        return ans.find(n) != ans.end();
    }
    // 第二种方法，官方题解
    bool isPowerOfFour(int n) {
        int mask = 0xAAAAAAAA;
        return (n & (n - 1)) == 0 && (n & mask) == 0;
    }
    // 或者：
    bool isPowerOfFour(int n, int type = 2) {
        int mask = 0x55555555;
        return (n & mask) != 0 && (n & (n - 1)) == 0;
    }
};