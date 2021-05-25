//
// Created by zhang on 2021/5/19.
//

#include "common-header.h"
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> deq;
        sort(deck.begin(), deck.end());
        deq.push_back(deck.back());
        for (int i = deck.size() - 2; i >= 0; --i) {
            deq.push_front(deq.back()); deq.pop_back();
            deq.push_front(deck[i]);
        }
        vector<int> ans(deq.begin(), deq.end());
        return ans;
    }
};



