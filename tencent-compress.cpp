//
// Created by zhang on 2021/9/3.
//
#include "common-header.h"
#include <stack>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return string字符串
     */
    string compress(string str) {
        // write code here
        const int n = str.length();
        stack<string> parts;
        stack<int> repeatTimes;
        string part;
        int number = 1;
        string buf;
        for(int i = 0; i < n; ++i) {
            switch(str[i]) {
                case '[':
                    parts.push(part);
                    part.erase();
                    repeatTimes.push(number);
                    break;
                case ']':
                    buf.erase();
                    while(number > 0) {
                        buf += part;
                        number--;
                    }
                    number = repeatTimes.top();
                    part = parts.top() + buf;
                    repeatTimes.pop();
                    parts.pop();
                    break;
                case '|':
                    number = stoi(part);
                    part.erase();
                    break;
                default:
                    part.push_back(str[i]);
            }
        }
        return part;
    }
};

int main() {
    Solution solution;
    cout << solution.compress("HG[3|B[2|CA]]F") << endl;
}