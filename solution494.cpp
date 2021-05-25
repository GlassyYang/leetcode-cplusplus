//
// Created by zhang on 2021/5/19.
//
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0;
        n = nums.size();
        recusive(nums, 0, 0, target);
        return count;
    }

private:
    int count = 0;
    int n = 0;
    deque<char> sta;
    void recusive(vector<int> nums, int index, int sum, int &target) {
        if (index < n) {
            sta.push_back('+');
            recusive(nums, index + 1, sum + nums[index], target);
            sta.pop_back();
            sta.push_back('-');
            recusive(nums, index + 1, sum - nums[index], target);
        }
        cout << sum << endl;
        if (sum == target) {
            for(auto i = sta.begin(); i != sta.end(); ++i) {
                cout << *i << ' ';
            }
            cout << endl;
            ++count;
        }
    }
};

