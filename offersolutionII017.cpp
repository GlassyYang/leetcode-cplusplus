//
// Created by zhang on 2021/9/7.
//
#include "common-header.h"
class Solution {
public:
    string minWindow(string s, string t) {
        const int n = s.length();
        int minLeft = -1, minLength = n;
        int left = 0;
        unordered_map<char, int> charactersOft, charactersOfs;
        for(char &chr : t) {
            charactersOft[chr]++;
        }
        for(int right = 0; right < n; ++right) {
            charactersOfs[s[right]]++;
            bool flag = true;
            for(auto &entry : charactersOft) {
                if(charactersOfs[entry.first] < entry.second) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                while(left <= right) {
                    char &chr = s[left++];
                    if(--charactersOfs[chr] < charactersOft[chr]) {
                        int curLength = right - left + 2;
                        if(curLength < minLength) {
                            minLeft = left - 1;
                            minLength = curLength;
                        }
                        break;
                    }

                }

            }
        }
        return minLeft == -1 ? "" : s.substr(minLeft, minLength);
    }
};

int main() {
    Solution solution;
    cout << solution.minWindow("a", "a") << endl;
}