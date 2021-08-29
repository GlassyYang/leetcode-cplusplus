//
// Created by zhang on 2021/8/8.
//

#include "common-header.h"

class Solution {
public:
    vector<int> minOperations(string boxes) {
        const auto n = boxes.size();
        vector<int> left;
        vector<int> right;
        vector<int> ans;
        int p = 0, c = 0;
        for(int i = 0; i < n; ++i) {
            p += c;
            left.emplace_back(p);
            c += boxes[i] - 0x30;
        }
        p = 0, c = 0;
        for(int i = n - 1; i >= 0; --i) {
            p += c;
            right.emplace_back(p);
            c += boxes[i] - 0x30;
        }
        for(int i = 0; i < n; ++i) {
            ans.emplace_back(left[i] + right[n - i - 1]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> ans = solution.minOperations("110");
    return 0;
}

