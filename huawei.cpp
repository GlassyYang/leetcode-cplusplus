//
// Created by zhang on 2021/9/8.
//
#include <iostream>
#include <vector>
#define MAX_STEP 1000000
using namespace std;


int main() {
    int m, n;
    string line;
    getline(cin, line);
    int de = line.find(',') + 1;
    m = stoi(line.substr(0, de));
    n = stoi(line.substr(de));
    vector<vector<int>> dp(m, vector<int>(n, MAX_STEP));
    dp[0][0] = 0;
    int input;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> input;
            for(int k = 1; k <= input; ++k) {
                if(i + k < m) {
                    dp[i + k][j] = min(dp[i + k][j], dp[i][j] + 1);
                }
                if(j + k < n) {
                    dp[i][j + k] = min(dp[i][j + k], dp[i][j] + 1);
                }
            }
        }
    }
    int min = dp[m - 1][n - 1];
    if(min >= MAX_STEP) {
        min = -1;
    }
    cout << min << endl;
}