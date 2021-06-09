//
// Created by zhang on 2021/6/9.
//
#include "common-header.h"
class Solution {
public:
    int numOfMinutes(const int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxTime = 0;
        unordered_map<int, vector<int>> adjacent;
        for(int i = 0; i < n; i++) {
            adjacent[manager[i]].push_back(i);
        }
        queue<pair<int, int>> que;
        que.push(make_pair(-1, 0));
        while (!que.empty())
        {
            pair<int, int> &cur = que.front();
            vector<int> &children = adjacent[cur.first];
            if (children.empty()) maxTime = max(maxTime, cur.second);
            for (auto &child : children) {
                que.push(make_pair(child, cur.second + informTime[child]));
            }
            que.pop();
        }
        return maxTime;
    }
};
