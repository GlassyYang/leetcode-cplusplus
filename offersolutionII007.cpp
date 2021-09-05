//
// Created by zhang on 2021/9/4.
//
#include "common-header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end(), less<>());
        const int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] > 0) {
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = n - 1;
            while(left < right) {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    left++;
                } else if (right < n - 1 && nums[right] == nums[right + 1]) {
                    right--;
                } else {
                    int temp = nums[left] + nums[right] + nums[i];
                    if(temp == 0) {
                        res.emplace_back(vector<int>{nums[left], nums[right], nums[i]});
                        left++;
                        right--;
                    } else if(temp > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution solution;
    cout << solution.threeSum(nums).size() << endl;
}