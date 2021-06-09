//
// Created by zhang on 2021/5/19.
//
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
namespace dfs{
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
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
            for (auto i = sta.begin(); i != sta.end(); ++i) {
                cout << *i << ' ';
            }
            cout << endl;
            ++count;
        }
    }
};
}
namespace dp {
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        const int m = nums.size() + 1;
        int sum = 0;
        for (auto &i : nums) sum += abs(i);
        const int n = 2 * sum + 1;
        int dp[m][n];
        for (int i = 0; i < n; ++i) {
            dp[0][i] = 0;
        }
        dp[0][0 + sum] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                const int &num = nums[i - 1];
                dp[i][j] = 0;
                if (j - num + sum >= 0) dp[i][j + sum] += dp[i - 1][j - num + sum];
                if (j + num + sum <= sum << 1) dp[i][j + sum] += dp[i - 1][j + num + sum];
            }
        }
        return dp[m - 1][sum + target];
    }
};
}

