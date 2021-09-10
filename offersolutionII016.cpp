//
// Created by zhang on 2021/9/6.
//

#include "common-header.h"

class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        const int n = s.length();
        vector<int> count(alphabet, 0);
        int left = 0, replica = 0, maxLength = 0;
        for(int right = 0; right < n; ++right) {
            int offset = s[right] - 'a';
            if(count[offset]++ > 0) {
                replica++;
            }
            if(replica > 0) {
                int leftOffset = s[left++] - 'a';
                if(count[leftOffset]-- == 2) {
                    replica--;
                }
            }
            if(replica == 0) {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        return maxLength;
    }
private:
    static const int alphabet = 26;
};

int main() {
    string s = "pwwkew";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
}