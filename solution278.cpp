//
// Created by zhang on 2021/6/14.
//
bool isBadVersion(int);
class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1, end = n;
        while(begin < end) {
            int mid = (begin + end) >> 1;
            if (isBadVersion(mid)) end = mid;
            else begin = mid + 1;
        }
        return begin;
    }
};
