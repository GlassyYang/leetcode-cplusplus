//
// Created by zhang on 2021/8/9.
//

#include "common-header.h"
namespace solution1 {
    class Solution {
    public:
        int nthSuperUglyNumber(int n, vector<int> &primes) {
            priority_queue<long, vector<long>, greater<long>> que;
            unordered_set<long> found;
            que.push(1);
            found.insert(1);
            for (int i = 1; i < n; ++i) {
                long cur = que.top();
                for (int &prime : primes) {
                    long next = prime * cur;
                    if (found.insert(next).second) {
                        que.push(next);
                    }
                }
                que.pop();
            }
            return que.top();
        }
    };
}

namespace solution2 {
    class Solution {
    public:
        int nthSuperUglyNumber(int n, vector<int> &primes) {
            long dp[n];
            const auto size = primes.size();
            dp[0] = 1;
            vector<long> nextPrimes;
            for(int &prime : primes) {
                nextPrimes.emplace_back(prime);
            }
            for(int i = 1; i < n; ++i) {
                long min = LONG_MAX;
                for(long &prime : nextPrimes) {
                    min = ::min(min, prime);
                }
                dp[i] = min;
                for(int i = 0; i < size; ++i) {
                    if (nextPrimes[i] == min) {
                        nextPrimes[i] *= primes[i];
                    }
                }
            }
            return dp[n - 1];
        }
    };
}