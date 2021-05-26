//
// Created by zhang on 2021/5/26.
//
#include "common-header.h"
class Solution {
private:
    static constexpr int MAXX = 1 << 10;
    static constexpr int INFTY = INT_MAX / 2;

public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(MAXX, INFTY);
        f[0] = 0;

        for (int i = 0; i < k; ++i) {
            unordered_map<int, int> cnt;
            int size = 0;
            for (int j = i; j < n; j += k) {
                ++cnt[nums[j]];
                ++size;
            }

            int t2min = *min_element(f.begin(), f.end());

            vector<int> g(MAXX, t2min);
            for (int mask = 0; mask < MAXX; ++mask) {
                for (auto [x, countx]: cnt) {
                    g[mask] = min(g[mask], f[mask ^ x] - countx);
                }
            }

            for_each(g.begin(), g.end(), [&](int& val) {val += size;});
            f = move(g);
        }

        return f[0];
    }
};