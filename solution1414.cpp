//
// Created by zhang on 2021/5/28.
//

#include "common-header.h"

class Solution {
public:
    Solution() {
        fb[0] = fb[1] = 1;
        for (int i = 2; i < N; ++i) {
            fb[i] = fb[i - 1] + fb[i - 2];
        }
    }
    int findMinFibonacciNumbers(int k) {
        int count = 0;
        int end = N;
        while (k > 0) {
            int index = binary_search(end, k);
            k -= fb[index];
            count++;
        }
        return count;
    }
private:
    const static int N = 45;
    int fb[N];
    int binary_search(int end, int target) {
        int start = 0;
        while (start <= end) {
            int mid = (start + end) >> 1;
            if (fb[mid] == target) return mid;
            else if (fb[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }
};


int main(int argc, char **argv) {
    Solution solution;
    return EXIT_SUCCESS;
}