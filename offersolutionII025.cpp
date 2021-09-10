//
// Created by zhang on 2021/9/9.
//

#include "common-header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1Length = 0, l2Length = 0;
        ListNode *cur = l1;
        vector<ListNode*> sta;
        sta.push_back(new ListNode(0));
        while(cur != nullptr) {
            cur = cur->next;
            l1Length++;
        }
        cur = l2;
        while(cur != nullptr) {
            cur = cur->next;
            l2Length++;
        }
        ListNode *maxList, *minList;
        if(l1Length > l2Length) {
            maxList = l1;
            minList = l2;
        } else {
            maxList = l2;
            minList = l1;
        }
        for (int i = 0; i < abs(l1Length - l2Length); ++i) {
            cur = new ListNode(maxList->val);
            sta.back()->next = cur;
            sta.push_back(cur);
            maxList = maxList->next;
        }
        while(minList != nullptr) {
            cur = new ListNode(minList->val + maxList->val);
            if(cur->val >= 10) {
                cur->val -= 10;
                for(auto i = sta.rbegin(); i != sta.rend(); ++i) {
                    ListNode *temp = *i;
                    temp->val++;
                    if(temp->val >= 10) {
                        temp->val -= 10;
                    } else {
                        break;
                    }
                }
            }
            sta.back()->next = cur;
            sta.push_back(cur);
            minList = minList->next;
            maxList = maxList->next;
        }
        cur->next = sta[1];
        if(cur->val == 0) {
            return cur->next;
        }
        return cur;
    }
};

int main() {
    ListNode *l1 = new ListNode(7), *l2 = new ListNode(5);
    ListNode *cur = l1;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = l2;
    cur->next = new ListNode(6);
    cur = cur->next;
    cur->next = new ListNode(4);
    Solution solution;
    solution.addTwoNumbers(l1, l2);
}