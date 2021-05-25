//
// Created by zhang on 2021/5/20.
//
#include "common-header.h"
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &x, vector<int> &y){ return x[0] < y[0];});
        int max = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            int width = points[i][0] - points[i + 1][0];
            if (width > max) max = width;
        }
        return max;
    }
};
