//
// Created by zhang on 2021/7/18.
//
#include "common-header.h"
class Solution {
public:
    vector<vector<string>>& groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> indexes;
        for(string& str : strs) {
            string index = str;
            sort(index.begin(), index.end());
            indexes[index].emplace_back(str);
        }
        vector<vector<string>> *ans = new vector<vector<string>>(indexes.size());
        for(auto i = indexes.begin(); i != indexes.end(); i++) {
            ans->emplace_back(i->second);
        }
        return *ans;
    }
};
