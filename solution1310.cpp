//
// Created by zhang on 2021/5/18.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const auto n = arr.size();
        vector<int> s(n + 1, 0);
        for(auto i = 1; i <= n; ++i) {
            s[i] = s[i - 1] ^ arr[i - 1];
        }
        vector<int> ans;
        for(auto query : queries) {
            ans.push_back(s[query[0]] ^ s[query[1] + 1]);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    Solution solution;
    cout << solution.xorQueries(arr,queries).size() << endl;
    return 0;
}
