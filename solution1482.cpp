//
// Created by zhang on 2021/5/9.
//
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
class solution1482 {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < m * k) return -1;
        int min = INT_MAX, max = INT_MIN;
        for(auto &i : bloomDay) {
            min = min <= i ? min : i;
            max = max >= i ? max : i;
        }
        // 开始进行二分查找
        int left = min, right = max + 1;
        while (left < right) {
            printf("%d %d\n", left, right);
            int mid = (left + right) / 2;
            bool ans = check(bloomDay, m, k, mid);
            if (ans)
                right = mid;
            else
                left = mid + 1;
        }
        return check(bloomDay, m, k, right) ? right : -1;
    }
private:
    bool check(vector<int> &bloomDay, int &m, int &k, int &day) {
        int count = 0, clusters = 0;
        for (auto &i : bloomDay) {
            if (i <= day) {
                count++;
                if (count >= k) {
                    clusters++;
                    count = 0;
                }
            } else {
                if (count >= k) clusters++;
                count = 0;
            }
        }
        if (count >= k) clusters++;
        return clusters >= m;
    }
};

int main(int argc, char **argv) {
    vector<int> test = {1,10,2,9,3,8,4,7,5,6};
    solution1482 solution;
    cout << "ans: " << solution.minDays(test, 4, 2);
    return 0;
}