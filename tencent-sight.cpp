//
// Created by zhang on 2021/9/3.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(vector<int> &a, vector<int> &b) {
    if (a[0] < b[0]) {
        return 1;
    } else if (a[0] > b[0]) {
        return -1;
    }
    if (a[1] < b[1]) {
        return -1;
    } else if (a[1] > b[1]) {
        return 1;
    }
    return 0;
}

int findMinGard(vector<vector<int>> &section, int n, int l) {
    sort(begin(section),end(section), compare);
    int cur = 0;
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(section[i][0] <= cur) {
            cur = section[i][1];
            count++;
        }
    }
    return count;
}

int main() {
    int n, l;
    cin >> n >> l;
    vector<vector<int> > section(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> section[i][0] >> section[i][1];
    }
    cout << findMinGard(section, n, l) << endl;
}