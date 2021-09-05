//
// Created by zhang on 2021/9/3.
//
#include "common-header.h"
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param heights int整型vector
     * @return int整型vector
     */
    vector<int> findBuilding(vector<int>& heights) {
        // write code here
        // 两个栈，一个单调递增栈，一个单调递减栈
        const int n = heights.size();
        vector<int> res;
        int left[n];
        int right[n];
        left[0] = right[n - 1] = 1;
        for(int i = 1; i < n; ++i) {
            int preIndex = i - 1;
            const int &height = heights[i];
            while (heights[preIndex] <= height && preIndex >= 0) {
                preIndex--;
            }
            if(preIndex >= 0) {
                left[i] = left[preIndex] + 1;
            } else {
                left[i] = 1;
            }
        }
        for(int i = n - 2; i >= 0; --i) {
            int preIndex = i + 1;
            const int &height = heights[i];
            while (heights[preIndex] < height && preIndex < n) {
                preIndex++;
            }
            if(preIndex < n) {
                right[i] = right[preIndex] + 1;
            } else {
                right[i] = 1;
            }
        }
        for(int i = 0; i < n; ++i) {
            int leftIndex = i - 1;
            int rightIndex = i + 1;
            int count = 1;
            if(leftIndex >= 0) count += left[leftIndex];
            if(rightIndex < n) count += right[rightIndex];
            res.push_back(count);
        }
        return res;
    }
};

int main() {
    vector<int> heights = {5,3,8,3,2,5};
    Solution solution;
    vector<int> res = solution.findBuilding(heights);
    for(int i : res) {
        cout << i << " ";
    }
    cout << endl;
}