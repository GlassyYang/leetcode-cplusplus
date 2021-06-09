//
// Created by zhang on 2021/6/4.
//
#include "common-header.h"
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        queue<int> que;
        que.push(1);
        vector<vector<int>> ans = {{1}};
        for (int i = 1; i < numRows; ++i) {
            int size = que.size();
            vector<int> row = {1};
            que.push(1);
            for (int j = 1; j < size; ++j) {
                int pre = que.front();
                que.pop();
                int val = pre + que.front();
                row.push_back(val);
                que.push(val);
            }
            row.push_back(1);
            que.pop();
            que.push(1);
            ans.push_back(row);
        }
        return ans;
    }
};