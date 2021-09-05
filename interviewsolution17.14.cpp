//
// Created by zhang on 2021/9/3.
//
#include "common-header.h"
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        const int n = arr.size();
        int begin = 0, end = n;
        while(begin < end) {
            int mid = partition(arr, begin, end);
            if(mid > k) {
                end = mid;
            } else if (mid < k) {
                begin = mid + 1;
            } else {
                break;
            }
        }
        return vector<int>(arr.begin(), arr.begin() + k);
    }
private:
    int partition(vector<int> &arr, int begin, int end) {
        int flag = arr[begin];
        int left = begin;
        for(int i = begin + 1; i < end; ++i) {
            if(arr[i] <= flag) {
                swap(arr[++left],arr[i]);
            }
        }
        swap(arr[begin], arr[left]);
        return left;
    }
};

int main() {
    vector<int> arr = {1,3,5,7,2,4,6,8};
    Solution solution;
    solution.smallestK(arr, 4);
}