//
// Created by zhang on 2021/8/29.
//
#include "common-header.h"
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        const int n = pairs.size();
        if (n == 0) return 0;
        sort(pairs.begin(), pairs.end(), comparator);
        int count = 1, end = pairs[0][1];
        for(int i = 1; i < n; ++i) {
            if (end < pairs[i][0]) {
                count++;
                end = pairs[i][1];
            }
        }
        return count;
    }
private:
    static int comparator(vector<int> a, vector<int> b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
};