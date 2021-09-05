//
// Created by zhang on 2021/9/2.
//
#include "common-header.h"
class Solution {
public:
    string addBinary(string a, string b) {
        const int aLength = a.length(), bLength = b.length();
        const int minLength = min(aLength, bLength);
        int flag = 0;
        forward_list<char> res;
        for(int i = 1; i <= minLength; i++) {
            int left = a[aLength - i] - '0', right = b[bLength - i] - '0';
            int ans = left + right + flag;
            res.emplace_front((ans & 1) + '0');
            flag = ans >> 1;
        }
        string *maxStr = &a;
        int maxLength = aLength;
        if (bLength > aLength) {
            maxLength = bLength;
            maxStr = &b;
        }
        for(int i = maxLength - minLength - 1; i >= 0; --i) {
            int ans = (maxStr->operator[](i) - '0') + flag;
            res.emplace_front((ans & 1) + '0');
            flag = ans >> 1;
        }
        if (flag) {
            res.emplace_front(flag + '0');
        }
        return string(res.begin(), res.end());
    }
};

int main() {
    Solution solution;
    cout << solution.addBinary("1", "1") << endl;
}