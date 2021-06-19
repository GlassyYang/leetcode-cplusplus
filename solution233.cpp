//
// Created by zhang on 2021/6/10.
//

class Solution{
public:
    int countDigitOne(int n)
    {
        int countr = 0;
        for (long i = 1; i <= n; i *= 10) {
            long divider = i * 10;
            countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return countr;
    }
};