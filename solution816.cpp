//
// Created by zhang on 2021/8/8.
//

#include "common-header.h"

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        const auto n = s.length();
        for(int i = 2; i < n - 1; ++i) {
            string left(s.substr(1, i - 1));
            string right(s.substr(i, n - i - 1));
            if(validate(left) && validate(right)) {
                vector<string> leftPos = addPos(left);
                vector<string> rightPos = addPos(right);
                for(string& l : leftPos) {
                    string lStr = "(" + l + ", ";
                    for(string& r : rightPos) {
                        ans.push_back(lStr + r + ")");
                    }
                }
            }
        }
        return ans;
    }
private:
    bool validate(string& s) {
        int num = stoi(s) != 0;
        return num != 0 || s.length() == 1;
    }
    vector<string> addPos(string& s) {
        vector<string> ans;
        if (s.length() > 1 && s[0] != '0') {
            ans.emplace_back(s);
        }
        const auto n = s.length();
        for(int i = 1; i < n; ++i) {
            string left(s.substr(0, i));
            string right(s.substr(i, n - i));
            if(validate(left) && validate(right) && stoi(right) != 0) {
                ans.push_back(left + '.' + right);
            }
        }
        return ans;
    }
};


int main() {
    Solution solution;
    vector<string> ans = solution.ambiguousCoordinates("(123)");
    for (string& str : ans) {
        cout << str << endl;
    }
    return 0;
}