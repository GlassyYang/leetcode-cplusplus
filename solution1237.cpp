//
// Created by zhang on 2021/6/15.
//
#include "common-header.h"
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z) {
        // 先固定x，搜索y
        vector<vector<int>> ans;
        int x = 1, y = 1000;
        while (x <= 1000 && y >= 1) {
            int f = customfunction.f(x, y);
            if (f > z) --y;
            else if (f < z) ++x;
            else ans.push_back(vector<int>{x++,y--});
        }
        return ans;
    }
};