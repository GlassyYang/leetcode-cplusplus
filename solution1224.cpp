//
// Created by zhang on 2021/6/7.
//
#include "common-header.h"
class Solution {
public:
    int maxEqualFreq(vector<int>& nums)
    {
        unordered_map<int,int> num_freq;
        unordered_map<int,int> freq_freq;
        int res = 1;
        int species = 0;                        //数字种类
        int max_freq = 0;                       //最大频率
        for (int i = 0; i < nums.size(); i ++)
        {
            int x = nums[i];
            if (num_freq[x] == 0)
                species ++;
            num_freq[x] ++;
            max_freq = std::max(max_freq, num_freq[x]);
            freq_freq[num_freq[x]] ++ ;
            freq_freq[num_freq[x] - 1] --;      //很容易忘记  +1 前的freq

            if (species == (i + 1)  || species == 1)  // 123456  111111
                res = i + 1;
            if (freq_freq[max_freq] == (species - 1) && freq_freq[1] == 1) //11 22 33 44 5
                res = i + 1;
            if (freq_freq[max_freq] == 1 && freq_freq[max_freq - 1] == (species - 1) )// 11 22 33 44 555
                res = i + 1;
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {2,2,1,1,5,3,3,5};
    return 0;
}