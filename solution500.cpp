//
// Created by zhang on 2021/5/24.
//
#include "common-header.h"

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        const int n = 3;
        unordered_set<char> sets[n] = {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
                                       {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
                                       {'z', 'x', 'c', 'v', 'b', 'n', 'm'}};
        vector<string> ans;
        for (auto &word :words) {
            if (word.empty()) ans.push_back(word);
            else {
                for (int i = 0; i < n; ++i) {
                    bool flag = true;
                    for (char c : word) {
                        c = tolower(c);
                        if (sets[i].find(c) == sets[i].end()) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) ans.push_back(word);
                }
            }
        }
        return ans;
    }
};