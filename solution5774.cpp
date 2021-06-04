//
// Created by zhang on 2021/5/30.
//
#include "common-header.h"
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        const int serversNumber = servers.size(), tasksNumber = tasks.size();
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy, free;
        for (int i = 0; i < serversNumber; ++i) {
            free.push(make_pair(servers[i], i));
        }
        int ts = 0;
        for (int i = 0; i < tasksNumber; ++i) {
            ts = max(ts, i);
            if (free.empty()) ts = busy.top().first;
            while (!busy.empty()) {
                const pair<int, int> &runningServer = busy.top();
                if (runningServer.first > ts) break;
                free.push(make_pair(servers[runningServer.second], runningServer.second));
                busy.pop();
            }
            const pair<int, int> candidateServer = free.top();
            busy.push(make_pair(ts + tasks[i], candidateServer.second));
            ans.push_back(candidateServer.second);
        }
        return ans;
    }
};