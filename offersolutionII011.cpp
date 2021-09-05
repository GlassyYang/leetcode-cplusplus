//
// Created by zhang on 2021/9/5.
//

#include "common-header.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> prefix;
        int count = 0,  maxLength = 0;
        for(int i = 0; i < n; ++i) {
            count += nums[i] == 0 ? -1 : 1;
            if(count == 0) {
                maxLength = i + 1;
            } else {
                auto last = prefix.find(-count);
                if(last != prefix.end()) {
                    maxLength = max(maxLength, i - last->second);
                }
                prefix.insert(make_pair(count, i));
            }
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0};
    cout << solution.findMaxLength(nums) << endl;
}
