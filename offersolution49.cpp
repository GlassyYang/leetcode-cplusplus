//
// Created by zhang on 2021/5/26.
//
#include "common-header.h"
class Solution {
public:
    // TODO
    int nthUglyNumber(const int n) {
        int dp[n];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        int p2n = 2, p3n = 3, p5n = 5;
        for (int i = 1; i < n; ++i) {
            dp[i] = min3(p2n, p3n, p5n);
            // 注意这儿
            if (dp[i] == p2n) {
                p2n = dp[++p2] * 2;
            }
            if (dp[i] == p3n) {
                p3n = dp[++p3] * 3;
            }
            if (dp[i] == p5n) {
                p5n = dp[++p5] * 5;
            }
        }
        return dp[n - 1];
    }
private:
    inline int &min3(int &x, int &y, int &z) {
        if (x < y) {
            if (z < x) return z;
            else return x;
        } else {
            if (z < y) return z;
            else return y;
        }
    }
};