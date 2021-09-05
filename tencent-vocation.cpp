//
// Created by zhang on 2021/9/3.
//

#include <iostream>
#include <climits>
using namespace std;

int minRestDays(bool canWork[], bool canExercise[], int n) {
    int dp[n + 1][3];
    // 0 休息， 1工作，2锻炼
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = min(dp[i][0], dp[i - 1][2]) + 1;
        if(canWork[i - 1]) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        } else {
            dp[i][1] = INT_MAX;
        }
        if(canExercise[i - 1]) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        } else {
            dp[i][2] = INT_MAX;
        }
    }
    int res = min(dp[n][0], dp[n][1]);
    return min(dp[n][2], res);
}

int main() {
    int n;
    cin >> n;
    bool canWork[n];
    bool canExercise[n];
    bool *dir[2] = {canWork, canExercise};
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < n; ++j) {
            int can;
            cin >> can;
            dir[i][j] = (can == 1);
        }
    }
    cout << minRestDays(canWork, canExercise, n) << endl;
}