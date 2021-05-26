//
// Created by zhang on 2021/5/26.
//
#include "common-header.h"
class Solution {
public:
    string reverseParentheses(string s) {
        int index = 0;
        n = s.length();
        return reverseParentheses(s, index);
    }

private:
    int n;
    string reverseParentheses(string &s, int &index) {
        string ans;
        while (index < n) {
            const char &c = s[index];
            index++;
            if (c == '(') {
                string temp = reverseParentheses(s, index);
                reverse(temp.begin(), temp.end());
                ans += temp;
            } else if (c == ')') {
                break;
            } else {
                ans += c;
            }
        }
        return ans;
    }
};

int main () {

}