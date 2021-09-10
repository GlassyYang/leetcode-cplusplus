//
// Created by zhang on 2021/9/7.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, k, e;
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i) {
        string output;
        for(int j = 0; j < n; ++j) {
            cin >> e;
            for(int l = 0; l < k; ++l) {
                output.push_back(e + '0');
                    output += ' ';
            }
        }
        output.pop_back();
        for(int j = 0; i < k; ++i) {
            cout <<output << endl;
        }
    }
}