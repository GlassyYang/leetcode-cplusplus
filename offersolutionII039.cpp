//
// Created by zhang on 2021/9/8.
//

#include "common-header.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        stack<int> sta;
        int maxArea = 0;
        for(int i = 0; i < n; ++i) {
            if(!sta.empty() && heights[sta.top()] > heights[i]) {
                int right = sta.top();
                while(!sta.empty() && heights[sta.top()] > heights[i]) {
                    int left = sta.top();
                    maxArea = max(maxArea, heights[left] * (i - left));
                    sta.pop();
                }
                if(sta.empty()) {
                    maxArea = max(maxArea, heights[right] * i);
                }
            }
            sta.push(i);
        }
        if(!sta.empty()) {
            int right = n, staSize = sta.size();
            while(staSize > 1) {
                int left = sta.top();
                sta.pop();
                if(sta.empty()) {}
                maxArea = max(maxArea, heights[left] * (right - left));
                staSize--;
            }
            maxArea = max(maxArea, heights[sta.top()] * n);
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> test = {5,4,3,2,1};
    cout << solution.largestRectangleArea(test) << endl;
}
