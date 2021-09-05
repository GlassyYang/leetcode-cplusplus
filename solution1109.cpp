//
// Created by zhang on 2021/8/31.
//
#include "common-header.h"
namespace common {
    class Solution {
    public:
        vector<int> corpFlightBookings(vector<vector<int>> &bookings, const int n) {
            vector<int> seats(n, 0);
            for (vector<int> &order : bookings) {
                for (int i = order[0]; i <= order[1]; ++i) {
                    seats[i] += order[2];
                }
            }
            return seats;
        }
    };
}

namespace difference {
    class Solution {
    public:
        vector<int> corpFlightBookings(vector<vector<int>> &bookings, const int n) {
            vector<int> seats(n, 0);
            for (vector<int> &order : bookings) {
                seats[order[0] - 1] -= order[2];
                seats[order[1]] += order[2];
            }
            for(int i = 1; i < n; ++i) {
                seats[i] += seats[i - 1];
            }
            return seats;
        }
    };
}