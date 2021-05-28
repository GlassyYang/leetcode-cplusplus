//
// Created by zhang on 2021/5/28.
//
#include "common-header.h"

class Solution {
public:
    // TODO
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int  sell = 0, buy = INT_MIN >> 1;
        for(int &price : prices) {
            sell = max(sell, buy + price);
            buy = max(buy, sell - price);
        }
        return sell;
    }
};
