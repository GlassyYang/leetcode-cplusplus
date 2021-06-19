//
// Created by zhang on 2021/6/19.
//

#include "common-header.h"

class Solution {
public:
    int maxLength(const vector<string> &arr) {
        const int n = arr.size();
        int maxStrings = 0, curSize = 0;
        stack<int> sta;
        unordered_set<char> usedCharacters;
        sta.push(0);
        sta.push(0);
        while (sta.size() > 1) {
            int cur = sta.top();
            sta.pop();
            int &parent = sta.top();
            if (cur < n) {
                const string &curStr = arr[cur];
                unordered_set<char> curSet;
                bool canAdd = true;
                for(const char &c : curStr) {
                    if (curSet.count(c) > 0) {
                        canAdd = false;
                        break;
                    }
                    curSet.insert(c);
                }
                for(const char &c : curSet) {
                    if (usedCharacters.count(c) > 0) {
                        canAdd = false;
                        break;
                    }
                }
                if (canAdd) {
                    usedCharacters.insert(curSet.begin(), curSet.end());
                    sta.push(cur);
                    sta.push(cur + 1);
                    cout << curStr << " with length: " << curSize << endl;
                    curSize += curStr.length();
                } else {
                    sta.push(cur + 1);
                }
            } else {
                cout << curSize << endl;
                maxStrings = max(maxStrings, curSize);
                const string &parentStr = arr[parent++];
                curSize -= parentStr.length();
                for (const char &c : parentStr) {
                    usedCharacters.erase(c);
                }
            }
        }
        return maxStrings;
    }
};

int main(int argc, char **argv)
{
    vector<string> arr = {"cha","r","act","ers"};
    Solution solution;
    cout << solution.maxLength(arr) << endl;
}