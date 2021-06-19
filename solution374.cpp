//
// Created by zhang on 2021/6/14.
//

int guess(int);

class Solution {
public:
    int guessNumber(int n) {
        int begin = 1, end = n;
        while (begin < end) {
            int mid = (begin + end) / 2;
            switch (guess(mid)) {
                case -1:
                    end = mid - 1;
                    break;
                case 1:
                    begin = mid + 1;
                    break;
                default:
                    return mid;
            }
        }
        return begin;
    }
};