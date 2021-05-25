//
// Created by zhang on 2021/5/25.
//
#include "common-header.h"
class Solution {
public:
    vector<string> permutation(string s) {
        const int n = s.length();
        unordered_set<int> visited;
        deque<int> order;
        vector<string> ans;
        permutation(s, n, order, visited, ans);
        return ans;
    }
private:
    void permutation(string &s, const int &n, deque<int> &order, unordered_set<int> &visited, vector<string> & ans) {
        if (visited.size() == n) {
            string str;
            for (int i : order) {
                str += s[i];
            }
            ans.push_back(str);
        } else {
            unordered_set<char> st;
            for (int i = 0; i < n; ++i) {
                if (visited.find(i) == visited.end() && st.find(s[i]) == st.end()) {
                    visited.insert(i);
                    order.push_back(i);
                    st.insert(s[i]);
                    permutation(s, n, order, visited, ans);
                    visited.erase(i);
                    order.pop_back();
                }
            }
        }
    }
};