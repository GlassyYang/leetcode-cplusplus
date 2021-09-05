//
// Created by zhang on 2021/9/4.
//
#include "common-header.h"
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int n = nums.size();
        int left = 0, right = 1, accu = nums[0];
        int count = 0;
        while(right <= n) {
            if(accu < k) {
                if(right >= n) {
                    cout << right << " " << left << endl;
                    int length = right - left;
                    count += (length * (length + 1)) >> 1;
                    break;
                }
                accu *= nums[right++];
            } else {
                accu /= nums[left++];
                cout << right << "  " << left << endl;
                int length = right - left;
                count += (length *(length + 1)) >> 1;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums{10,5,2,6};
    Solution solution;
    solution.numSubarrayProductLessThanK(nums, 100);
}