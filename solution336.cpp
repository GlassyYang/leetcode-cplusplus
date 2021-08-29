//
// Created by zhang on 2021/8/8.
//
#include "common-header.h"

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        const auto n = words.size();
        for(int i = 0; i < n; ++i) {
            string& left = words[i];
            bool flag = false;
            for(int j = 0; j < n; ++j) {
                if (i == j) continue;
                flag = true;
                string& right = words[j];
                auto leftLength = left.length();
                auto rightLength = right.length();
                auto minLength = min(leftLength, rightLength);
                for (int k = 0; k < minLength; ++k) {
                    if (left[k] != right[rightLength - 1 - k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag && leftLength != rightLength) {
                    int remain = abs(int(leftLength - rightLength));
                    if (leftLength > rightLength) {
                        for(int k = 1; k <= (remain >> 1); ++k) {
                            if (left[leftLength - k] != left[leftLength - remain + k - 1]) {
                                flag = false;
                                break;
                            }
                        }
                    } else {
                        for(int k = 0; k < (remain >> 1); ++k) {
                            if (right[k] != right[remain - k - 1]) {
                                flag = false;
                                break;
                            }
                        }
                    }
                }
                if (flag) {
                    ans.emplace_back(vector<int>({i, j}));
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> words = {"bb","bababab","baab","abaabaa","aaba","","bbaa","aba","baa","b"};
    Solution solution;
    vector<vector<int>> res = solution.palindromePairs(words);

    return 0;
}