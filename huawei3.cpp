//
// Created by zhang on 2021/9/8.
//
#include <iostream>
using namespace std;
static int max_abs = 0;
static int minNumber;
static int sum = 0;
int getMaxAbs(int children[][2], int val[], int &cur) {
    int subSum = val[cur];
    if(children[cur][0] != -1) {
        subSum += getMaxAbs(children, val, children[cur][0]);
    }
    if(children[cur][1] != -1) {
        subSum += getMaxAbs(children, val, children[cur][1]);
    }
    int res = abs(sum - (subSum << 1));
    if(res > max_abs) {
        max_abs = res;
        minNumber = cur;
    } else if(res == max_abs) {
        minNumber = min(minNumber, cur);
    }
    return subSum;
}

int main() {
    int n;
    cin >> n;
    int val[n];
    int children[n][2];
    minNumber = n;
    for(int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        val[i] = temp;
        sum += temp;
        children[i][0] = -1;
        children[i][1] = -1;
    }
    int first, second;
    for(int i = 0; i < n - 1; ++i) {
        cin >> first >> second;
        if(children[first][0] == -1) {
            children[first][0] = second;
        } else {
            children[first][1] = second;
        }
    }
    int root = 0;
    getMaxAbs(children, val, root);
    cout << minNumber << endl;
    return 0;
}