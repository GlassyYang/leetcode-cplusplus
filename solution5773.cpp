//
// Created by zhang on 2021/5/30.
//
#include "common-header.h"
class Solution {
public:
    string maxValue(string &n, int x) {

        x += 0x30;
        char op = n[0];
        if(op == '-') {
            auto index = n.cbegin() + 1;
            while(*index < x) index++;
            n.insert(index, x);
        } else {
            auto index = n.cbegin();
            while(*index > x) index++;
            n.insert(index, x);
        }
        return n;
    }
};
