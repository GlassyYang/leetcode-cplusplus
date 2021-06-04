//
// Created by zhang on 2021/6/1.
//

#include "common-header.h"

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        constexpr int alphabet = 30;
        const int m = s.size(), n = t.size();
        if (m != n) return false;
        unordered_set<int> set;
        for (int i = 0; i < m; ++i) {
            int count = t[i] - s[i];
            if (count == 0) continue;
            while (count <= k) {
                if (set.find(count) == set.end()) break;
                count += 26;
            }
            if (count > k) return false;
            set.insert(count);
        }
        return true;
    }
    bool canConvertString(string s, string t, int k, int type = 2) {
        if (s.size() != t.size()) {
            return false;
        }
        int counts[26] = {0};
        int length = s.size();
        for (int i = 0; i < length; i++) {
            int difference = t.at(i) - s.at(i);
            if (difference < 0) {
                difference += 26;
            }
            counts[difference]++;
        }
        for (int i = 1; i < 26; i++) {
            int maxConvert = i + 26 * (counts[i] - 1);
            if (maxConvert > k) {
                return false;
            }
        }
        return true;
    }
};