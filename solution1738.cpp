//
// Created by zhang on 2021/5/19.
//
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
class Solution {
public:
    // 计算二维前缀和，然后从结果中选择第K大的数。
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        auto m = matrix.size();
        auto n = matrix[0].size();
        vector<int> pre(m * n, 0);
        for(auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (0 == i) {
                    if (0 == j) pre[j] = matrix[i][j];
                    else pre[j] = pre[j - 1] ^ matrix[i][j];
                } else if (0 == j) {
                    pre[i * n] = pre[(i - 1) * n] ^ matrix[i][j];
                } else {
                    pre[i * n + j] = pre[(i - 1) * n + j - 1] ^ pre[i * n + j - 1] ^ pre[(i - 1) * n + j] ^ matrix[i][j];
                }
            }
        }
        nth_element(pre.begin(), pre.begin() + k - 1, pre.end(), greater<int>());
        return pre[k - 1];
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> matrix = {{5,2},{1,6}};
    Solution solution;
    cout << solution.kthLargestValue(matrix, 1) <<endl;
}

