//
// Created by zhang on 2021/5/9.
//
# include <vector>
# include <cmath>
using namespace std;
class Solution {
public:
    vector<int> printNumbers(int n) {
        // 先求出最大的N位数
        int max_n = pow(10, n) - 1;
        vector<int> ans;
        for(int i = 1; i <= max_n; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};
