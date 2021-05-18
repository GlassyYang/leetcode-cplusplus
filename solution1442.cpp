//
// Created by zhang on 2021/5/18.
//
#include <vector>
using namespace std;
class Solution {
public:
    // 三层大循环
    int countTriplets(vector<int>& arr, int a) {
        const vector<int>::size_type n = arr.size();
        vector<int> v(n + 1);
        int count = 0;
        for(auto i = 0; i < n; ++i) {
            v[i + 1] = v[i] ^ arr[i];
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                for (int k = i + 1; k <= j; ++k) {
                    if ((v[k] ^ v[i]) == (v[k] ^ v[j + 1])) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    // 两层循环
    int countTriplets(vector<int>& arr) {
        const vector<int>::size_type n = arr.size();
        vector<int> v(n + 1);
        int count = 0;
        for(auto i = 0; i < n; ++i) {
            v[i + 1] = v[i] ^ arr[i];
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(v[i] == v[j + 1]) count += j - i;
            }
        }
        return count;
    }
};

