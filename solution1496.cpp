//
// Created by zhang on 2021/5/20.
//
#include "common-header.h"
class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> passed;
        int x = 0, y = 0;
        passed.insert(make_pair(0, 0));
        for (auto &c : path) {
            switch (c) {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }
            pair<int, int> pair = make_pair(x, y);
            if (passed.find(pair) != passed.end()) return true;
            passed.insert(pair);
        }
        return false;
    }
};