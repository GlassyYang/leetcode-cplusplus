//
// Created by zhang on 2021/9/3.
//
#include "common-header.h"
namespace base {
    class Solution {
    public:
        int maxProduct(vector<string> &words) {
            const int n = words.size();
            vector<unordered_set<char>> sets;
            for (string &word : words) {
                unordered_set<char> wordSet(word.begin(), word.end());
                sets.emplace_back(wordSet);
            }
            int maxMulti = 0;
            for (int i = 0; i < n; ++i) {
                unordered_set<char> &firstSet = sets[i];
                int firstLength = words[i].length();
                for (int j = i + 1; j < n; ++j) {
                    unordered_set<char> &secondSet = sets[j];
                    bool exists = false;
                    for (auto &pair : secondSet) {
                        if (firstSet.find(pair) != firstSet.end()) {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists) {
                        int secondLength = words[j].length();
                        int res = firstLength * secondLength;
                        if (res > maxMulti) {
                            maxMulti = res;
                        }
                    }
                }
            }
            return maxMulti;
        }
    };
}

namespace binary {
    class Solution {
    public:
        int maxProduct(vector<string> &words) {
            const int n = words.size();
            vector<int> binaries;
            for(string &word : words) {
                int binary = 0;
                for(char &character : word) {
                    int mask = 1 << (character - 'a');
                    binary |= mask;
                }
                binaries.emplace_back(binary);
            }
            int max = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    if((binaries[i] & binaries[j]) == 0) {
                        int lLength = words[i].length(), rLength = words[j].length();
                        if(lLength * rLength > max) {
                            max = lLength * rLength;
                        }
                    }
                }
            }
            return max;
        }
    };
}