//
// Created by zhang on 2021/9/5.
//
#include "common-header.h"
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix): m(matrix.size()), n(matrix[0].size()), prefixs(matrix.size(), vector<int>(matrix[0].size(), 0)) {
        prefixs[0][0] = matrix[0][0];
        for(int i = 1; i < n; ++i) {
            prefixs[0][i] = prefixs[0][i - 1] + matrix[0][i];
        }
        for(int i = 1; i < m; ++i) {
            prefixs[i][0] = prefixs[i - 1][0] + matrix[i][0];
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                prefixs[i][j] = prefixs[i][j - 1] + (prefixs[i - 1][j] - prefixs[i - 1][j - 1]) + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int leftUp = 0, leftDown = 0, rightUp = 0;
        if(row1 != 0) {
            leftDown = prefixs[row1 - 1][col2];
        }
        if(col1 != 0) {
            rightUp = prefixs[row2][col1 - 1];
        }
        if(row1 != 0 && col1 !=0) {
            leftUp = prefixs[row1 - 1][col1 - 1];
        }
        return prefixs[row2][col2] - leftDown - rightUp + leftUp;
    }
private:
    vector<vector<int>> prefixs;
    int m;
    int n;
};

int main() {
    vector<vector<int>> matrix{{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(2,1,4,3) << endl;
    cout << numMatrix.sumRegion(1,1,2,2) << endl;
    cout << numMatrix.sumRegion(1,2,2,4) << endl;

}