//
// Created by zhang on 2021/5/9.
//
#include <vector>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

class Solution{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0) return true;
        stack<int> sta;
        decltype(popped.size()) pi = 0;
        for(auto &i : popped) {
            int push = pushed[pi];
            if (sta.empty()) sta.push(push);
            else push = sta.top();
            while (push != i) {
                pi++;
                if (pi == pushed.size()) return false;
                push = pushed[pi];
                sta.push(push);
            }
            sta.pop();
        }
        return true;
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> pushed = {1,0}, popped = {1,0};

    solution.validateStackSequences(pushed, popped);
}

