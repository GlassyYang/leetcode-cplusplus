//
// Created by zhang on 2021/9/2.
//
#include "common-header.h"
class Solution {
public:
    int divide(int a, int b) {
        if(a == INT_MIN && b == -1) return INT_MAX;
        int flag = 1;
        long al = abs(a), bl = abs(b);
        if(al == bl) return flag * 1;
        cout <<al << ' ' << bl << endl;
        if((a >> 31) != (b >> 31)) {
            flag = -1;
        }
        long left = 0, right = al;
        int res = 0;
        while(left < right - 1) {
            int mid = (left + right) >> 1;
            long multiRes = multi(bl, mid);
            if(multiRes < al) {
                left = mid;
            } else if(multiRes > al) {
                right = mid;
            } else {
                res = mid;
                break;
            }
        }
        if(left == right - 1) {
            res = left;
        }
        return flag * res;
    }
private:
    int multi(long a, long b) {
        long ans = 0;
        while(b > 0) {
            if((b & 1) == 1) ans += a;
            a <<= 1;
            b >>= 1;
        }
        return ans;
    }
};

int main() {
    int a = -1, b = 1;
    Solution solution;
    cout << solution.divide(a, b) << endl;
}
