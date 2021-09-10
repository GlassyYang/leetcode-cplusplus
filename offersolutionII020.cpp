//
// Created by zhang on 2021/9/7.
//
#include "common-header.h"
class Solution {
public:
    int countSubstrings(string &s) {
        const auto n = s.length();
        int count = 0;
        for(int i = 0; i < n; ++i) {
            int left = i, right = i;
            while(left >= 0 && right < n) {
                if(s[left--] == s[right++]) {
                    count++;
                } else {
                    break;
                }
            }
            left = i - 1, right = i;
            while(left >= 0 && right < n) {
                if(s[left--] == s[right++]) {
                    count++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};