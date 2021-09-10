//
// Created by zhang on 2021/9/7.
//

#include <iostream>
#include <vector>
using namespace std;
long long maxNumber(long long num) {
    long long numCp = num;
    long long numMin = 0;
    int count = 0;
    while(num > 0) {
        num /= 10;
        numMin *= 10;
        numMin += 1;
        count++;
    }
    num = numCp;
    if(num < numMin) {
        long long ans = 0;
        while (count > 1) {
            ans *= 10;
            ans += 3;
            count--;
        }
        return ans;
    }
    vector<int> que;
    while(num > 0) {
        que.push_back(num % 10);
        num /= 10;
    }
    const int n = que.size();
    for (int i = 0; i < n; ++i) {
        if(que[i] >= 3) {
            que[i] = 3;
        } else if (que[i] == 0) {
            int right = i + 1;
            while(right < n) {
                auto &e = que[right];
                if(e > 0) {
                    e--;
                    for(int j = i; j < right; ++j) {
                        que[j] = 9;
                    }
                    for(int j = 0; j < i; ++j) {
                        que[j] = 3;
                    }
                    break;
                }
                right++;
            }
            if(que[i] != 0) {
                que[i] = 3;
            }
        }
    }
    long long ans = 0;
    int right = n - 1;
    while(que[right] == 0) {
        right--;
    }
    while(right >= 0) {
        ans *= 10;
        ans += que[right];
        right--;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        long long num;
        cin >> num;
        cout << maxNumber(num) << endl;
    }
}