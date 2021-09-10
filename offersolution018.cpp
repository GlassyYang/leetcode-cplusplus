//
// Created by zhang on 2021/9/7.
//
#include "common-header.h"
#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        const int n = s.length();
        int right = n - 1, left = 0;
        while(left <= right) {
            while(left < n && !isalnum(s[left])) {
                left++;
            }
            while (right >= 0 && !isalnum(s[right])) {
                right--;
            }
            if(left < n && right >= 0 && tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome("OP") << endl;
}