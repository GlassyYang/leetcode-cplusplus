//
// Created by zhang on 2021/5/20.
//
#include "common-header.h"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) >> 1;
            if (nums[start] == target || nums[end] == target || nums[mid] == target) return true;
            else if (nums[start] < target && nums[mid] > target) end = mid - 1;
            else if (nums[mid] < target && nums[end] > target) start = mid + 1;
            else start++,end--;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<int> test = {1,3};
    cout << solution.search(test, 2) << endl;
    return 0;
}
