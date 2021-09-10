//
// Created by zhang on 2021/9/10.
//
#include "common-header.h"
class Solution {
public:
    vector<int> findOrder(const int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> entranceDegrees(numCourses, 0);
        vector<vector<int>> edges(numCourses, vector<int>());
        vector<int> res;
        int visited = 0;
        for(auto &prerequisite : prerequisites) {
            edges[prerequisite[1]].push_back(prerequisite[0]);
            entranceDegrees[prerequisite[0]]++;
        }
        deque<int> queue;
        for(int i = 0; i < numCourses; ++i) {
            if(entranceDegrees[i] == 0) {
                queue.push_back(i);
            }
        }
        while(!queue.empty()) {
            int cur = queue.front();
            for(auto &targets : edges[cur]) {
                if(--entranceDegrees[targets] == 0) {
                    queue.push_back(targets);
                }
            }
            queue.pop_front();
            res.push_back(cur);
            visited++;
        }
        if(visited != numCourses) {
            return {};
        }
        return res;
    }
};
