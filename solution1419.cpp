//
// Created by zhang on 2021/6/8.
//

#include "common-header.h"
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int status[5];
        fill(begin(status), end(status), 0);
        string croak = "croak";
        for(auto &c : croakOfFrogs) {
            auto index = croak.find(c);
            status[index]++;
            if (index > 0) {
                if (status[index - 1] == 0) return -1;
                status[index - 1]--;
            } else if (status[4] > 0) status[4]--;
        }
        for (int i = 0; i < 4; ++i) {
            if (status[i] != 0) return -1;
        }
        return status[4];
    }
};