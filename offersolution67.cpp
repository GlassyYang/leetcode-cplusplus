//
// Created by zhang on 2021/6/4.
//
#include "common-header.h"
class Solution {
public:
    int strToInt(string &str) {
        const auto size = str.size();
        const unsigned nBound = 0x80000000, pBound = 0x7fffffff;  // 2147483648,2147483647
        unsigned long ans = 0;
        if (size == 0) return ans;
        int index = 0;
        while (index < size) {
            if (str[index] != ' ') break;
            index++;
        }
        if (index >= size) return ans;
        bool negative = false;
        switch (str[index]) {
            case '-':
                negative = true;
            case '+':
                index++;
                break;
        }
        while (index < size) {
            if (str[index] < '0' || str[index] > '9') break;
            ans *= 10;
            ans += str[index] - '0';
            if (ans >= nBound) break;
            index++;
        }
        if (negative) {
            ans = ans > nBound ? -nBound : -ans;
        } else {
            ans = ans > pBound ? pBound : ans;
        }
        return ans;
    }
};