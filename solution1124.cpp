//
// Created by zhang on 2021/5/20.
//
#include "common-header.h"

class Solution {
public:
    // 滑动窗口做不了,就暴力一下子
    int longestWPI(vector<int>& hours) {
        const int n = hours.size();
        int a[n];
        for (int i = 0; i < n; ++i) {
            a[i] = hours[i] > 8 ? 1 : -1;
        }
        int sum, max = 0;
        for (int i = 0; i < n; ++i) {
            sum = 0;
            for (int j = i; j < n; ++j) {
                sum += a[j];
                if (sum > 0 && j - i + 1 > max) max = j - i + 1;
            }
        }
        return max;
    }
};

int main(int argc, char **argv) {
    vector<int> hours = {9,9,6,9,6,6,9,9,6};
    Solution solution;
    cout << solution.longestWPI(hours);
    return 0;
}