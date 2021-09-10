//
// Created by zhang on 2021/9/6.
//
#include "common-header.h"
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int indexA = 0, indexB = 0, indexC = 0;
        int nextA = a, nextB = b, nextC = c;
        int dp[n + 1];
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            dp[i] = min(nextA, nextB);
            dp[i] = min(dp[i], nextC);
            if(dp[i] == nextA) {
                nextA = dp[++indexA] * a;
            }
            if(dp[i] == nextB) {
                nextB = dp[++indexB] * b;
            }
            if(dp[i] == nextC) {
                nextC = dp[++indexC] * c;
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    cout <<solution.nthUglyNumber(1000000000, 2, 217983653, 336916467) << endl;
}