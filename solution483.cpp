//
// Created by zhang on 2021/6/18.
//
#include "common-header.h"
class Solution {
public:
    string smallestGoodBase(string n) {
        long nl = stol(n);
        int mMax = floor(log(nl) / log(2));
        for (int m = mMax; m > 1; --m) {
            int k = pow(nl, 1.0 / m);
            long sum = 0, base = 1;
            for (int i = 0; i < m; ++i) {
                sum += base;
                base *= k;
            }
            if (sum == nl) return to_string(sum);
        }
        return to_string(nl - 1);
    }
};