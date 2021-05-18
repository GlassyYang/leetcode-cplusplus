//
// Created by zhang on 2021/5/10.
//

// 五分钟解决
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int s1Length = s1.length(), s2Length = s2.length();
        bool dp[s2.length() + 1];
        memset(dp, true, sizeof(dp));
        dp[0] = true;
        for(auto i = 0; i < s1Length; i++) {
            for(auto j = 1; j <= s2Length; j++) {
                char c1 = s1[i], c2 = s2[j - 1], c3 = s3[i + j - 1];
                dp[j] = (c3 == c1 && dp[j]) || (c3 == c2 && dp[j - 1]);
            }
        }
        return dp[s2Length];
    }
};


int main(int argc, char **argv) {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    Solution solution;
    cout << solution.isInterleave(s1, s2, s3);
    return 0;
}
