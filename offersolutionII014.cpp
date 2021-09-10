//
// Created by zhang on 2021/9/6.
//
#include "common-header.h"
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int s1Length = s1.length(), s2Length = s2.length();
        vector<int> count(alphabet, 0);
        if(s2Length < s1Length) {
            return false;
        }
        int left = 0, diff = 0;
        for(int i = 0; i < s1Length; ++i) {
            if(count[s1[i] - 'a'] == 0) {
                diff++;
            }
            count[s1[i] - 'a']++;
        }
        for(int right = 0; right < s2Length; ++right) {
            int offset = s2[right] - 'a';
            if(count[offset] == 0) {
                diff++;
            }
            count[offset]--;
            if(count[offset] == 0) {
                diff--;
            }
            if(right - left >= s1Length) {
                int offsetLeft = s2[left++] - 'a';
                if(count[offsetLeft] == 0) {
                    diff++;
                }
                count[offsetLeft]++;
                if(count[offsetLeft] == 0) {
                    diff--;
                }
            }
            if(diff == 0) {
                return true;
            }
        }
        return false;
    }
private:
    const static int alphabet = 26;
};

int main() {
    Solution solution;
    string s1 = "hello", s2 = "ooolleoooleh";
    cout << solution.checkInclusion(s1, s2);
}