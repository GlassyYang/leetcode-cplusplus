//
// Created by zhang on 2021/9/4.
//

#include <string>
#include <iostream>
#include <set>
using namespace std;
string findKthSubString(string &str, int k) {
    const int n = str.length();
    set<string> que;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            que.emplace(str.substr(i, j - i));
            if(que.size() > k) {
                que.erase(*que.rbegin());
            }
        }
    }
    return *que.rbegin();
}

int main() {
    string str = "aabb";
    int k = 3;
    cout << findKthSubString(str, k) << endl;
}