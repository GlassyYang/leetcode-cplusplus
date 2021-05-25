//
// Created by zhang on 2021/5/25.
//
#include "common-header.h"
class Solution {
public:
    string minNumber(vector<int>& nums) {
        string ans;
        const int n = nums.size();
        vector<string> buf;
        for (int i : nums) {
            buf.push_back(to_string(i));
        }
        sort(buf.begin(), buf.end(), [](string &a, string &b) -> bool {return a + b < b + a;});
        for (string a : buf) {
            ans += a;
        }
        return ans;
    }
};
