//
// Created by zhang on 2021/6/1.
//
#include "common-header.h"
class Solution {
public:
    typedef long long LL;
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<LL> prefixSum;
        vector<bool> ans;
        LL sum = 0;
        for (int &candies : candiesCount) {
            sum += candies;
            prefixSum.push_back(sum);
        }
        for (auto &query: queries) {
            LL &candiesSum = prefixSum[query[0]],
                yesterdayCandiesSum = query[0] == 0 ? 0 : prefixSum[query[0] - 1],
                favouriteDay = query[1] + 1;
             long double maxEat = query[2];
            if (candiesSum >= favouriteDay && yesterdayCandiesSum / maxEat <= favouriteDay) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};