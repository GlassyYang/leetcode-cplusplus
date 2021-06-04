//
// Created by zhang on 2021/6/3.
//
#include "common-header.h"
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        int max_line = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> &x1 = points[i];
            int h = 0;
            unordered_map<double, int> map;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                vector<int> &x2 = points[j];
                double k = 0;
                int hc = h;
                calculateLine(x1, x2, h, k);
                if (hc != h) continue;
                int count = 2;
                if (map.find(k) == map.end()) {
                    map[k] = count;
                } else {
                    count = ++map[k];
                }
                if (count > max_line) max_line = count;
            }
            if (h > max_line) max_line = h;
        }
        return max_line;
    }
private:
    void calculateLine(vector<int> &x1, vector<int> &x2, int &h, double &k) {
        if (x1[1] == x2[1]) h++;
        else{
            double x = x1[0] - x2[0];
            k = x / (x1[1] - x2[1]);
        }
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> points = {{1,1}, {2,2}, {3,3}};
    Solution solution;
    cout << solution.maxPoints(points);
}